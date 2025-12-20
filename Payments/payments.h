#include <iostream>
#include <string>
#include <vector>

/**
 * @class Payment
 * @brief Individual payment details
 *
 * Details for payments
 * 
 * Usage example:
 * @code
 * Payment pay()
 * burger.display();
 * @endcode
 */
class Payment{
        /**
        * @brief Creates an Order
        * 
        * @param Item The item type
        * @param Amt The price of the item
        *
        */
    public:
        Payment(float a, string i){
            Amt = a;
            Item = i;
        }

        /**
        * @brief Update Suite
        *
        * Menu of methods for Payment
        *
        * @return int
        */  
        int Update();

        /**
        * @brief Compares amounts
        *
        * @return 0 amt is larger, 1 amt is maller, 2 is equal
        */  
        int Compare(float a);

        /**
        * @brief Updates price
        *
        * @return void
        */  
        void Price(float a);
        
        /**
        * @brief Gets amt
        *
        * Getter
        *
        * @return Float
        */  
        float GetAmt();

        /**
        * @brief Displays info
        *
        * @return int
        */  
        void Display();
        
    private:
        float Amt;
        string Item;
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