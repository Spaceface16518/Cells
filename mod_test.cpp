//
// Created by Amrit Rathie on 2019-05-15.
//

#include "mod.h"
#include "catch.h"

TEST_CASE("Signed modular arithmetic implementation", "[algorithm]") {
    SECTION("Regular modulus alignment") {
        REQUIRE(signed_mod(3, 1)
                == 3 % 1);
        REQUIRE(signed_mod(15, 4)
                == 15 % 4);
        REQUIRE(signed_mod(1000, 314)
                == 1000 % 314);
    }

    SECTION("Negative modulus") {
        REQUIRE(signed_mod(-1, 3)
                == 2);
        REQUIRE(signed_mod(-5, 4)
                == 3);
    }
}