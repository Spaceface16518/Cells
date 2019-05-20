//
// Created by Amrit Rathie on 2019-05-16.
//

#include <tuple>
#include <csignal>
#include <unistd.h>
#include "curses.h"
#include "Board.h"
#include <iostream>
#include "game.h"
#include "options.h"

void finish(int sig) {
    endwin();

    exit(0);
}

void render(const int &screenWidth, const int &screenHeight, Board *board) {
    clear();

    // TODO: optimize this maybe
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            mvprintw(y, x, board->isAlive(x, y) ? "@" : " "); // TODO: choose final dead/living characters
        }
    }

    refresh();
}

void update(int &screenWidth, int &screenHeight, Board *&board) {
    Board *newBoard = nullptr;

    int currScreenHeight, currScreenWidth;
    getmaxyx(stdscr, currScreenHeight, currScreenWidth);

    if (currScreenHeight != screenHeight || currScreenWidth != screenWidth) {
        newBoard = board->resize(currScreenWidth, currScreenHeight);
    }

    if (newBoard == nullptr) {
        newBoard = board->next();
    } else {
        newBoard = newBoard->next();
    }

    board = newBoard;
//        delete newBoard; // TODO: is this necessary? newBoard should be destroyed when scope ends
    screenHeight = currScreenHeight;
    screenWidth = currScreenWidth;
}

void delay() { usleep(100000); }

void initGame(int &screenWidth, int &screenHeight, Board *&board, std::vector<std::tuple<int, int>> &initial) {
    signal(SIGINT, finish);

    initscr();
    refresh(); // TODO: necessary?
    noecho();

    getmaxyx(stdscr, screenHeight, screenWidth);
    board = new Board(screenWidth, screenHeight);

    for (auto &coord : initial) {
        int x, y;
        std::tie(x, y) = coord;

        board->setAlive(x, y);
    }
}

