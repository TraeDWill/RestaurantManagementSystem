#include <iostream>
#include <string>
#include <vector>
#include "Ingredients/ingredients.h"
#include "Contacts/contacts.h"
#include "Orders/orders.h"
#include "Maintenance/mnt.h"
#include "Payments/payments.h"

using namespace std;

class System{
    public:
        System() : AllOrders(), Inventory(), Mnt(), ContactList(), Payment(){};\
        void Menu();
    private:
        ContactList contacts;
        Inventory stock;
        AllOrders orders;
        Mnt mnt;
        Economy money;
};