//
// Created by Amrit Rathie on 2019-05-22.
//

#ifndef CELLS_GAMESTATE_H
#define CELLS_GAMESTATE_H


#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Board.h"

class GameState {
public:
    GameState(sf::RenderWindow *window, Board *board);

public:
    bool paused; // TODO: add UI pause indicator
    float delay;
    sf::Clock clock;
    sf::RenderWindow *window;
    Board *board;
};


#endif //CELLS_GAMESTATE_H
