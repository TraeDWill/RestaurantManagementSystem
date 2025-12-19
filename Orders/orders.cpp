#include "orders.h"

void Order::Display(){
    cout << "Item: " << FoodItem << endl;
    cout << "Price: " << Price << endl;
}

OrderNode * OrderNode::GetNext(){
    return Next;
}

void OrderNode::SetNext(OrderNode * temp){
    Next = Temp;
}

void OrderNode::Display(){
    Stuff.Display();
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

int AllOrders::dequeue(string item, float amt){
    OrderNode * temp = nullptr;
    Ordernode * curr = nullptr; 

    if(!tail){
        return nullptr;
    }
    if(tail->GetNext() == this->tail){
        delete tail;
        tail = nullptr;
    }
    
    temp = tail->GetNext();
    curr = temp;
    
    while(temp->GetNext() != tail){
        temp = temp->GetNext();
    }

    temp->SetNext(curr);
    tail.display();
    delete tail;
    tail = temp;

    return 1;
    
}
void AllOrders::display_all(){
    OrderNode * temp = tail->GetNext();
    OrderNode * curr = temp;
    if(!tail){
        cout << "No Orders Currently" << endl;
    }
    else{
        while(temp->GetNext() != curr){
            temp.display();
            temp = temp.GetNext();
        }
    }

}

void AllOrders::menu(){
    int choice = 0;

    while(choice != 4){
        cout << "Here are your choices:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Remove Order" << endl;
        cout << "3. Display All Orders" << endl;
        cout << "4. Exit to menu" << endl;

        cin >> choice;
        cin.ignore(1234, '\n');
    }
}