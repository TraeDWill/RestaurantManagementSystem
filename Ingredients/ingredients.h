#include <iostream>
#include <string>
#include <vector>
#include <date/date.h>

using namespace std;
using namespace date;


/**
 * @class Ingredient
 * @brief An individual ingredient 
 *
 * This manages the information of said ingredient 
 * 
 * Usage example:
 * @code
 * Ingredient I(name, amount);
 * cout << I.Display();
 * @endcode
 */
class Ingredient{
    public:
        /**
        * @brief Constructs a Rectangle with the given dimensions.
        *
        * @param width  The width of the rectangle (must be >= 0).
        * @param height The height of the rectangle (must be >= 0).
        */
        Ingredient(char * Name, int Amount){
            IngName = new char[strlen(Name) + 1];
            strcpy(IngName, Name);
            AmtInLbs = Amount;
        }
        
        /**
        * @brief Returns the area of the rectangle.
        *
        * Computes width * height using integer multiplication.
        *
        * @return The computed area of the rectangle.
        */
        int Display();
        int NameCmp(char * Name);
        int Add(int add);
        void Remove();
        
    private:
        char * IngName;
        int AmtInLbs;
}

class IngNode{
    public:
        IngNode(char * IName,, int IAmount): Ingredient(IName, IAmount){
            next = nullptr;
        }
    int Next(IngNode *& Temp);
    void Connect(IngNode *& Temp);
    private:
        Ingredient Ing;
        IngNode * Next;
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
};
// Implement this
class CatNode{
    public:
        CatNode(char * Name):Category(Name){
            Next = nullptr;
            Head = nullptr;
        }

    private:
        Category Cat;
        CatNode * Next;
        IngNode * Head;
}

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