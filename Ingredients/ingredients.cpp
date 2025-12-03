#include "ingredients.h"

void Ingredient::Display(){
    cout << "Ingredient Name" << ing_name << endl;
    cout << "Amount in Lbs" << amt_in_lbs << endl;
}

int Ingredient::Next(Ingredient *& temp){
    if(next){
        temp = next;
    }
    else{
        return 0;
    }
    return 1;
}

int Ingredient::NameComp(char * name){
    int num = strcmp(ing_name, name);
    if(num < 0)
        return -1;
    else if(num > 0)
        return 1;
    return 0;
}

void Ingredient::Connect(Ingredient *& temp){
    next = temp;
}

int Ingredient::Add(int add){
    amt_in_lbs += add;
    return amt_in_lbs;
}

void Ingredient::Remove(){
    delete ing_name;
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

int Inventory::add_category(){
    char cat[50];
    char * cat_name = nullptr;
    category * temp = nullptr;
    category * curr = nullptr;

    cout << "What is the name of the category you'd like to add?" << endl;
    cin.get(cat, 50, '\n');
    cin.ignore(1234, '\n');

    cat_name = new char[strlen(cat)+1];
    strcpy(cat_name, cat);

    if(!head){
        head = new category(cat);
    }
    else{
        while(temp->GetNext()){
            temp = temp->GetNext();
        }
        curr = new category(cat);
        temp->next(curr);
    }
    return 1;

}

int inventory::remove_category(){
    char cat[50];
    char * cat_name = nullptr;
    category * temp = nullptr;
    category * curr = nullptr;
    category * last = nullptr;

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
        while(temp && (temp.comp(cat) != 0)){
            curr = temp;
            temp = temp->GetNext();
        }
        if(temp){
            if(!temp->GetNext()){
                temp.end();
                delete temp;
                temp = nullptr;
                curr->next(temp);
                return 1;
            }
            else{
                last = temp->GetNext();
                curr->next(last);
                temp.end();
                temp = nullptr;
                return 1;
            }
        }
        return 0;
        
    }
}

int add_ingredient(){

}

int remove_ingredient(){

}

void display_all_ingredients(){
    
}

int inventory::add_ingredient(){
    char temp[50];
    char curr[50];
    char * cat = nullptr;
    char * ing = nullptr;
    category * find = head;

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

    while(find && find->tcmp(cat) != 0){
        find = find.GetNext();
    }

    if(!find){
        cout << "Category not found" << endl;
        return 0;
    }
    find.add_ingredient(ing);
    return 1;

}

void inventory::menu(){
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
                add_category();
            case 2:
                remove_category();
            case 3:
                dispaly_all();
            case 4:
                add_ingredient();
            case 5: 
                remove_ingredient();
            case 6:
                display_all_ingredients();
            case 7:
                cout << "Exiting inventory menu" << endl;
        }
    }

    
}

