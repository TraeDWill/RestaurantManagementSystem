#include "ingredients.h"

void Ingredient::Display(){
    cout << "Ingredient Name" << IngName << endl;
    cout << "Amount in Lbs" << AmtInLbs << endl;
}

int Ingredient::Next(Ingredient *& Temp){
    if(Next){
        Temp = Next;
    }
    else{
        return 0;
    }
    return 1;
}

int Ingredient::NameComp(char * Name){
    int Num = strcmp(IngName, Name);
    if(Num < 0)
        return -1;
    else if(Num > 0)
        return 1;
    return 0;
}

void Ingredient::Connect(Ingredient *& Temp){
    Next = Temp;
}

int Ingredient::Add(int Add){
    AmtInLbs += Add;
    return AmtInLbs;
}

void Ingredient::Remove(){
    delete IngName;
}

int Category::AddIngredient(char * name, int amt){       
    int result = 0;
    int amt = 0;
    Ingredient * temp = nullptr;
    Ingredient * trail = nullptr;
    Ingredient * insert = nullptr;
    
    cout << "How many lbs(in whole numbers) rounded to the lower number is there of this item?" << endl;

    if(!head){
        head = new Ingredient(name, amt);
    }
    else{
        temp = head;
        trail = head;
        while(temp && (temp->name_comp(name) == -1)){
            trail = temp;
            result = temp->next(temp);
        }
        if(!temp){
            temp = new Ingredient(name, amt);
        }
        else if(result == 1){
            insert = new Ingredient(name, amt);
            trail->Connect(insert);
            insert->Connect(temp);
        }
        else{
            cout << "New amount is:" << temp->Add(amt) << endl;
        }
    }
    return 1;
}

int Category::RemoveIngredient(char * ing){
    Ingredient * temp = head;
    Ingredient * trail;
    Ingredient * lead;
    if(!head){
        return 0;
    }
    while(temp && temp->NameComp(ing) != 0){
        trail = temp;
        temp->Next(temp);
    }
    if(!temp){
        return 0;
    }
    temp->Next(lead);
    temp->Remove();
    delete temp;
    trail->Connect(lead);
    return 1;
}

int Category::FindIngredient(char * ing){
    Ingredient * temp = head;

    while(temp && temp->name_comp(ing) != 0){
        temp->Next(temp);
    }
    if(temp){
        temp.Display();
        return 1;
    }
    return 0;
}

int Category::DispAllIng(){
    ingredient * temp = head;
    if(!temp){
        return 0;
    }
    while(temp){
        temp.display();
        temp->next(temp);
    }
    return 1;
}

Category * Category::GetNext(){
    return next;
}

int Category::Next(Category *& temp){
    next = temp;
    return 1;
}

int Category::Comp(char * cat){
    return strcmp(cat, type);
}

void Category::End(){
    Ingredient * temp = nullptr;

    delete type;

    if(head){
        while(head){
            temp = head->GetNext();
            head.Remove();
            delete head;
            head = temp;
        }    
    }
}

int TComp(char * t){
    return strcmp(t, type);
}

int Inventory::AddCategory(){
    char cat[50];
    char * cat_name = nullptr;
    Category * temp = nullptr;
    Category * curr = nullptr;

    cout << "What is the name of the category you'd like to add?" << endl;
    cin.get(cat, 50, '\n');
    cin.ignore(1234, '\n');

    cat_name = new char[strlen(cat)+1];
    strcpy(cat_name, cat);

    if(!head){
        head = new Category(cat);
    }
    else{
        while(temp->GetNext()){
            temp = temp->GetNext();
        }
        curr = new Category(cat);
        temp->Next(curr);
    }
    return 1;

}

int Inventory::RemoveCategory(){
    char cat[50];
    char * cat_name = nullptr;
    Category * temp = nullptr;
    Category * curr = nullptr;
    Category * last = nullptr;

    cout << "What is the name of the category you'd like to remove?" << endl;
    cin.get(cat, 50, '\n');
    cin.ignore(1234, '\n');

    cat_name = new char[strlen(cat)+1];
    strcpy(cat_name, cat);

    if(!head){
        return 0;
    }
    else{
        temp = head;
        while(temp && (temp.Comp(cat) != 0)){
            curr = temp;
            temp = temp->GetNext();
        }
        if(temp){
            if(!temp->GetNext()){
                temp.End();
                delete temp;
                temp = nullptr;
                curr->Next(temp);
                return 1;
            }
            else{
                last = temp->GetNext();
                curr->Next(last);
                temp.End();
                temp = nullptr;
                return 1;
            }
        }
        return 0;
        
    }
}

int Inventory::AddIngredient(){
    char temp[50];
    char curr[50];
    char * cat = nullptr;
    char * ing = nullptr;
    Category * find = head;

    cout << "What is the type of category you'd like to add the ingredient to?" << endl;
    cin.get(temp, 50, '\n');
    cin.ignore(1234, '\n');

    cat = new char(strlen(temp) + 1);
    strcpy(cat, temp);

    count << "What is the name of the ingredient?" << endl;
    cin.get(curr, 50, '\n');
    cin.ignore(1234, '\n');

    ing = new char[strlen(curr) + 1];
    strcpy(ing, curr);

    while(find && find->TComp(cat) != 0){
        find = find.GetNext();
    }

    if(!find){
        cout << "Category not found" << endl;
        return 0;
    }
    find.AddIngredient(ing);
    return 1;

}

void Inventory::Menu(){
    int choice = 0;

    cout << "Would you like to:" << endl;
    cout << "1. Add a category" << endl;
    cout << "2. Remove a Category" << endl;
    cout << "3. Display all categories" << endl;
    cout << "4. Add Ingredient" << endl;
    cout << "5. Remove Ingredient" << endl;
    cout << "6. Display all ingredients in a cerain category" << endl;
    cout << "7. Exit Menu" << endl;

    while(choice != 7){
        switch(choice){
            case 1: 
                AddCategory();
            case 2:
                RemoveCategory();
            case 3:
                DispalyAll();
            case 4:
                AddIngredient();
            case 5: 
                RemoveIngredient();
            case 6:
                DisplayAllIngredients();
            case 7:
                cout << "Exiting inventory menu" << endl;
        }
    }

    
}

