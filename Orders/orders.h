#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @class Order
 * @brief An individual order of food 
 *
 * Simply shows what the food is and how much it cost
 * 
 * Usage example:
 * @code
 * Order burger(item, amt);
 * burger.display();
 * @endcode
 */
class Order{
    public:
        /**
        * @brief Creates an Order
        * 
        * @param item The name of the food item
        * @param amt The price of the item
        *
        */
        Order(string item, float amt){
            FoodItem = item;
            Price = amt;
        }

        /**
        * @brief Displays information on a ingredient
        *
        * Uses IOstream to display the values
        *
        * @return void
        */        
        void Display();

    private:
        string FoodItem;
        float Price;
}

/**
 * @class OrderNode
 * @brief Node for an order
 *
 * Node used for the queue
 * 
 * Usage example:
 * @code
 * OrderNode burger()
 * burger.display();
 * @endcode
 */
class OrderNode{
        /**
        * @brief Creates an Order
        * 
        * @param item The name of the food item
        * @param amt The price of the item
        *
        */
    public:
        Ordernode(string item, float amt) : Order(item, amt){
            Next = nullptr;
        }

        /**
        * @brief Retrieves Next
        *
        * Next Getter
        *
        * @return OrderNode pointer
        */
        ContactNode * GetNext();

        /**
        * @brief Connects current node to another via next node
        *
        * Setter
        *
        * @return void
        */
        void SetNext(ContactNode * temp);

        /**
        * @brief Displays order info
        * 
        * Runs order display method
        *
        * @return void
        */
        void display();
    private:
        Order Stuff;
        OrderNode * Next;
}

class AllOrders{
    public:
        Allorders(){
            tail = nullptr;
        }
        int enqueue(string item, float amt);
        int dequeue(string item, float amt);
        int display_all();
        void menu();
    private:
        OrderNode * tail;
}