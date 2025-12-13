#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 101;

/**
 * @class Contact
 * @brief Basic contact object
 *
 * This is a basic contact card with name and phone number
 *
 * Usage example:
 * @code
 * Contact wii("Bob", 5555555555);
 * wii.Display();
 * @endcode
 */
class Contact{
    public:
       /**
        * @brief Constructs a node for category LLL 
        *
        * @param CName Name of category being implemented
        * @param CPhone Phone Number
        */
        Contact(string CName, long CPhone){
            Name = CName;
            Phone = CPhone;
        }
        ~Contact(){}

        /**
        * @brief Compares names
        *
        * Compares names from arguments to names
        *
        * @return 1 is same 0 if not
        */
        int CompName(string CName);

        /**
        * @brief Displays information on ingredient
        *
        * Uses IOstream to display the values
        *
        * @return void
        */
        void Display();

    private:
        string Name;
        long Phone;

};

/**
 * @class ContactNode
 * @brief Node wrapped around Contact
 *
 * Node for Contact
 *
 * Usage example:
 * @code
 * ContactNode Temp(Name, Phone);
 * Temp.Display(); 
 * @endcode
 */
class ContactNode{
    public:
        /**
        * @brief Constructs a node for category LLL 
        *
        * @param CName Name of category being implemented
        * @param CPhone Phone Number
        */
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

        /**
        * @brief Displays information on ingredient
        *
        * Use the ingredient display method
        *
        * @return void
        */
        void Display();

        /**
        * @brief Returns Next
        *
        * Next getter
        *
        * @return ContactNode pointer
        */
        ContactNode * MoveNext();

        /**
        * @brief Compares names
        *
        * Compares names using contact compname
        *
        * @return 1 for true 0 for false
        */
        int CompName(string CName);

        /**
        * @brief Sets next
        *
        * next setter
        *
        * @return void
        */
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