#include "mnt.h"

int Request::AddRequest(int z, string t){
    Zone = z;
    Type = t;
    return 1;
}

void Request::Display(){
    cout << "Zone: " << Zone << endl;
    cout << "Type: " << Type << endl;
}

void RequestNode::Display(){
    Rqts[Spot].Display();
}

int RequestNode::SetNext(RequestNode * temp){
    Next = temp;
    return 1;
}

RequestNode * RequestNode::GetNext(){
    return Next;
}

int mnt::push(int z, string t){
    RequestNode * temp = head;
    
    while(temp->getNext()){
        temp = temp->getNext();
    }

    if(spot == 4){
        temp->getNext() = new requestNode();
        temp = temp->getNext();
        spot == 0;
    }

    rqts[spot].addRequest(z, t);
    ++spot;
    return 1;
}

int pop(){
    RequestNode * temp = head;
    while(temp->getNext()){
        temp = temp->getNext();
    }
    temp->dispaly();
    --spot;
    return 1;
}

void mnt::display(){
    head->display();
}

void mnt::menu(){
    int choice = 0;
    int z = 0;
    string t = "";

    while(choice != 4){
        switch(choice){
            case 1: 
                cout << "What zone is it?" << endl;
                cin >> z;
                cin.ignore(1234, '\n');
                cout << "What is the issue in 100 char or less?" << endl;
                cin.get(t, 100, '\n');
                cin.ignore(1234, '\n');
                push(z, t);
            case 2:
                pop();
            case 3:
                display();
            case 4:
                cout << "Exiting Maintenance Menu" << endl;
            default:
                cout << "Incorrect Choice" << endl;
                
        }
        
    }
}