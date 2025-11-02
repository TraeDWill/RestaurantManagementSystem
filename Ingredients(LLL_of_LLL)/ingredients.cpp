#include "ingredients.h"
    void ingredient::display(){
        cout << "Ingredient Name" << ing_name << endl;
        cout << "Amount in Lbs" << amt_in_lbs << endl;
    }

    int ingredient::next(ingredient *& temp){
        if(next){
            temp = next;
        }
        else{
            return 0;
        }
        return 1;
    }
    
    int ingredient::name_comp(char * name){
        int num = strcmp(ing_name, name);
        if(num < 0)
            return -1;
        else if(num > 0)
            return 1;
        return 0;
    }

    void ingredient::connect(node *& temp){
        next = temp;
    }

    int category::add_ingredient(){
        char * name;
        int amt = 0;       
        int result = 0;
        node * temp = nullptr;
        node * trail = nullptr;
        node * insert = nullptr;
        
        cout << "What is the name of the ingredient?" << endl;
        cin.get(name, 20, '\n');
        cout << "How many pounds of it do we have?" << endl;
        cin >> amt;

        if(!head){
            head = new ingredient(name, amt);
        }
        else{
            temp = head;
            trail = head;
            while(temp && (temp->name_comp(name) == -1)){
                trail = temp;
                result = temp->next(temp);
            }
            if(!temp){
                temp = new ingredient(name, amt);
            }
            else{
                insert = new ingredient(name, amt);
                trail->connect(insert);
                insert->connect(temp);
            }
        }
        return 1;
    }

    int category::remove_ingredient(char * ing);
    int category::find_ingredient(char * ing);
    int category::disp_all_ing();