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

TEST_CASE("Contact compares names correctly.", "[contactList]") {
    contactList con;

    con.addContact("Yes", 0);

    REQUIRE(con.removeContact("Yes"));

    con.addContact("Yes", 0);

    REQUIRE_FALSE(con.compName("No"));
}

