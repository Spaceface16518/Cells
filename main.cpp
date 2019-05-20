#include <iostream>
#include "Board.h"
#include "game.h"
#include "options.h"
#include <unistd.h>
#include <csignal>
#include <tuple>
#include <SFML/Graphics.hpp>

int main(int argc, const char **argv) {
    sf::RenderWindow *window = nullptr;
    Board *board = nullptr;
    sf::Clock clock;
    const float delay = 0.15; // TODO: make this interactive/user-modifiable

    auto initial = get_initial_living(argc, argv);

    // FIXME: make sure all parameters are in the right place
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

    // TODO: make game interactive

    while (window->isOpen()) {
        sf::Event event{};

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        auto elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() >= delay) {
            update(window, board);
            clock.restart();
        }

        render(window, board);
    }

    return 0;
}

