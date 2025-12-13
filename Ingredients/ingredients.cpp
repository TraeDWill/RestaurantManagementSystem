#include "ingredients.h"

void Ingredient::Display(){
    cout << "Ingredient Name" << IngName << endl;
    cout << "Amount in Lbs" << AmtInLbs << endl;
}

int IngNode::Next(IngNode *& Temp){
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

void IngNode::Connect(Ingredient *& Temp){
    Next = Temp;
}

int Ingredient::Add(int Add){
    AmtInLbs += Add;
    return AmtInLbs;
}

void Ingredient::Remove(){
    delete IngName;
}

int CatNode::AddIngredient(char * Name, int Amt){       
    int Result = 0;
    int Amt = 0;
    IngNode * Temp = nullptr;
    IngNode * Trail = nullptr;
    IngNode * Insert = nullptr;
    
    cout << "How many lbs(in whole numbers) rounded to the lower number is there of this item?" << endl;

    if(!Head){
        Head = new IngNode(Name, Amt);
    }
    else{
        Temp = Head;
        Trail = Head;
        while(Temp && (Temp->NameComp(Name) == -1)){
            Trail = Temp;
            Result = Temp->Next(Temp);
        }
        if(!Temp){
            Temp = new IngNode(Name, Amt);
        }
        else if(Result == 1){
            Insert = new IngName(Name, Amt);
            Trail->Connect(Insert);
            Insert->Connect(Temp);
        }
        else{
            cout << "New amount is:" << Temp->Add(Amt) << endl;
        }
    }
    return 1;
}

int CatNode::RemoveIngredient(char * ing){
    IngNode * Temp = Head;
    IngNode * Trail;
    IngNode * Lead;
    if(!Head){
        return 0;
    }
    while(Temp && Temp->NameComp(Ing) != 0){
        Trail = Temp;
        Temp->Next(Temp);
    }
    if(!Temp){
        return 0;
    }
    Temp->Next(Lead);
    Temp->Remove();
    delete Temp;
    Trail->Connect(Lead);
    return 1;
}

int CatNode::FindIngredient(char * Ing){
    IngNode * Temp = Head;

    while(Temp && Temp->NameComp(Ing) != 0){
        Temp->Next(Temp);
    }
    if(Temp){
        Temp.Display();
        return 1;
    }
    return 0;
}

int CatNode::DispAllIng(){
    IngNode * Temp = Head;
    if(!Temp){
        return 0;
    }
    while(Temp){
        Temp.Display();
        Temp->Next(Temp);
    }
    return 1;
}

CatNode * CatNode::GetNext(){
    return Next;
}

int CatNode::Next(Category *& Temp){
    Next = Temp;
    return 1;
}

int Category::Comp(char * Cat){
    return strcmp(Cat, Type);
}

void CatNode::End(){
    IngName * Temp = nullptr;

    delete Type;

    if(Head){
        while(Head){
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

