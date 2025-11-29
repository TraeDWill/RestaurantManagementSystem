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
        int compare(float a);
        void price(float a);
        float GetAmt();
        void display();
        
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
        void SetLeft(P_Node * temp);
        void SetRight(P_Node * tmep);
        int compare(float a);
        int match(string i);
        void price(float a);
        float GetAmt();
        void display();

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
        int insert(P_Node * temp, float a, string i)
        int remove();
        int remove(P_Node * temp, float a, string i);
        void display_all();
        void display_all(P_Node * temp);
        void menu();
        
    private:
        P_Node * root;
}