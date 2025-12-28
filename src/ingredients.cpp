#include "../include/ingredients.h"

void ingredient::display(){
    cout << "Ingredient Name" << ingName << endl;
    cout << "Amount in Lbs" << amtInLbs << endl;
}

int ingNode::next(ingNode *& temp){
    if(next){
        temp = next;
    }
    else{
        return 0;
    }
    return 1;
}

int ingredient::nameComp(char * name){
    int num = strcmp(ingName, name);
    if(num < 0) 
        return -1;
    else if(num > 0)
        return 1;
    return 0;
}

void ingNode::connect(ingredient *& temp){
    next = temp;
}

int ingredient::add(int add){
    amtInLbs += add;
    return amtInLbs;
}

void ingredient::remove(){
    delete ingName;
}

int catNode::addIngredient(char * name, int amt){       
    int result = 0;
    int amt = 0;
    ingNode * temp = nullptr;
    ingNode * trail = nullptr;
    ingNode * insert = nullptr;
    
    cout << "How many lbs(in whole numbers) rounded to the lower number is there of this item?" << endl;

    if(!head){
        head = new ingNode(name, amt);
    }
    else{
        temp = head;
        trail = head;
        while(temp && (temp->nameComp(name) == -1)){
            trail = temp;
            result = temp->next(temp);
        }
        if(!temp){
            temp = new ingNode(name, amt);
        }
        else if(result == 1){
            insert = new ingName(name, amt);
            trail->connect(insert);
            insert->connect(temp);
        }
        else{
            cout << "New amount is:" << temp->add(amt) << endl;
        }
    }
    return 1;
}

int catNode::removeIngredient(char * ing){
    ingNode * temp = head;
    ingNode * trail;
    ingNode * lead;
    if(!head){
        return 0;
    }
    while(temp && temp->nameComp(ing) != 0){
        trail = temp;
        temp->next(temp);
    }
    if(!temp){
        return 0;
    }
    temp->next(lead);
    temp->remove();
    delete temp;
    trail->connect(lead);
    return 1;
}

int catNode::findIngredient(char * ing){
    ingNode * temp = head;

    while(temp && temp->nameComp(ing) != 0){
        temp->next(temp);
    }
    if(temp){
        temp.display();
        return 1;
    }
    return 0;
}

int catNode::dispAllIng(){
    ingNode * temp = head;
    if(!temp){
        return 0;
    }
    while(temp){
        temp.display();
        temp->next(temp);
    }
    return 1;
}

catNode * catNode::getNext(){
    return next;
}

int catNode::next(category *& temp){
    next = temp;
    return 1;
}

int category::comp(char * cat){
    return strcmp(cat, type);
}

void catNode::end(){
    ingName * temp = nullptr;

    delete type;

    if(head){
        while(head){
            Temp = Head->GetNext();
            Head.Remove();
            delete Head;
            Head = Temp;
        }    
    }
}

int Category::TComp(char * T){
    return strcmp(T, Type);
}

int Inventory::AddCategory(){
    char Cat[50];
    char * CatName = nullptr;
    Category * Temp = nullptr;
    Category * Curr = nullptr;

    cout << "What is the name of the category you'd like to add?" << endl;
    cin.get(Cat, 50, '\n');
    cin.ignore(1234, '\n');

    CatName = new char[strlen(Cat)+1];
    strcpy(CatName, Cat);

    if(!Head){
        Head = new Category(Cat);
    }
    else{
        while(Temp->GetNext()){
            Temp = Temp->GetNext();
        }
        Curr = new Category(Cat);
        Temp->Next(Curr);
    }
    return 1;

}

int Inventory::RemoveCategory(){
    char Cat[50];
    char * CatName = nullptr;
    Category * Temp = nullptr;
    Category * Curr = nullptr;
    Category * Last = nullptr;

    cout << "What is the name of the category you'd like to remove?" << endl;
    cin.get(Cat, 50, '\n');
    cin.ignore(1234, '\n');

    CatName = new char[strlen(Cat)+1];
    strcpy(CatName, Cat);

    if(!Head){
        return 0;
    }
    else{
        Temp = Head;
        while(Temp && (Temp.Comp(Cat) != 0)){
            Curr = Temp;
            Temp = Temp->GetNext();
        }
        if(Temp){
            if(!Temp->GetNext()){
                Temp.End();
                delete Temp;
                Temp = nullptr;
                Curr->Next(Temp);
                return 1;
            }
            else{
                Last = Temp->GetNext();
                Curr->Next(Last);
                Temp.End();
                Temp = nullptr;
                return 1;
            }
        }
        return 0;
        
    }
}

int Inventory::AddIngredient(){
    char Temp[50];
    char Curr[50];
    char * Cat = nullptr;
    char * Ing = nullptr;
    Category * Find = Head;

    cout << "What is the type of category you'd like to add the ingredient to?" << endl;
    cin.get(Temp, 50, '\n');
    cin.ignore(1234, '\n');

    Cat = new char(strlen(Temp) + 1);
    strcpy(Cat, Temp);

    count << "What is the name of the ingredient?" << endl;
    cin.get(Curr, 50, '\n');
    cin.ignore(1234, '\n');

    Ing = new char[strlen(Curr) + 1];
    strcpy(Ing, Curr);

    while(Find && Find->TComp(Cat) != 0){
        Find = Find.GetNext();
    }

    if(!Find){
        cout << "Category not found" << endl;
        return 0;
    }
    Find.AddIngredient(Ing);
    return 1;

}

// Implement RemoveIngredient and DisplayAllIngredients

int Inventory::RemoveIngredient(){
    char Temp[50];
    char Curr[50];
    char * Cat = nullptr;
    char * Ing = nullptr;
    Category * Find = Head;

    cout << "What is the type of category you'd like to remove an ingredient from?" << endl;
    cin.get(Temp, 50, '\n');
    cin.ignore(1234, '\n');

    Cat = new char(strlen(Temp) + 1);
    strcpy(Cat, Temp);

    count << "What is the name of the ingredient?" << endl;
    cin.get(Curr, 50, '\n');
    cin.ignore(1234, '\n');

    Ing = new char[strlen(Curr) + 1];
    strcpy(Ing, Curr);

    while(Find && Find->TComp(Cat) != 0){
        Find = Find.GetNext();
    }

    if(!Find){
        cout << "Category not found" << endl;
        return 0;
    }
    Find.RemoveIngredient(Ing);
    return 1;
}

void Inventory::DisplayAllIngredients(){
    Category * Top = Head;
    while(Top->GetNext()){
        Top.DisAllIng();
    }
}

void Inventory::Menu(){
    int Choice = 0;

    cout << "Would you like to:" << endl;
    cout << "1. Add a category" << endl;
    cout << "2. Remove a Category" << endl;
    cout << "3. Display all categories" << endl;
    cout << "4. Add Ingredient" << endl;
    cout << "5. Remove Ingredient" << endl;
    cout << "6. Display all ingredients in a cerain category" << endl;
    cout << "7. Exit Menu" << endl;

    while(Choice != 7){
        switch(Choice){
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

