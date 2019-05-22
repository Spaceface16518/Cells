//
// Created by Amrit Rathie on 2019-05-22.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow *window, Board *board) : window(window), board(board), paused(false), delay(0.15),
                                                               clock(sf::Clock()) {}