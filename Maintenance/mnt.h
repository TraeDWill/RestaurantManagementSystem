#include <iostream>
#include <vector>
#include <string>

using namespace std;

class request{
    public: 
        request(){
            zone = 0;
            type = "";
        }
        int addRequest(int z, string t);
        void display();
    private:
        int zone;
        string type;
}

class requestNode{
    public:
        requestNode(){
            next = nullptr;
        }
        int setNext(RequestNode * temp);
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