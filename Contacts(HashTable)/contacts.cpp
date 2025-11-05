#include "contacts.h"

    int Contact::comp_name(string c_name){
        if(name == c_name)
            return 1;
        return 0;
    }

    int ContactNode::insert(string c_name, long c_phone){
        
    }
    int ContactNode::remove(string c_name);
    int ContactNode::display(string c_name);
    int ContactList::add_contact(string c_name, long c_phone){
        int key = hash_function(c_name);
        list[key] = new Contact(c_name, c_phone);

    }
    int ContactList::remove_contact(string c_name){

    }
    int ContactList::display_contact(string c_name){

    }
    int ContactList::hash_function(string c_name){
            unsigned long hash = 0;
            for (char c : key)
                hash = (hash * 31 + c) % TABLESIZE;
            return hash;

    }