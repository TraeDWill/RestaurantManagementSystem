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