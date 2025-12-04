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
        string Name;
        long Phone;

};

class ContactNode{
    public:
        ContactNode(string c_name, long c_phone): local(c_name, c_phone)
        {
            Next = nullptr;
        }
        ~ContactNode(){
            if(Next){
                delete Next;
                Next = nullptr;
            }
        }
        void Display();
        ContactNode * MoveNext();
        int CompName(string c_name);
        void SetNext(ContactNode * temp);
    private:
        Contact Local;
        ContactNode * Next;
};

class ContactList{
    public:
        ContactList(){
            for(int i = 0; i < TABLE_SIZE; ++i){
                List[i] = nullptr;
            }
        }
        ~ContactList(){
            for(int i = 0; i < TABLE_SIZE; ++i){
                if(List[i]){
                    delete List[i];
                    List[i] = nullptr;
                }
                delete [] List;
            }
        }
        void Menu();
        int AddContact(string c_name, long c_phone);
        int RemoveContact(string c_name);
        void DisplayContact(string c_name);
        int HashFunction(string c_name);
    private:
        ContactNode * List[TABLE_SIZE];
};