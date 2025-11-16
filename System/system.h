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
        System() : AllOrders(), category(char * t_name)
    private:
        ContactList contacts;
        category stock;
        AllOrders orders;
        Mnt mnt;
};