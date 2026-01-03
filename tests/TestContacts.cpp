#include "../include/contacts.h"
#include "external/catch.hpp"

TEST_CASE("Contact compares names correctly.", "[contacts]") {
    contact con("Yes", 0);

    REQUIRE(con.compName("Yes"));
    REQUIRE_FALSE(con.compName("No"));
}

TEST_CASE("Contact compares names correctly.", "[contactNode]") {
    contactNode con("Yes", 0);

    REQUIRE(con.compName("Yes"));
    REQUIRE_FALSE(con.compName("No"));
}

TEST_CASE("Adds contact correctly", "[contactList]") {
    contactList con;

    con.addContact("Yes", 0);

    REQUIRE(con.removeContact("Yes"));

    con.addContact("Yes", 0);

    REQUIRE_FALSE(con.compName("No"));
}

TEST_CASE("Removes Contact Correctly", "[contactList]") {
    contactList con;
    string yes = "yes";
    int place = con.hashFunction(yes);
    REQUIRE(place < TABLE_SIZE && place > 0);
}