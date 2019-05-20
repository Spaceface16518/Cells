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

void render(sf::RenderWindow *&renderWindow, const Board *board) {
    renderWindow->clear(sf::Color::Black);

    // TODO: optimize this a bunch
    for (int i = 0; i < board->rawSize(); i++) {
        if (board->isAlive(i)) {
            int x, y;
            std::tie(x, y) = board->toPoint(i);

            sf::RectangleShape rect(sf::Vector2f(static_cast<float>(cellSize), static_cast<float>(cellSize)));

            rect.setPosition(static_cast<float>(x * cellSize), static_cast<float>(y * cellSize));
            rect.setFillColor(sf::Color::White);

            renderWindow->draw(rect);
        }
    }

    renderWindow->display();
}

void update(sf::RenderWindow *&renderWindow, Board *&board) {
    board = board->next();
    // TODO: handle window resizing
//        delete newBoard; // TODO: is this necessary? newBoard should be destroyed when scope ends
}
