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
        * @brief Creates a Payment object
        * 
        * @param i the item type
        * @param a The price of the item
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

/**
 * @class P_Node
 * @brief Individual payment node for bst
 * 
 * Usage example:
 * @code
 * P_Node pay(a, i);
 * num = pay.GetAmt();
 * @endcode
 */
class P_Node{

    public:
        /**
        * @brief Creates a Payment node
        * 
        * @param i item type
        * @param a The amount of money
        *
        */
        P_Node(float a, string i) : Payment(a, i){
            left = nullptr;
            right = nullptr;
        }

        /**
        * @brief Gets right pointer
        *
        * getter
        *
        * @return P_Node pointer
        */  
        P_Node * GetRight();

        /**
        * @brief Gets left pointer
        *
        * getter
        *
        * @return P_Node pointer
        */  
        P_Node * GetLeft();

        /**
        * @brief Sets left pointer
        *
        * setter
        *
        * @return void
        */  
        void SetLeft(P_Node * temp);

        
        /**
        * @brief Sets right pointer
        *
        * setter
        *
        * @return void
        */  
        void SetRight(P_Node * temp);

        
        /**
        * @brief Compares amount of money
        *
        * @return int
        */  
        int Compare(float a);

        
        /**
        * @brief Matches type
        *
        * @return int
        */  
        int Match(string i);

        
        /**
        * @brief Price setter
        *
        * @return void
        */  
        void Price(float a);

        
        /**
        * @brief Getter for amount
        *
        * @return float
        */  
        float GetAmt();

        
        /**
        * @brief Calls payment display
        *
        * @return P_Node pointer
        */  
        void Display();

    private:
        P_Node * Left;
        p_Node * Right;
        Payment Pay;
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