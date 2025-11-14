#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Request{
    public: 
        int add_request(int z, string t);
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
    private:
        RequestNode * next;
}

class Mnt{
    public:
        Mnt(){
            head = nullptr;
        }
        int push(int z, string t);
        int pop();
        void display();
    private:
        RequestNode * head;
}