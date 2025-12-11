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

/**
 * @class IngNode
 * @brief An LLL node for a individual ingredient
 *
 * This node wraps the ingredient class for LLL
 * 
 * Usage example:
 * @code
 * ing->connect(temp); //Sets ing's next to temp
 * @endcode
 */
class IngNode{

    public:
        /**
        * @brief Constructs an Ingredient Node for LLL
        *
        * @param IName Ingredient name for ingredient object constructor
        * @param IAmount Ingredient amount in lbs for ingredient object constructor
        */
        IngNode(char * IName, int IAmount): Ingredient(IName, IAmount){
            next = nullptr;
        }
        /**
        * @brief Sets Temp to Next, If next exists
        *
        * Getter for the next member
        *
        * @return Successful int
        */
        int Next(IngNode *& Temp);

        /**
        * @brief Connects current node to temp
        *
        * Setter for the next data member
        *
        * @return void
        */
        void Connect(IngNode *& Temp);

    private:
        Ingredient Ing;
        IngNode * Next;
}

/**
 * @class Category
 * @brief An individual Category
 *
 * This manages the information of a category along with a full LLL of ingredients 
 * that belong to that category
 *
 * Usage example:
 * @code
 * Ingredient I(name, amount);
 * cout << I.Display();
 * @endcode
 */
class Category{
    public:
        /**
        * @brief Constructs a category object with the type name in parameter
        *
        * @param TName Ingredient name for ingredient object constructor
        */
        Category(char * TName){
            type = new char[strlen(TName)+1];
            strcpy(Type, TName);
            IngAmount = 0;
            Head = nullptr;
        }

        /**
        * @brief Compares type names
        *
        * Uses strcmp to compare the argument to the member value
        *
        * @return result of the strcmp
        */
        int TComp(char * T);

    private:
        char * Type;
        int IngAmount;
};

/**
 * @class CatNode
 * @brief Node that wraps an individual category
 *
 * This node not only manages a category node, it manages the entire LLL for Ingredients
 *
 * Usage example:
 * @code
 * Ingredient I(name, amount);
 * cout << I.Display();
 * @endcode
 */
class CatNode{
    public:
        CatNode(char * Name):Category(Name){
            Next = nullptr;
            Head = nullptr;
        }
        /**
        * @brief Adds to ingredient list
        *
        * Inserts an LLL insert node into the ingredient list
        *
        * @return 0 on failure and 1 on success
        */
        int AddIngredient(char * Name);

        /**
        * @brief Removes an ingredient from the list
        *
        * using the Ing name as the search argument, the proper ingredient is removed from the list.
        *
        * @return 0 on failure and 1 on success
        */
        int RemoveIngredient(char * Ing);

        /**
        * @brief Finds and displays requested ingredient
        *
        * Using Ing as the search argument, the ingredient info is displayed 
        *
        * @return 0 on failure and 1 on success
        */
        int FindIngredient(char * Ing);

        /**
        * @brief Shows full list of ingredients
        *
        * Traverses the LLL of ingredients and displays each individually
        *
        * @return 0 on failure and 1 on success
        */
        int DispAllIng();

        /**
        * @brief Sets Temp to Next, If next exists
        *
        * Getter for the next member
        *
        * @return Successful int
        */
        int Next(Category *& Temp);

        /**
        * @brief Gets the Next from the current node
        *
        * Getter for the next member
        *
        * @return Next pointer
        */        
        Category * GetNext();

        /**
        * @brief Prepares Node for deletion
        *
        * Clears out ing LLL and prepares for deletion
        *
        * @return Void
        */
        void End();
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