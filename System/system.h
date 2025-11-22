#include <iostream>
#include <string>
#include <vector>
#include "Ingredients/ingredients.h"
#include "Contacts/contacts.h"
#include "Orders/orders.h"
#include "Maintenance/mnt.h"

using namespace std;

class System{
    public:
        System() : AllOrders(), inventory(), Mnt(), ContactList(){};\
        void menu();
    private:
        ContactList contacts;
        inventory stock;
        AllOrders orders;
        Mnt mnt;
};