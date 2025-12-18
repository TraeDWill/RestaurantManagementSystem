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

class OrderNode{
    public:
        Ordernode(string item, float amt) : Order(string item, float amt){
            next = nullptr;
        }
        ContactNode * GetNext();
        void SetNext(ContactNode * temp);
        void display();
    private:
        Order stuff;
        OrderNode * next;
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