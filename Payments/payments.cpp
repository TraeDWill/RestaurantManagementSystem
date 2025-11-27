#include "payments.h" 

int Payment::Update(){
    float a = 0;
    string i = "";
    int choice = 0;

    cout << "Would you like to:" << endl;
    cout << "1. Update price" << endl;
    cout << "2. Update item name" << endl;
    cout << "3. Update both" << endl;

    switch(choice){
        case 1: 
            cout << "What's the new price?" << endl;
            cin >> a;
            cin.ignore(1234, '\n');

            amt = a;
            return 1;
        case 2:
            cout << "Whats the new name of the item?" << endl;
            cin.get(i, 50, '\n');
            cin.ignore(1234, '\n');

            item = i;

            return 1;
        case 3:
            cout << "What's the new price?" << endl;
            cin >> a;
            cin.ignore(1234, '\n');

            cout << "Whats the new name of the item?" << endl;
            cin.get(i, 50, '\n');
            cin.ignore(1234, '\n');

            amt = a;
            item = i;
            return 1;
        default:
            cout << "Incorrect choice" << endl;
            return 0;
    }

}

void Payment::price(float a){
    amt = a;
}

int Payment::compare(float a){
    if(amt > a){
        return 0; 
    }
    if(amt < a){
        return 1;
    }
    return 2;
}

float Payment::GetAmt(){
    return amt;
}

float P_Node::GetAmt(){
    return pay.GetAmt();
}
void P_Node::price(float a){
    pay.price(a);
}

P_Node * P_Node::GetRight(){
    return right;
}

P_Node * P_Node::GetLeft(){
    return left;
}

void SetLeft(P_Node * temp){
    left = temp;
}

void SetRight(P_Node * temp){
    right = temp;
}

int P_Node::compare(float a){
    return pay.compare(a);
}

int Economy::insert(){
    float a = 0;
    string i = "";
    P_Node * temp = root;

    cout << "How much did the order cost?" << endl;
    cin >> a;
    cin.ignore(1234, '\n');

    cout << "What was the name of the item ordered?" << endl;
    cin.get(i, 50, '\n');
    cin.ignore(1234, '\n');
    
    return insert(temp, a, i);
}

int Economy::insert(P_Node * temp, float a, string i){
    if(!root){
        root = new P_Node(a, i);
        return 1;
    }
    if(temp->compare(a) == 0){
        return insert(temp->GetLeft(), a, i);
    }
    return insert(temp->GetRight(), a, i);

}

int Economy::remove(){

    float a = 0;
    string i = "";
    P_Node * temp = root;

    cout << "How much did the order cost?" << endl;
    cin >> a;
    cin.ignore(1234, '\n');

    cout << "What was the name of the item ordered?" << endl;
    cin.get(i, 50, '\n');
    cin.ignore(1234, '\n');

    return remove(temp, a, i);
}

int Economy::remove(P_Node * temp, float a, string i){
    if(!temp){
        return 0;
    }
    if(temp->compare(a) == 2){
        if(temp->match(i) == 0){
            if(temp->GetRight() && temp->GetLeft()){
                delete temp;
                temp = nullptr;
                return 1;
            }
            else if(temp->GetRight() && temp->GetLeft()){
                P_Node * curr = temp->GetRight();
                P_Node * tail = curr;
                while(curr->GetLeft()){
                    tail = curr;
                    curr = curr->GetLeft();
                }
                temp.price(curr.GetAmt());
                delete curr;
                curr = nullptr;
                tail->SetLeft(nullptr);
                return 1;
            }
            else{
                if(temp->GetRight()){
                    P_Node * curr = temp->GetRight();
                    temp.price(curr.GetAmt());
                    delete curr;
                    temp.SetRight(nullptr);
                    return 1;
                }
                else{
                    P_Node * curr = temp->GetLeft();
                    temp.price(curr.GetAmt());
                    delete curr;
                    temp.SetLeft(nullptr);
                    return 1;
                }
            }
        }
        else{
            return remove(temp->GetRight(), a, i);
        }
    }
    if(temp->compare(a) == 0){
        return remove(temp->GetLeft(), a, i);
    }
    return remove(temp->GetRight(), a, i);

}

int Economy::display_all(){
    return display_all(root);
}

int Economy::display_all(P_Node * temp){    
    if(!temp){
        return 0;
    }
    display_all(temp->GetLeft());
    temp.display();
    display_all(temp->GetRight());
    return 0;

}