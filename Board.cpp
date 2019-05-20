//
// Created by Amrit Rathie on 2019-05-13.
//

#include <numeric>
#include "Board.h"
#include "mod.h"
#include <tuple>

// Neighbor coordinates of a certain coordinate pair
// Generated from top row, left corner, in clockwise direction (ending on middle row, left side)
const std::vector<std::tuple<int, int>> Board::neighbors(std::tuple<int, int> idx) const {
    int xsize = this->width;
    int ysize = this->height;

    int x, y;
    std::tie(x, y) = idx;

    std::vector<std::tuple<int, int>> coords(8);

#define tuple_mod(x_coord, y_coord) std::make_tuple(signed_mod(x_coord, xsize), signed_mod(y_coord, ysize))

    coords[0] = tuple_mod(x - 1, y - 1); // Top left
    coords[1] = tuple_mod(x, y - 1); // Top center
    coords[2] = tuple_mod(x + 1, y - 1); // Top right
    coords[3] = tuple_mod(x + 1, y); // Middle right
    coords[4] = tuple_mod(x + 1, y + 1); // Bottom right
    coords[5] = tuple_mod(x, y + 1); // Bottom center
    coords[6] = tuple_mod(x - 1, y + 1); // Bottom left
    coords[7] = tuple_mod(x - 1, y); // Middle left

    return coords;
}

const int Board::toRaw(std::tuple<int, int> point) const {
    int x, y;
    std::tie(x, y) = point;

    return this->toRaw(x, y);
}


const int Board::toRaw(int x, int y) const {
    return this->width * (y % this->height) + (x % this->width);
}

const std::tuple<int, int> Board::toPoint(int idx) const {
    int x, y;

    x = idx % this->width;

    y = (idx - x) / this->width;

    return std::make_tuple(x, y);
}

Cell &Board::operator[](int idx) {
    return this->grid.at(idx);
}

const Cell &Board::operator[](int idx) const {
    return this->grid.at(idx);
}

Cell &Board::operator[](std::tuple<int, int> idx) {
    int i = this->toRaw(idx);

    return this->operator[](i);
}

const Cell &Board::operator[](std::tuple<int, int> idx) const {
    int i = this->toRaw(idx);

    return this->operator[](i);
}

Board::Board(int width, int height) : width(width), height(height),
                                      grid(std::vector<Cell>(width * height, Cell())) {}

Board::Board() : Board(0, 0) {}


Board *const Board::next() const {
    auto next = new Board(this->width, this->height);

    for (int i = 0; i < this->grid.size(); ++i) {
        // Collect neighbors
        auto neighbors = this->neighbors(this->toPoint(i));

        int sum = 0;
        for (auto coord : neighbors) {
            auto index = this->toRaw(coord);

            sum += static_cast<int>(this->grid.at(index).getStateValue());
        }

        // Set the cell's state
        // TODO: index board instead of internal grid
        bool nextState;
        if (this->grid.at(i).isAlive()) {
            nextState = sum == 2 || sum == 3;
        } else {
            nextState = sum == 3;
        }
        next->grid[i].setAlive(nextState);
    }

    return next;
}

Board *const Board::resize(int newWidth, int newHeight) const {
    auto board = new Board(newWidth, newHeight);

    // Only iterate over the minimum
    const auto &maxY = std::min(newHeight, this->height);
    const auto &maxX = std::min(newWidth, this->width);

    for (int row = 0; row < maxY; ++row) {
        for (int column = 0; column < maxX; ++column) {
            // Get the raw array location of this point
            auto i = this->toRaw(column, row);

            // Copy location state
            if (this->grid[i].isAlive()) {
                board->grid[i].setAlive(true);
            }
            // TODO: use board indexing for this too
        }
    }

    return board;
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

bool Board::isAlive(int x, int y) const {
    int i = this->toRaw(x, y);
    return this->grid[i].isAlive();
}

void Board::setAlive(int x, int y) {
    int i = this->toRaw(x, y);
    this->grid[i].makeAlive();
}