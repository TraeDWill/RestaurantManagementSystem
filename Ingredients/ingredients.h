#include <iostream>
#include <string>
#include <vector>
#include <date/date.h>

using namespace std;
using namespace date;

class Ingredient{
    public:
        Ingredient(char * Name, int Amount){
            IngName = new char[strlen(Name) + 1];
            strcpy(IngName, Name);
            AmtInLbs = Amount;
            Next = nullptr;
        }
        int Display();
        int Next(Ingredient *& Temp);
        int NameCmp(char * Name);
        void Connect(Ingredient *& Temp);
        int Add(int add);
        void Remove();
        
    private:
        char * IngName;
        int AmtInLbs;
        Ingredient * Next;
}

class Category{
    public:
        Category(char * TName){
            type = new char[strlen(TName)+1];
            strcpy(Type, TName);
            IngAmount = 0;
            Head = nullptr;
        }
        int AddIngredient(char * Name);
        int RemoveIngredient(char * Ing);
        int FindIngredient(char * Ing);
        int DispAllIng();
        int Next(Category *& Temp);
        Category * GetNext();
        void End();
        int TComp(char * T);

    private:
        char * Type;
        int IngAmount;
        Category * Next;
        Ingredient * Head;
};

class Inventory{
    public:
        Inventory(){
            Head = nullptr;
        }
        int AddCategory();
        int RemoveCategory();
        void DisplayAll();
        int AddIngredient();
        int RemoveIngredient();
        void DisplayAllIngredients();
        void Menu();

    private: 
        Category * Head;
}