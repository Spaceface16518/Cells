#include "options.h"
#include "game.h"

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
                            game->toggle_pause();
                            game->restart_clock();
                            break;
                        case sf::Keyboard::Down:
                            game->increment_delay();
                            break;
                        case sf::Keyboard::Up:
                            game->decrement_delay();
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

        update(game);
        render(game);
    }

    return 0;
}

