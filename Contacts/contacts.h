#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 101;

class Contact{
    public:
        Contact(string CName, long CPhone){
            Name = CName;
            Phone = CPhone;
        }
        ~Contact(){}
        int CompName(string CName);
        void Display();

    private:
        string Name;
        long Phone;

};

class ContactNode{
    public:
        ContactNode(string CName, long CPhone): local(CName, CPhone)
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
        int CompName(string CName);
        void SetNext(ContactNode * Temp);
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
        int AddContact(string CName, long CPhone);
        int RemoveContact(string CName);
        void DisplayContact(string CName);
        int HashFunction(string CName);
    private:
        ContactNode * List[TABLE_SIZE];
};