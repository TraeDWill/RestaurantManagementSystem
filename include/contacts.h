#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 101;

/**
 * @class contact
 * @brief Basic contact object
 *
 * This is a basic contact card with name and phone number
 *
 * Usage example:
 * @code
 * contact wii("Bob", 5555555555);
 * wii.display();
 * @endcode
 */
class contact{
    public:
        /**
        * @brief Default Constructor
        */
        contact(){
            name = "";
            cPhone = 0;
        }
        /**
        * @brief Constructs a node for category LLL 
        *
        * @param cName Name of category being implemented
        * @param cPhone Phone Number
        */
        Contact(string cName, long cPhone){
            name = cName;
            phone = cPhone;
        }
        ~Contact(){}

        /**
        * @brief Compares names
        *
        * Compares names from arguments to names
        *
        * @return 1 is same 0 if not
        */
        bool compName(string cName);

        /**
        * @brief Displays information on ingredient
        *
        * Uses IOstream to display the values
        *
        * @return void
        */
        void display();

    private:
        string name;
        long phone;

};

/**
 * @class contactNode
 * @brief Node wrapped around Contact
 *
 * Node for Contact
 *
 * Usage example:
 * @code
 * contactNode temp(name, phone);
 * temp.display(); 
 * @endcode
 */
class contactNode{
    public:
        /**
        * @brief Constructs a node for category LLL 
        *
        * @param cName Name of category being implemented
        * @param cPhone Phone Number
        */
        contactNode(string cName, long cPhone): local(cName, cPhone)
        {
            next = nullptr;
        }
        ~contactNode(){

        }

        /**
        * @brief Displays information on ingredient
        *
        * Use the ingredient display method
        *
        * @return void
        */
        void display();

        /**
        * @brief Returns Next
        *
        * Next getter
        *
        * @return ContactNode pointer
        */
        ContactNode * moveNext();

        /**
        * @brief Compares names
        *
        * Compares names using contact compname
        *
        * @return 1 for true 0 for false
        */
        bool compName(string cName);

        /**
        * @brief Sets next
        *
        * next setter
        *
        * @return void
        */
        void setNext(contactNode * temp);
    private:
        contact local;
        unique_ptr<contactNode> next;
};

/**
 * @class contactList
 * @brief System for contacts
 *
 * Hash table class
 *
 * Usage example:
 * @code
 * contactList temp;
 * temp.DisplayContact(); 
 * @endcode
 */
class ContactList{
    public:
        /**
        * @brief Constructs a Hash table for contacts
        */
        contactList(){
            for(int i = 0; i < TABLE_SIZE; ++i){
                List[i] = nullptr;
            }
        }
        ~contactList(){}

        /**
        * @brief Menu
        *
        * Access all methods from here.
        *
        * @return void
        */        
        void menu();

        /**
        * @brief Adds Contact
        *
        * Inserts contact into hash table
        *
        * @return 1 for success
        */            
        int addContact(string cName, long cPhone);

        /**
        * @brief Removes contact
        *
        * Finds the contact to remove and removes it from the LLL on the hash
        *
        * @return 1 for success and 0 for failure
        */    
        int removeContact(string cName);

        /**
        * @brief Displays contact
        *
        * Displays the information for a contact by a certain string name
        *
        * @return void
        */    
        void displayContact(string cName);

        /**
        * @brief Hash Function
        *
        * Turns name into a number for which will then be the place on the 
        * hash table that it is found.
        *
        * @return hash int
        */    
        int hashFunction(string cName);
    private:
        unique_ptr<contactNode> List[TABLE_SIZE];
};