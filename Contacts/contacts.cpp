#include "contacts.h"

    int Contact::CompName(string CName){
        if(Name == CName)
            return 1;
        return 0;
    }

    void Contact::Display(){
        cout << "Contact Name:" << Name << endl;
        cout << "Contact Number:" << Phone << endl;
    }

    ContactNode * ContactNode::MoveNext(){
        return Next;
    }

    void ContactNode::SetNext(ContactNode * Temp){
        Next = Temp;
    }

    void ContactNode::Display(){
        List.Display();
    }

    int ContactNode::CompName(string CName){
        return List.CompName(CName);
    }

    int ContactList::AddContact(string CName, long CPhone){
        ContactNode * Temp = nullptr;
        ContactNode * Curr = nullptr;
        int Key = HashFunction(CName);
        
        List[Key] = new ContactNode;
        Temp = List[Key];
        
        if(!Temp){
            Temp = new ContactNode(CName, CPhone);
        }
        else{
            while(Temp->MoveNext()){
                Temp = Temp->MoveNext();
            }
            Curr = Temp->MoveNext();
            Curr = new ContactNode(CName, CPhone);
        }
        return 1;

    }
    int ContactList::RemoveContact(string CName){
        ContactNode * Temp = nullptr;
        ContactNode * Curr = nullptr;
        ContactNode * Add = nullptr;
        int Key = HashFunction(CName);
        
        Temp = List[Key];

        while(Temp && Temp->CompName(CName) == 0){
            Curr = Temp;
            Temp = Temp->MoveNext();
        }

        if(Temp){
            if(!Temp->MoveNext()){
                delete Temp;
                Temp = nullptr;
            }
            else{
                Add = Temp->MoveNext();
                Curr->SetNext(Add);
                delete Temp;
                Temp = nullptr;

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