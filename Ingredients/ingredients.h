#include <iostream>
#include <string>
#include <vector>
#include <date/date.h>

using namespace std;
using namespace date;

class ingredient{
    public:
        ingredient(char * name, int amount){
            ing_name = new char[strlen(name) + 1];
            strcpy(ing_name, name);
            amt_in_lbs = amount;
            next = nullptr;
        }
        int display();
        int next(ingredient *& temp);
        int name_cmp(char * name);
        void connect(ingredient *& temp);
        int add(int add);
        void remove();
        
    private:
        char * ing_name;
        int amt_in_lbs;
        ingredient * next;
}

class category{
    public:
        category(char * t_name){
            type = new char[strlen(t_name)+1];
            strcpy(type, t_name);
            ing_amount = 0;
            head = nullptr;
        }
        int add_ingredient();
        int remove_ingredient(char * ing);
        int find_ingredient(char * ing);
        int disp_all_ing();
        int next(category *& temp);
        category * GetNext();
        void end();

    private:
        char * type;
        int ing_amount;
        category * next;
        ingredient * head;
};

class inventory{
    public:
        inventory(){
            head = nullptr;
        }
        int add_category();
        int remove_category();
        void display_all();
        int add_ingredient();
        int remove_ingredient();
        void display_all_ingredients();
        void menu();

    private: 
        category * head;
}