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
    next = Temp;
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
int contactList::removeContact(string CName){
    ContactNode * Temp = nullptr;
    ContactNode * Curr = nullptr;
    ContactNode * Add = nullptr;
    int Key = HashFunction(CName);
    
    Temp = List[Key].get();

    while(Temp->Next.get() && Temp->Next->CompName(CName) == 0){
        Curr = Temp;
        Temp = Temp->MoveNext();
    }

    if(Temp->Next.get()){
        if(!Temp->MoveNext()){
            Temp->Next = move(nullptr);
        }
        else{
            Add = Temp->Next.get();
            Curr->Next = move(temp->Next);
        }
        return 1;
    }
    return 0;
}
void ContactList::DisplayContact(string CName){
    int Key = HashFunction(CName);
    ContactNode * Temp = nullptr;

    Temp = List[Key];

    while(Temp && Temp->CompName(CName) != 1){
        Temp = Temp->MoveNext();
    }
    if(Temp){
        Temp.Display();
    }
    else{
        cout << "No such contact." << endl;
    }

}
int ContactList::HashFunction(string CName){
        unsigned long Hash = 0;
        for (char c : Key)
            Hash = (Hash * 31 + c) % TABLESIZE;
        return Hash;

}

void ContactList::Menu(){
    string CName;
    long CPhone;
    int Choice;
    
    cout << "Would you like to:" << endl;
    cout << "1. Add contact" << endl;
    cout << "2. Remove a contact" << endl;
    cout << "3. Display a contact" << endl;
    cout << "4. End Menu" << endl;

    while(Choice != 4){
        switch(Choice){
            case 1:
                cout << "Which contact would you like to add?" << endl;
                cin.get(CName, 1234, '\n');
                cin.ignore(1234, '\n');
                cout << "What is the phone number?" << endl;
                cin >> CPhone;
                cin.ignore(1234, '\n');

                AddContact(CName, CPhone);
            case 2:
                cout << "Which contact would you like to remove?" << endl;
                cin.get(CName, 50, '\n');
                cin.ignore(1234, '\n');

                RemoveContact(CName);
            case 3:
                cout << "Which contact would you like to display?" << endl;
                cin.get(CName, 50, '\n');
                cin.ignore(1234, '\n');

                DisplayContact(CName);
            case 4:
                cout << "Exiting Menu" << endl;
            default:
                cout << "Incorrect Choice" << endl;
        }
    }
}