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