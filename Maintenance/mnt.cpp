#include "mnt.h"

int Request::add_request(int z, string t){
    zone = z;
    type = t;
    return 1;
}

void Request::display(){
    cout << "Zone: " << zone << endl;
    cout << "Type: " << type << endl;
}

void RequestNode::display(){
    rqts[spot].display();
}

int RequestNode::SetNext(RequestNode * temp){
    next = temp;
    return 1;
}

RequestNode * RequestNode::GetNext(){
    return next;
}

int Mnt::push(int z, string t){
    RequestNode * temp = head;
    
    while(temp->GetNext()){
        temp = temp->GetNext();
    }

    if(spot == 4){
        temp->GetNext() = new RequestNode();
        temp = temp->GetNext();
        spot == 0;
    }

    rqts[spot].add_request(z, t);
    ++spot;
    return 1;
}

int pop(){
    RequestNode * temp = head;
    while(temp->GetNext()){
        temp = temp->GetNext();
    }
    temp->dispaly();
    --spot;
    return 1;
}

void Mnt::display(){
    head->display();
}

void Mnt::menu(){
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