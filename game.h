//
// Created by Amrit Rathie on 2019-05-16.
//

#ifndef CELLS_GAME_H
#define CELLS_GAME_H

void finish(int sig);

void render(const int &screenWidth, const int &screenHeight, Board *board);

void update(int &screenWidth, int &screenHeight, Board *&board);

void delay();

void initGame(int &screenWidth, int &screenHeight, Board *&board, std::vector<std::tuple<int, int>> &initial);

#endif //CELLS_GAME_H
