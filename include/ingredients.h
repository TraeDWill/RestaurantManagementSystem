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
 * I.Display();
 * @endcode
 */
class ingredient{
    public:
        /**
        * @brief Creates an ingredient with said characteristics
        *
        * @param Name  The name of the ingredient.
        * @param Amount of the ingredient in lbs.
        */
        ingredient(char * name, int amount){
            ingName = new char[strlen(name) + 1];
            strcpy(ingName, name);
            amtInLbs = amount;
        }

        ~ingredient(){
            delete ingName;
        }
        
        /**
        * @brief Displays information on a ingredient
        *
        * Uses IOstream to display the values
        *
        * @return void
        */
        void display();

        /**
        * @brief Name Comparison
        *
        * Yses strcmp to see if the name value matches the parameter
        *
        * @return int comparison of names
        */
        int nameCmp(char * name);

        /**
        * @brief Adds more lbs to weight
        *
        * Adds the input parameter to the member value of AmtInLbs
        *
        * @return Success int
        */
        int add(int add);

        /**
        * @brief Deletes memory used for name
        *
        * directly deletes the allocated memory so that the entire node around it can be deleted. 
        *
        * @return void
        */
        void remove();
        
    private:
        char * ingName;
        int amtInLbs;
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
class ingNode{

    public:
        /**
        * @brief Constructs an Ingredient Node for LLL
        *
        * @param iName Ingredient name for ingredient object constructor
        * @param iAmount Ingredient amount in lbs for ingredient object constructor
        */
        ingNode(char * iName, int iAmount): Ingredient(iName, iAmount){
            next = nullptr;
        }
        /**
        * @brief Sets Temp to Next, If next exists
        *
        * Getter for the next member
        *
        * @return Successful int
        */
        int next(ingNode *& temp);

        /**
        * @brief Connects current node to temp
        *
        * Setter for the next data member
        *
        * @return void
        */
        void connect(ingNode *& temp);

    private:
        ingredient ing;
        unique_ptr<ingNode> next;
}

/**
 * @class category
 * @brief An individual Category
 *
 * This manages the information of a category along with a full LLL of ingredients 
 * that belong to that category
 *
 * Usage example:
 * @code
 * category I(name, amount);
 * cout << I.Display();
 * @endcode
 */
class category{
    public:
        /**
        * @brief Constructs a category object with the type name in parameter
        *
        * @param tName Ingredient name for ingredient object constructor
        */
        Category(char * tName){
            type = new char[strlen(tName)+1];
            strcpy(type, tName);
            ingAmount = 0;
            head = nullptr;
        }

        /**
        * @brief Compares type names
        *
        * Uses strcmp to compare the argument to the member value
        *
        * @return result of the strcmp
        */
        int tComp(char * t);

    private:
        char * type;
        int ingAmount;
};

/**
 * @class catNode
 * @brief Node that wraps an individual category
 *
 * This node not only manages a category node, it manages the entire LLL for Ingredients
 *
 * Usage example:
 * @code
 * catNode cat(name);
 * cout << I.Display();
 * @endcode
 */
class catNode{
    public:
        /**
        * @brief Constructs a node for category LLL 
        *
        * @param name Name of category being implemented
        */
        CatNode(char * name):Category(Name){
            next = nullptr;
            head = nullptr;
        }
        /**
        * @brief Adds to ingredient list
        *
        * Inserts an LLL insert node into the ingredient list
        *
        * @return 0 on failure and 1 on success
        */
        int addIngredient(char * name);

        /**
        * @brief Removes an ingredient from the list
        *
        * using the Ing name as the search argument, the proper ingredient is removed from the list.
        *
        * @return 0 on failure and 1 on success
        */
        int removeIngredient(char * ing);

        /**
        * @brief Finds and displays requested ingredient
        *
        * Using Ing as the search argument, the ingredient info is displayed 
        *
        * @return 0 on failure and 1 on success
        */
        int findIngredient(char * ing);

        /**
        * @brief Shows full list of ingredients
        *
        * Traverses the LLL of ingredients and displays each individually
        *
        * @return 0 on failure and 1 on success
        */
        int dispAllIng();

        /**
        * @brief Sets Temp to Next, If next exists
        *
        * Getter for the next member
        *
        * @return Successful int
        */
        int next(category *& temp);

        /**
        * @brief Gets the Next from the current node
        *
        * Getter for the next member
        *
        * @return Next pointer
        */        
        Category * getNext();

        /**
        * @brief Prepares Node for deletion
        *
        * Clears out ing LLL and prepares for deletion
        *
        * @return Void
        */
        void end();
    private:
        category cat;
        catNode * next;
        ingNode * head;
}

/**
 * @class inventory
 * @brief Whole System
 *
 * This inventory system manages category LLL and menu system
 *
 * Usage example:
 * @code
 * Inventory inv;
 * inv.AddCategory();
 * @endcode
 */
class inventory{
    public:
        /**
        * @brief Constructs an inventory
        */
        inventory(){
            head = nullptr;
        }
        /**
        * @brief Adds Category
        *
        * Inserts a Category Node into a LLL
        *
        * @return 1 on success
        */
        int addCategory();

        /**
        * @brief Removes a category
        *
        * Removes category node from the LLL
        *
        * @return 1 on success, 0 on failure
        */
        int removeCategory();

        /**
        * @brief Display all categories
        *
        * Traverses the LLL of categories and displays them
        *
        * @return void
        */
        void displayAll();

        /**
        * @brief Adds to ingredient list
        *
        * Inserts an LLL insert node into the ingredient list after finding
        * out the category it belongs to
        *
        * @return 0 on failure and 1 on success
        */
        int addIngredient();

        /**
        * @brief Removes an ingredient
        *
        * Removes an ingredient from a specific category
        *
        * @return 0 on failure and 1 on success
        */
        int removeIngredient();
        
        /**
        * @brief Display All Ingredients
        *
        * Traverses all categories to display all ingredients
        *
        * @return void
        */
        void displayAllIngredients();
        
        /**
        * @brief Menu
        *
        * Shows a menu for all actionable methods
        *
        * @return void
        */
        void menu();

    private: 
        category * head;
}