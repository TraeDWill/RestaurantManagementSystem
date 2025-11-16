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

void ingredient::connect(ingredient *& temp){
    next = temp;
}

int ingredient::add(int add){
    amt_in_lbs += add;
    return amt_in_lbs;
}

void ingredient::remove(){
    delete ing_name;
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
        else if(result == 1){
            insert = new ingredient(name, amt);
            trail->connect(insert);
            insert->connect(temp);
        }
        else{
            cout << "New amount is:" << temp->add(amt) << endl;
        }
    }
    return 1;
}

int category::remove_ingredient(char * ing){
    ingredient * temp = head;
    ingredient * trail;
    ingredient * lead;
    if(!head){
        return 0;
    }
    while(temp && temp->name_comp(ing) != 0){
        trail = temp;
        temp->next(temp);
    }
    if(!temp){
        return 0;
    }
    temp->next(lead);
    temp->remove();
    delete temp;
    trail->connect(lead);
    return 1;
}

int category::find_ingredient(char * ing){
    ingredient * temp = head;

    while(temp && temp->name_comp(ing) != 0){
        temp->next(temp);
    }
    if(temp){
        temp.display();
        return 1;
    }
    return 0;
}

int category::disp_all_ing(){
    ingredient * temp = head;
    if(!temp){
        return 0;
    }
    while(temp){
        temp.display();
        temp->next(temp);
    }
    return 1;
}

category * category::GetNext(){
    return next;
}

int category::next(category *& temp){
    next = temp;
    return 1;
}

int inventory::add_category(){
    char cat[50];
    char * cat_name = nullptr;
    category * temp = nullptr;
    category * curr = nullptr;

    cout << "What is the name of the category you'd like to add?" << endl;
    cin.get(cat, 50, '\n');

    cat_name = new char[strlen(cat)+1];
    strcpy(cat_name, cat);

    if(!head){
        head = new category(cat);
    }
    else{
        while(temp->GetNext()){
            temp = temp->GetNext();
        }
        curr = new category(cat);
        temp->next(curr);
    }
    return 1;

}

