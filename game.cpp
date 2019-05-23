//
// Created by Amrit Rathie on 2019-05-16.
//

#include "game.h"

void render(GameState *&gameState) {
    gameState->window->clear();

    renderBoard(gameState->window, gameState->board);
    renderUI(gameState->paused, gameState->window);

    gameState->window->display();
}


void renderBoard(sf::RenderWindow *&renderWindow, const Board *board) {
    // TODO: optimize this a bunch
    for (int i = 0; i < board->rawSize(); i++) {
        if (board->isAlive(i)) {
            int x, y;
            std::tie(x, y) = board->toPoint(i);

            sf::RectangleShape rect(sf::Vector2f(static_cast<float>(cellSize), static_cast<float>(cellSize)));

            rect.setPosition(static_cast<float>(x * cellSize), static_cast<float>(y * cellSize));
            rect.setFillColor(sf::Color::White);
            rect.scale(0.95, 0.95);

            renderWindow->draw(rect);
        }
    }
}

void renderUI(bool paused, sf::RenderWindow *&window) {
    if (paused) {
        sf::CircleShape triangle(35.0, 3); // TODO: don't create this every time it needs to be rendered

        const float offset = 49.49747468;

        triangle.setOrigin(triangle.getOrigin() + sf::Vector2f(offset, offset));
        triangle.setPosition(offset, offset);
        triangle.setRotation(90.0);
        triangle.setFillColor(sf::Color(0, 0, 255, 191));

        window->draw(triangle);
    }
}

void update(GameState *&gameState) {
    if (gameState->getElapsedClockTime() >= gameState->delay && !gameState->paused) {
        updateBoard(gameState->window, gameState->board);
        gameState->restart_clock();
    }
}

void updateBoard(sf::RenderWindow *&renderWindow, Board *&board) {
    board = board->next();
    // TODO: handle window resizing
}

GameState *
initGame(const std::vector<std::tuple<int, int>> initial) {// FIXME: make sure all parameters are in the right place
    constexpr int windowHeight = 1600;
    constexpr int windowWidth = 1200;
    auto window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Conway's Game of Life!");
    window->setFramerateLimit(10);

    constexpr int boardHeight = windowHeight / cellSize;
    constexpr int boardWidth = windowWidth / cellSize;
    auto board = new Board(boardWidth, boardHeight);

    for (auto &coord : initial) {
        int x, y;
        std::tie(x, y) = coord;

        board->setAlive(x, y);
    }

    return new GameState(window, board);
}
