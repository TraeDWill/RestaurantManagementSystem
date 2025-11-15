#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Request{
    public: 
        Request(){
            zone = 0;
            type = "";
        }
        int add_request(int z, string t);
        void display();
    private:
        int zone;
        string type;
}

class RequestNode{
    public:
        RequestNode(){
            next = nullptr;
        }
        int SetNext(RequestNode * temp);
        RequestNode * GetNext();
        void display();
    private:
        Request rqts[5];
        RequestNode * next;
}

class Mnt{
    public:
        Mnt(){
            head = nullptr;
            spot = 0;
        }
        int push(int z, string t);
        int pop();
        void display();
    private:
        RequestNode * head;
        int spot;
}