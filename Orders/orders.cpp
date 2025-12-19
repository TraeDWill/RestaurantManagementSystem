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
    OrderNode * temp = new OrderNode(item, amt);
    OrderNode * curr = nullptr;

    if(!Tail){
        Tail = temp;
        Tail->SetNext(Tail);
    }
    else{
        curr = Tail.GetNext();
        Tail->SetNext(temp);
        Temp->SetNext(curr);
    }

    return 1;
}

int AllOrders::Dequeue(){
    OrderNode * temp = nullptr;
    OrderNode * curr = nullptr; 

    if(!Tail){
        return nullptr;
    }
    if(Tail->GetNext() == this->Tail){
        delete Tail;
        Tail = nullptr;
    }
    
    temp = Tail->GetNext();
    curr = temp;
    
    while(temp->GetNext() != Tail){
        temp = temp->GetNext();
    }

    temp->SetNext(curr);
    Tail.Display();
    delete Tail;
    Tail = temp;

    return 1;
    
}

void AllOrders::DisplayAll(){
    OrderNode * temp = Tail->GetNext();
    OrderNode * curr = temp;
    if(!Tail){
        cout << "No Orders Currently" << endl;
    }
    else{
        while(temp->GetNext() != curr){
            temp->Display();
            temp = temp->GetNext();
        }
    }

}

void AllOrders::menu(){
    int choice = 0;
    string item = "";
    float amt = 0;

    while(choice != 4){
        cout << "Here are your choices:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Remove Order" << endl;
        cout << "3. Display All Orders" << endl;
        cout << "4. Exit to menu" << endl;

        cin >> choice;
        cin.ignore(1234, '\n');

        switch(choice){
            case 1:
                cout << "What is the name of the item?" << endl;
                cin.get(item, 100, '\n');
                cin.ignore(1234, '\n');

                cout << "How much does it cost" << endl;
                cin >> amt; 
                cin.ignore(1234, '\n');

                enqueue(item, amt);
            
            case 2:
                Dequeue();

            case 3:
                DisplayAll();
            
            case 4: 
                cout << "Exiting Menu" << endl;
            
            default: 
                cout << "Wrong Choice" << endl;
        }
    }
}