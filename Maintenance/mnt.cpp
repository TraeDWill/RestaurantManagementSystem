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

int Mnt::Push(int z, string t){
    RequestNode * temp = Head;
    
    while(temp->GetNext()){
        temp = temp->GetNext();
    }

    if(Spot == 4){
        temp->GetNext() = new RequestNode();
        temp = temp->GetNext();
        spot == 0;
    }

    Rqts[Spot].AddRequest(z, t);
    ++Spot;
    return 1;
}

int Mnt::Pop(){
    RequestNode * temp = Head;
    while(temp->GetNext()){
        temp = temp->GetNext();
    }
    temp->Display();
    --Spot;
    return 1;
}

void Mnt::Display(){
    Head->Display();
}

void Mnt::Menu(){
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
                Push(z, t);
            case 2:
                Pop();
            case 3:
                Display();
            case 4:
                cout << "Exiting Maintenance Menu" << endl;
            default:
                cout << "Incorrect Choice" << endl;
                
        }
        
    }
}