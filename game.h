//
// Created by Amrit Rathie on 2019-05-16.
//

#ifndef CELLS_GAME_H
#define CELLS_GAME_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

const unsigned int cellSize = 20;

void render(GameState *&gameState);

void renderBoard(sf::RenderWindow *&renderWindow, const Board *board);

void renderUI(bool paused, sf::RenderWindow *&window);

void update(GameState *&gameState);

void updateBoard(sf::RenderWindow *&renderWindow, Board *&board);

GameState *initGame(std::vector<std::tuple<int, int>> initial);

#endif //CELLS_GAME_H
