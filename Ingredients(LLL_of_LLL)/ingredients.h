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
        add_ingredient(char * name, int amount, date today);
    private:
        char * ing_name;
        int * amt_in_lbs;
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
        int add_category(char * type);
        int remove_category(char * type);
        int display_category(char * type);
        int type_count();
    private:
        char * type;
        int ing_amount;
        ingredient * head;
};