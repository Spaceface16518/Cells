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
    initGame(initial, window, board);

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

