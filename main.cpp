#include <iostream>
#include "Board.h"
#include "game.h"
#include "options.h"
#include <unistd.h>
#include <csignal>
#include <tuple>
#include <SFML/Graphics.hpp>

int main(int argc, const char **argv) {
    auto initial = get_initial_living(argc, argv);
    GameState *game = initGame(initial);

    while (game->window->isOpen()) {
        sf::Event event{};

        while (game->window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    game->window->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            game->paused = !game->paused;
                            game->clock.restart();
                            break;
                        case sf::Keyboard::Down:
                            game->delay += 0.01;
                            break;
                        case sf::Keyboard::Up:
                            game->delay -= 0.01;
                            break;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    int x = event.mouseButton.x / cellSize;
                    int y = event.mouseButton.y / cellSize;

                    game->board->toggle(x, y);
                    break;
            }
        }

        auto elapsedTime = game->clock.getElapsedTime();
        if (elapsedTime.asSeconds() >= game->delay && !game->paused) {
            updateBoard(game->window, game->board);
            game->clock.restart();
        }

        renderBoard(game->window, game->board);
    }

    return 0;
}

