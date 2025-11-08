#include "orders.h"
        void Order::display(){
            cout << "Item: " << FoodItem << endl;
            cout << "Price: " << Price << endl;
        }

        OrderNode * OrderNode::GetNext(){
            return next;
        }

        void OrderNode::SetNext(OrderNode * temp){
            next = temp;
        }

        void OrderNode::display(){
            stuff.display();
        }

        int AllOrders::enqueue(string item, float amt){
            OrderNode * temp = new Ordernode(item, amt);
            OrderNode * curr = nullptr;

            if(!tail){
                tail = temp;
                tail->set_next(tail);
            }
            else{
                curr = tail.GetNext();
                tail->SetNext(temp);
                temp->SetNext(curr);
            }

            return 1;
        }

        OrderNode * AllOrders::dequeue(string item, float amt){
            
        }
        int AllOrders::display_all();