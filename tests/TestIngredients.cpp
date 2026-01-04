#include "../include/ingredients.h"
#include "external/catch.hpp"

TEST_CASE("Contact compares names correctly.", "[contacts]") {
    contact con("Yes", 0);

    REQUIRE(con.compName("Yes"));
    REQUIRE_FALSE(con.compName("No"));
}