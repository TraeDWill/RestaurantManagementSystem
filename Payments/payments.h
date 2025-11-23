#include <iostream>
#include <string>
#include <vector>

class Payment{
    public:
        Payment(float a, string i){
            amt = a;
            item = i;
        }
        int Update();
    private:
        float amt;
        string item;
}

class P_Node{
    public:
        P_Node(float a, string i) : Payment(a, i){
            left = nullptr;
            right = nullptr;
        }
        P_Node * GetRight();
        P_Node * GetLeft();
        int SetLeft();
        int SetRight();
    private:
        P_Node * left;
        p_Node * right;
        Payment pay;
}

class Economy{
    public:
        Economy(){
            root = nullptr;
        }
        int insert();
        int remove();
        void display_all();

    private:
        P_Node * root;
}