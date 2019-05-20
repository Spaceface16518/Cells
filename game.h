//
// Created by Amrit Rathie on 2019-05-16.
//

#ifndef CELLS_GAME_H
#define CELLS_GAME_H

#include <SFML/Graphics.hpp>

const unsigned int cellSize = 20;

void render(sf::RenderWindow *&renderWindow, const Board *board);

void update(sf::RenderWindow *&renderWindow, Board *&board);

void initGame(const std::vector<std::tuple<int, int>> &initial, sf::RenderWindow *&window, Board *&board);

#endif //CELLS_GAME_H
