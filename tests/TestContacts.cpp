#include "../include/contacts.h"
#include "external/catch.hpp"

TEST_CASE("Contact compares names correctly.", "[Contacts]") {
    Contact con("Yes", 0);

    REQUIRE(con.compName("Yes"));
    REQUIRE_FALSE(con.compName("No"));
}

TEST_CASE("Contact compares names correctly.", "[Contacts]") {
    contactNode con("Yes", 0);

    REQUIRE(con.compName("Yes"));
    REQUIRE_FALSE(con.compName("No"));
}