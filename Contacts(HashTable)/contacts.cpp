#include "contacts.h"

    int Contact::comp_name(string c_name){
        if(name == c_name)
            return 1;
        return 0;
    }

    void ContactNode::display(){
        cout << "Contact Name:" << name << endl;
        cout << "Contact Number:" << phone << endl;
    }

    ContactNode * ContactNode::MoveNext(){
        return next;
    }

    void ContactNode::display(){
        list.display();
    }

    int comp_name(string c_name){
        return list.comp_name(c_name);
    }

    int ContactList::add_contact(string c_name, long c_phone){
        ContactNode * temp = nullptr;
        ContactNode * curr = nullptr;
        int key = hash_function(c_name);
        
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
    int ContactList::remove_contact(string c_name){
        ContactNode * temp = nullptr;
        ContactNode * curr = nullptr;
        int key = hash_function(c_name);
        
        temp = list[key];

        while(temp && temp->comp_name(c_name) == 0){
            curr = temp;
            temp = temp->MoveNext();
        }

        if(temp){
            if(!temp->MoveNext()){
                delete temp;
                temp = 
            }
        }
    }
    int ContactList::display_contact(string c_name){

    }
    int ContactList::hash_function(string c_name){
            unsigned long hash = 0;
            for (char c : key)
                hash = (hash * 31 + c) % TABLESIZE;
            return hash;

    }