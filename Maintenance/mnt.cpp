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