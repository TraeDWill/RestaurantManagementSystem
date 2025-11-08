#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order{
    public:
        Order(string item, float amt){
            FoodItem = item;
            Price = amt;
        }
        void display();
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
        int enqueue(string item, float amt);
        int dequeue(string item, float amt);
        int display_all();
    private:
        OrderNode * tail;
}