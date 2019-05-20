#include <iostream>
#include "Board.h"
#include "ncurses.h"
#include "game.h"
#include "options.h"
#include <unistd.h>
#include <csignal>
#include <tuple>

int main(int argc, const char **argv) {
    int screenWidth, screenHeight;
    Board *board;

    auto initial = get_initial_living(argc, argv);

    initGame(screenWidth, screenHeight, board, initial);

    // TODO: make game interactive

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    for (;;) {
        render(screenWidth, screenHeight, board);
        update(screenWidth, screenHeight, board);
        delay();
    }
#pragma clang diagnostic pop
}

