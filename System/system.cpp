#include "system.h"

void System::menu(){
    int choice = 0;

    cout << "Welcome to the R.M.S. Your friendly neighborhood restaurant management system!" << endl;
    cout << "Here are your choices:" << endl;
    cout << "1. Business Contacts" << endl;
    cout << "2. Inventory" << endl;
    cout << "3. Orders" << endl;
    cout << "4. Maintenance Requests" << endl;
    cout << "5. Payments" << endl;
    cout << "6. Exit System" << endl;

    switch(choice):
        case 1:
            contacts.menu();
        case 2:
            stock.menu();
        case 3:
            orders.menu();
        case 4:
            mnt.menu();
        case 5:
            money.menu();
        case 6:
            Cout << "Exiting R.M.S. Have a phenomenal day!" << endl; 
        default:
            cout << "Incorrect Choice" << endl;
}