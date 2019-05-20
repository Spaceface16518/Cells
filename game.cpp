//
// Created by Amrit Rathie on 2019-05-16.
//

#include <SFML/Graphics.hpp>
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

void initGame(const std::vector<std::tuple<int, int>> &initial, sf::RenderWindow *&window,
              Board *&board) {// FIXME: make sure all parameters are in the right place
    constexpr int windowHeight = 1600;
    constexpr int windowWidth = 1200;
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Conway's Game of Life!");

    constexpr int boardHeight = windowHeight / cellSize;
    constexpr int boardWidth = windowWidth / cellSize;
    board = new Board(boardWidth, boardHeight);

    for (auto &coord : initial) {
        int x, y;
        std::tie(x, y) = coord;

        board->setAlive(x, y);
    }
}
