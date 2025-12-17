#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @class Request
 * @brief An individual request 
 *
 * This has the information of where the request is from and what type it is
 * 
 * Usage example:
 * @code
 * Request req;
 * req.display();
 * @endcode
 */
class Request{
    public: 
        /**
        * @brief Creates a request
        */
        Request(){
            Zone = 0;
            Type = "";
        }
        /**
        * @brief Adds information to a request
        *
        * Setter for request object
        *
        * @return void
        */
        int AddRequest(int z, string t);

        /**
        * @brief Displays information on a ingredient
        *
        * Uses IOstream to display the values
        *
        * @return void
        */
        void Display();
    private:
        int Zone;
        string Type;
}

/**
 * @class RequestNode
 * @brief An individual request node
 *
 * Node for stack
 * 
 * Usage example:
 * @code
 * RequestNode req;
 * req.GetNext();
 * @endcode
 */
class RequestNode{
    public:
        /**
        * @brief Creates a RequestNode object
        */
        RequestNode(){
            Next = nullptr;
        }
        /**
        * @brief Connects current node to another via next
        *
        * Setter 
        *
        * @return 1 for success
        */
        int SetNext(RequestNode * temp);

        /**
        * @brief Brings out Next
        *
        * Getter
        *
        * @return RequestNode pointer
        */
        RequestNode * GetNext();

        /**
        * @brief Displays information on request
        *
        * Uses Request display method
        *
        * @return void
        */
        void display();
    private:
        Request Rqts[5];
        RequestNode * Next;
}

/**
 * @class Mnt
 * @brief Maintenance System
 *
 * Manages stack
 * 
 * Usage example:
 * @code
 * Mnt main;
 * main.push(z, t);
 * @endcode
 */
class mnt{
    public:
        /**
        * @brief Creates a RequestNode object
        */
        Mnt(){
            Head = nullptr;
            Spot = 0;
        }

        /**
        * @brief Pushes a request
        *
        * Inserts a request into the stack
        *
        * @return 1
        */
        int Push(int z, string t);

        /**
        * @brief Removes a request off the top of the stack
        *
        * Pops a request off the top of the stack
        *
        * @return 1
        */
        int Pop();

        /**
        * @brief Displays information on current request
        *
        * Uses RequestNode display method
        *
        * @return void
        */
        void Display();

        /**
        * @brief Menu for maintenance
        *
        * Output menu to command line
        *
        * @return void
        */
        void Menu();
    private:
        RequestNode * Head;
        int Spot;
}