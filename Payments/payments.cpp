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

            Amt = a;
            return 1;
        case 2:
            cout << "Whats the new name of the item?" << endl;
            cin.get(i, 50, '\n');
            cin.ignore(1234, '\n');

            Item = i;

            return 1;
        case 3:
            cout << "What's the new price?" << endl;
            cin >> a;
            cin.ignore(1234, '\n');

            cout << "Whats the new name of the item?" << endl;
            cin.get(i, 50, '\n');
            cin.ignore(1234, '\n');

            Amt = a;
            Item = i;
            return 1;
        default:
            cout << "Incorrect choice" << endl;
            return 0;
    }

}

void Payment::price(float a){
    Amt = a;
}

int Payment::Compare(float a){
    if(Amt > a){
        return 0; 
    }
    if(Amt < a){
        return 1;
    }
    return 2;
}

float Payment::GetAmt(){
    return Amt;
}

float P_Node::GetAmt(){
    return Pay.GetAmt();
}
void P_Node::Price(float a){
    Pay.Price(a);
}

P_Node * P_Node::GetRight(){
    return Right;
}

P_Node * P_Node::GetLeft(){
    return Left;
}

void P_Node::SetLeft(P_Node * temp){
    Left = temp;
}

void P_Node::SetRight(P_Node * temp){
    Right = temp;
}

int P_Node::Compare(float a){
    return Pay.Compare(a);
}

int Economy::Insert(){
    float a = 0;
    string i = "";
    P_Node * temp = Root;

    cout << "How much did the order cost?" << endl;
    cin >> a;
    cin.ignore(1234, '\n');

    cout << "What was the name of the item ordered?" << endl;
    cin.get(i, 50, '\n');
    cin.ignore(1234, '\n');
    
    return Insert(temp, a, i);
}

int Economy::Insert(P_Node * temp, float a, string i){
    if(!Root){
        Root = new P_Node(a, i);
        return 1;
    }
    if(temp->Compare(a) == 0){
        return Insert(temp->GetLeft(), a, i);
    }
    return Insert(temp->GetRight(), a, i);

}

int Economy::Remove(){

    float a = 0;
    string i = "";
    P_Node * temp = Root;

    cout << "How much did the order cost?" << endl;
    cin >> a;
    cin.ignore(1234, '\n');

    cout << "What was the name of the item ordered?" << endl;
    cin.get(i, 50, '\n');
    cin.ignore(1234, '\n');

    return Remove(temp, a, i);
}

int Economy::Remove(P_Node * temp, float a, string i){
    if(!temp){
        return 0;
    }
    if(temp->Compare(a) == 2){
        if(temp->Match(i) == 0){
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
                temp.Price(curr.GetAmt());
                delete curr;
                curr = nullptr;
                tail->SetLeft(nullptr);
                return 1;
            }
            else{
                if(temp->GetRight()){
                    P_Node * curr = temp->GetRight();
                    temp.Price(curr.GetAmt());
                    delete curr;
                    temp.SetRight(nullptr);
                    return 1;
                }
                else{
                    P_Node * curr = temp->GetLeft();
                    temp.Price(curr.GetAmt());
                    delete curr;
                    temp.SetLeft(nullptr);
                    return 1;
                }
            }
        }
        else{
            return Remove(temp->GetRight(), a, i);
        }
    }
    if(temp->Compare(a) == 0){
        return Remove(temp->GetLeft(), a, i);
    }
    return Remove(temp->GetRight(), a, i);

}

int Economy::DisplayAll(){
    return DisplayAll(Root);
}

int Economy::display_all(P_Node * temp){    
    if(!temp){
        return 0;
    }
    DisplayAll(temp->GetLeft());
    temp.Display();
    DisplayAll(temp->GetRight());
    return 0;

}

void Economy::Menu(){
    int choice = 0;

    while(choice != 4){
        cout << "1. Add Payment" << endl;
        cout << "2. Remove Payment" << endl;
        cout << "3. Display All" << endl;
        cout << "4. Exit Menu" << endl;

        switch(choice){
            case 1:
                Root->Insert();
            case 2:
                Root->Remove();
            case 3:
                Root->DisplayAll();
            case 4:
                cout << "Exiting Payments" << endl;
            default:
                cout << "Incorrect Choice" << endl;
        }
    }
}