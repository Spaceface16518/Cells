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
    float delay = 0.15;
    bool paused = false; // TODO: add UI pause indicator

    auto initial = get_initial_living(argc, argv);
    initGame(initial, window, board);

    while (window->isOpen()) {
        sf::Event event{};

        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            paused = !paused;
                            clock.restart();
                            break;
                        case sf::Keyboard::Down:
                            delay += 0.01;
                            break;
                        case sf::Keyboard::Up:
                            delay -= 0.01;
                            break;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    int x = event.mouseButton.x / cellSize;
                    int y = event.mouseButton.y / cellSize;

                    board->toggle(x, y);
                    break;
            }
        }

        auto elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() >= delay && !paused) {
            updateBoard(window, board);
            clock.restart();
        }

        renderBoard(window, board);
    }

    return 0;
}

