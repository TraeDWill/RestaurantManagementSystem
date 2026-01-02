#include "../include/contacts.h"


bool contact::compName(string cName){
    string ctemp = cName.lower();
    temp = name.lower();
    return temp == ctemp;
}

void contact::display(){
    cout << "Contact Name:" << name << endl;
    cout << "Contact Number:" << phone << endl;
}

contactNode * contactNode::moveNext(){
    return next.get();
}

void contactNode::setNext(contactNode * temp){
    next = temp;
}

void contactNode::display(){
    local.display();
}

int contactNode::compName(string cName){
    return local.compName(cName);
}

int contactList::addContact(string cName, long cPhone){
    contactNode * temp = nullptr;
    contactNode * curr = nullptr;
    int key = hashFunction(cName);
    
    list[key] = new contactNode;
    temp = list[key].get();
    
    if(!temp){
        temp = new contactNode(cName, cPhone);
    }
    else{
        while(temp->moveNext()){
            temp = temp->moveNext();
        }
        curr = temp->moveNext();
        curr = new contactNode(cName, cPhone);
    }
    return 1;

}
bool contactList::removeContact(string cName){
    contactNode * temp = nullptr;
    contactNode * curr = nullptr;
    contactNode * add = nullptr;
    int key = hashFunction(CName);
    
    temp = list[key].get();

    while(temp->next.get() && temp->next->compName(cName) == 0){
        Curr = temp;
        temp = temp->moveNext();
    }

    if(temp->next.get()){
        if(!temp->moveNext()){
            temp->next = move(nullptr);
        }
        else{
            add = temp->next.get();
            curr->next = move(temp->next);
        }
        return true;
    }
    return false;
}
void contactList::displayContact(string cName){
    int key = hashFunction(cName);
    contactNode * temp = nullptr;

    temp = list[key];

    while(temp && temp->compName(cName) != 1){
        temp = temp->moveNext();
    }
    if(temp){
        temp.display();
    }
    else{
        cout << "No such contact." << endl;
    }

}
int contactList::hashFunction(string cName){
        unsigned long hash = 0;
        for (char c : key)
            hash = (hash * 31 + c) % TABLESIZE;
        return hash;

}

void contactList::menu(){
    string cName;
    long cPhone;
    int choice;
    
    cout << "Would you like to:" << endl;
    cout << "1. Add contact" << endl;
    cout << "2. Remove a contact" << endl;
    cout << "3. Display a contact" << endl;
    cout << "4. End Menu" << endl;

    while(choice != 4){
        switch(choice){
            case 1:
                cout << "Which contact would you like to add?" << endl;
                cin.get(cName, 1234, '\n');
                cin.ignore(1234, '\n');
                cout << "What is the phone number?" << endl;
                cin >> cPhone;
                cin.ignore(1234, '\n');

                addContact(cName, cPhone);
            case 2:
                cout << "Which contact would you like to remove?" << endl;
                cin.get(cName, 50, '\n');
                cin.ignore(1234, '\n');

                removeContact(cName);
            case 3:
                cout << "Which contact would you like to display?" << endl;
                cin.get(cName, 50, '\n');
                cin.ignore(1234, '\n');

                displayContact(cName);
            case 4:
                cout << "Exiting Menu" << endl;
            default:
                cout << "Incorrect Choice" << endl;
        }
    }
}