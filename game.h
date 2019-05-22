//
// Created by Amrit Rathie on 2019-05-16.
//

#ifndef CELLS_GAME_H
#define CELLS_GAME_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

const unsigned int cellSize = 20;

void renderBoard(sf::RenderWindow *&renderWindow, const Board *board);

void renderUI(sf::RenderWindow *&renderWindow, GameState *gameState);

void updateBoard(sf::RenderWindow *&renderWindow, Board *&board);

GameState *initGame(const std::vector<std::tuple<int, int>> initial);

#endif //CELLS_GAME_H
