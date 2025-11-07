#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 101;

class Contact{
    public:
        Contact(string c_name, long c_phone){
            name = c_name;
            phone = c_phone;
        }
        int comp_name(string c_name);
        void display();

    private:
        string name;
        long phone;

};

class ContactNode{
    public:
        ContactNode(string c_name, long c_phone): local(c_name, c_phone)
        {
            next = nullptr;
        }
        void display();
        ContactNode * MoveNext();
        int comp_name(string c_name);
        void set_next(ContactNode * temp);
    private:
        Contact local;
        ContactNode * next;
};

class ContactList{
    public:
        int add_contact(string c_name, long c_phone);
        int remove_contact(string c_name);
        void display_contact(string c_name);
        int hash_function(string c_name);
    private:
        ContactNode; * list[TABLE_SIZE];
};