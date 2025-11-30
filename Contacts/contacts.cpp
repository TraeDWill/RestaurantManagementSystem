#include "contacts.h"

    int Contact::CompName(string c_name){
        if(name == c_name)
            return 1;
        return 0;
    }

    void Contact::Display(){
        cout << "Contact Name:" << name << endl;
        cout << "Contact Number:" << phone << endl;
    }

    ContactNode * ContactNode::MoveNext(){
        return next;
    }

    void ContactNode::SetNext(ContactNode * temp){
        next = temp;
    }

    void ContactNode::Display(){
        list.Display();
    }

    int ContactNode::CompName(string c_name){
        return list.CompName(c_name);
    }

    int ContactList::AddContact(string c_name, long c_phone){
        ContactNode * temp = nullptr;
        ContactNode * curr = nullptr;
        int key = HashFunction(c_name);
        
        list[key] = new ContactNode;
        temp = list[key];
        
        if(!temp){
            temp = new ContactNode(c_name, c_phone);
        }
        else{
            while(temp->MoveNext()){
                temp = temp->MoveNext();
            }
            curr = temp->MoveNext();
            curr = new ContactNode(c_name, c_phone);
        }
        return 1;

    }
    int ContactList::RemoveContact(string c_name){
        ContactNode * temp = nullptr;
        ContactNode * curr = nullptr;
        ContactNode * add = nullptr;
        int key = HashFunction(c_name);
        
        temp = list[key];

        while(temp && temp->CompName(c_name) == 0){
            curr = temp;
            temp = temp->MoveNext();
        }

        if(temp){
            if(!temp->MoveNext()){
                delete temp;
                temp = nullptr;
            }
            else{
                add = temp->MoveNext();
                curr->SetNext(add);
                delete temp;
                temp = nullptr;

            }
            return 1;
        }
        return 0;
    }
    void ContactList::DisplayContact(string c_name){
        int key = HashFunction(c_name);
        ContactNode * temp = nullptr;

        temp = list[key];

        while(temp && temp->CompName(c_name) != 1){
            temp = temp->MoveNext();
        }
        if(temp){
            temp.Display();
        }
        else{
            cout << "No such contact." << endl;
        }

    }
    int ContactList::HashFunction(string c_name){
            unsigned long hash = 0;
            for (char c : key)
                hash = (hash * 31 + c) % TABLESIZE;
            return hash;

    }

    void ContactList::Menu(){
        string c_name;
        long c_phone;
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
                    cin.get(c_name, 1234, '\n');
                    cin.ignore(1234, '\n');
                    cout << "What is the phone number?" << endl;
                    cin >> c_phone;
                    cin.ignore(1234, '\n');

                    AddContact(c_name, c_phone);
                case 2:
                    cout << "Which contact would you like to remove?" << endl;
                    cin.get(c_name, 50, '\n');
                    cin.ignore(1234, '\n');

                    RemoveContact(c_name);
                case 3:
                    cout << "Which contact would you like to display?" << endl;
                    cin.get(c_name, 50, '\n');
                    cin.ignore(1234, '\n');

                    DisplayContact(c_name);
                case 4:
                    cout << "Exiting Menu" << endl;
                default:
                    cout << "Incorrect Choice" << endl;
            }
        }
    }