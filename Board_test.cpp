//
// Created by Amrit Rathie on 2019-05-15.
//

#include "Board.h"
#include "catch.h"


TEST_CASE("Board location algorithm", "[algorithm]") {
    auto board = new Board(25, 30);

    REQUIRE(board
                    ->

                            rawSize()

            == 25 * 30);
    REQUIRE(board
                    ->

                            gridSize()

            == 25 * 30);
    REQUIRE(board
                    ->

                            rawSize()

            == board->

            gridSize()

    );

    REQUIRE(board
                    ->toRaw(5, 6) == 155);
    REQUIRE(board
                    ->toPoint(155) == std::make_tuple(5, 6));
// Yes I counted to 155 myself
}

TEST_CASE("Board neighbor coordinate generation algorithm", "[algorithm]") {
    auto board = new Board(11, 15);

#define NEIGHBORS_TEST_REQUIRE(i, x, y) REQUIRE(std::get<0>(neighbors[(i)]) == (x)); REQUIRE(std::get<1>(neighbors[(i)]) == (y))


    SECTION("Regular coordinates") {
        auto coord = std::make_tuple(5, 7);
        auto neighbors = board->neighbors(coord);

        REQUIRE(neighbors
                        .

                                size()

                == 8);

        NEIGHBORS_TEST_REQUIRE(0, 4, 6);
        NEIGHBORS_TEST_REQUIRE(1, 5, 6);
        NEIGHBORS_TEST_REQUIRE(2, 6, 6);
        NEIGHBORS_TEST_REQUIRE(3, 6, 7);
        NEIGHBORS_TEST_REQUIRE(4, 6, 8);
        NEIGHBORS_TEST_REQUIRE(5, 5, 8);
        NEIGHBORS_TEST_REQUIRE(6, 4, 8);
        NEIGHBORS_TEST_REQUIRE(7, 4, 7);
    }

    SECTION("Edge coordinates") {
        auto coord = std::make_tuple(0, 6);
        auto neighbors = board->neighbors(coord);

        REQUIRE(neighbors
                        .

                                size()

                == 8);

        NEIGHBORS_TEST_REQUIRE(0, 10, 5);
        NEIGHBORS_TEST_REQUIRE(1, 0, 5);
        NEIGHBORS_TEST_REQUIRE(2, 1, 5);
        NEIGHBORS_TEST_REQUIRE(3, 1, 6);
        NEIGHBORS_TEST_REQUIRE(4, 1, 7);
        NEIGHBORS_TEST_REQUIRE(5, 0, 7);
        NEIGHBORS_TEST_REQUIRE(6, 10, 7);
        NEIGHBORS_TEST_REQUIRE(7, 10, 6);
    }
}