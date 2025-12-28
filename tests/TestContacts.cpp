#include "../include/contacts.h"
#include "external/catch.hpp"

TEST_CASE("Contact compares names correctly.", "[Contacts]") {
    Contact con("Yes", 0);

    REQUIRE(con.CompName("Yes"));
    REQUIRE_FALSE(con.CompName("No"));
}
