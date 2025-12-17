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
        RequestNode(){
            Next = nullptr;
        }
        int SetNext(RequestNode * temp);
        RequestNode * getNext();
        void display();
    private:
        request rqts[5];
        requestNode * next;
}

class mnt{
    public:
        mnt(){
            head = nullptr;
            spot = 0;
        }
        int push(int z, string t);
        int pop();
        void display();
        void menu();
    private:
        requestNode * head;
        int spot;
}