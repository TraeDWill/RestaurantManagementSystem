#include <iostream>
#include <string>
#include <vector>
#include <date/date.h>

using namespace std;
using namespace date;

class Ingredient{
    public:
        Ingredient(char * name, int amount){
            ing_name = new char[strlen(name) + 1];
            strcpy(ing_name, name);
            amt_in_lbs = amount;
            next = nullptr;
        }
        int Display();
        int Next(ingredient *& temp);
        int NameCmp(char * name);
        void Connect(ingredient *& temp);
        int Add(int add);
        void Remove();
        
    private:
        char * ing_name;
        int amt_in_lbs;
        ingredient * next;
}

class Category{
    public:
        Category(char * t_name){
            type = new char[strlen(t_name)+1];
            strcpy(type, t_name);
            ing_amount = 0;
            head = nullptr;
        }
        int AddIngredient(char * name);
        int RemoveIngredient(char * ing);
        int FindIngredient(char * ing);
        int DispAllIng();
        int Next(category *& temp);
        category * GetNext();
        void End();
        int TComp(char * t);

    private:
        char * type;
        int ing_amount;
        category * next;
        ingredient * head;
};

class Inventory{
    public:
        Inventory(){
            head = nullptr;
        }
        int AddCategory();
        int RemoveCategory();
        void DisplayAll();
        int AddIngredient();
        int RemoveIngredient();
        void DisplayAllIngredients();
        void Menu();

    private: 
        category * head;
}