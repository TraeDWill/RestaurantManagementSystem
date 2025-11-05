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
    private:
        string name;
        long phone;

}

class ContactNode{
    public:
        ContactNode(){
            next = nullptr;
        }
        int insert(string c_name, long c_phone);
        int remove(string c_name);
        int display(string c_name);
    private:
        Contact local;
        ContactNode * next;
}

class ContactList{
    public:
        int add_contact(string c_name, long c_phone);
        int remove_contact(string c_name);
        int display_contact(string c_name);
        int hash_function(string c_name);
    private:
        ContactNode; * list[TABLE_SIZE];

}