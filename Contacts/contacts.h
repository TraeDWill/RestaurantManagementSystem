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
        ~Contact(){}
        int CompName(string c_name);
        void Display();

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
        ~ContactNode(){
            if(next){
                next = nullptr;
            }
        }
        void Display();
        ContactNode * MoveNext();
        int CompName(string c_name);
        void SetNext(ContactNode * temp);
    private:
        Contact local;
        ContactNode * next;
};

class ContactList{
    public:
        ContactList(){
            for(int i = 0; i < TABLE_SIZE; ++i){
                list[i] = nullptr;
            }
        }
        ~ContactList(){
            for(int i = 0; i < TABLE_SIZE; ++i){
                if(list[i]){
                    delete list[i];
                    list[i] = nullptr;
                }
            }
        }
        void Menu();
        int AddContact(string c_name, long c_phone);
        int RemoveContact(string c_name);
        void DisplayContact(string c_name);
        int HashFunction(string c_name);
    private:
        ContactNode * list[TABLE_SIZE];
};