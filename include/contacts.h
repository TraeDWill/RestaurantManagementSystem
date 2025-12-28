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
        * @brief Default Constructor
        */
        Contact(){
            Name = "";
            CPhone = 0;
        }
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
        bool CompName(string CName);

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
        unique_ptr<ContactNode> Next;
};

/**
 * @class ContactList
 * @brief System for contacts
 *
 * Hash table class
 *
 * Usage example:
 * @code
 * ContactNode Temp(Name, Phone);
 * Temp.Display(); 
 * @endcode
 */
class ContactList{
    public:
        /**
        * @brief Constructs a Hash table for contacts
        */
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

        /**
        * @brief Menu
        *
        * Access all methods from here.
        *
        * @return void
        */        
        void Menu();

        /**
        * @brief Adds Contact
        *
        * Inserts contact into hash table
        *
        * @return 1 for success
        */            
        int AddContact(string CName, long CPhone);

        /**
        * @brief Removes contact
        *
        * Finds the contact to remove and removes it from the LLL on the hash
        *
        * @return 1 for success and 0 for failure
        */    
        int RemoveContact(string CName);

        /**
        * @brief Displays contact
        *
        * Displays the information for a contact by a certain string name
        *
        * @return void
        */    
        void DisplayContact(string CName);

        /**
        * @brief Hash Function
        *
        * Turns name into a number for which will then be the place on the 
        * hash table that it is found.
        *
        * @return hash int
        */    
        int HashFunction(string CName);
    private:
        unique_ptr<ContactNode> List[TABLE_SIZE];
};