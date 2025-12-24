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
        return Next.get();
    }

    void ContactNode::SetNext(ContactNode * Temp){
        Next = Temp;
    }

    void ContactNode::Display(){
        Local.Display();
    }

    int ContactNode::CompName(string CName){
        return Local.CompName(CName);
    }

    int ContactList::AddContact(string CName, long CPhone){
        ContactNode * Temp = nullptr;
        ContactNode * Curr = nullptr;
        int Key = HashFunction(CName);
        
        List[Key] = new ContactNode;
        Temp = List[Key].get();
        
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
        
        Temp = List[Key].get();

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