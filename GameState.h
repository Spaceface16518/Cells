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

    // Toggles the current pause state of the game, and returns the new state
    inline void toggle_pause() {
        this->paused = !this->paused;
    }

    inline void restart_clock() {
        this->clock.restart();
    }

    inline float getElapsedClockTime() {
        return this->clock.getElapsedTime().asSeconds();
    }

    inline void increment_delay(float by = 0.01) {
        this->delay += by;
    }

    inline void decrement_delay(float by = 0.01) {
        this->delay -= by;
    }

public:
    bool paused;
    float delay;
    sf::Clock clock;
    sf::RenderWindow *window;
    Board *board;
};


#endif //CELLS_GAMESTATE_H
