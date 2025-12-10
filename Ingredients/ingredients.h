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
        * @brief Creates an ingredient with said characteristics
        *
        * @param Name  The name of the ingredient.
        * @param Amount of the ingredient in lbs.
        */
        Ingredient(char * Name, int Amount){
            IngName = new char[strlen(Name) + 1];
            strcpy(IngName, Name);
            AmtInLbs = Amount;
        }

        ~Ingredient(){
            delete IngName;
        }
        
        /**
        * @brief Displays information on ingredient
        *
        * Uses IOstream to display the values
        *
        * @return void
        */
        void Display();

        /**
        * @brief Name Comparison
        *
        * Yses strcmp to see if the name value matches the parameter
        *
        * @return int comparison of names
        */
        int NameCmp(char * Name);

        /**
        * @brief Adds more lbs to weight
        *
        * Adds the input parameter to the member value of AmtInLbs
        *
        * @return Success int
        */
        int Add(int add);

        /**
        * @brief Deletes memory used for name
        *
        * directly deletes the allocated memory so that the entire node around it can be deleted. 
        *
        * @return void
        */
        void Remove();
        
    private:
        char * IngName;
        int AmtInLbs;
}

class IngNode{
    /**
    * @brief Constructs an Ingredient Node for LLL
    *
    * @param Ing Ingredient class object
    * @param Next Next pointer for LLL
    */
    public:
        IngNode(char * IName, int IAmount): Ingredient(IName, IAmount){
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