//
// Created by Amrit Rathie on 2019-05-13.
//

#ifndef CELLS_BOARD_H
#define CELLS_BOARD_H


#include <vector>
#include "Cell.h"

class Board {
public:
    Board(int width, int height);

    Board();

    Cell &operator[](int idx);

    const Cell &operator[](int idx) const;

    Cell &operator[](std::tuple<int, int> idx);

    const Cell &operator[](std::tuple<int, int> idx) const;

    const std::vector<std::tuple<int, int>> neighbors(std::tuple<int, int> idx) const;

    Board *const next() const;

    Board *const resize(int newWidth, int newHeight) const;

    int getWidth() const;

    int getHeight() const;

    // TODO: get rid of this
    bool isAlive(int x, int y) const;

    // TODO: get ride of this as well
    void setAlive(int x, int y);

    bool isAlive(int i) const;

    void setAlive(int i);

    int rawSize() const {
        return this->width * this->height;
    }

    int gridSize() const {
        return this->grid.size();
    }

    const int toRaw(std::tuple<int, int> point) const;

    const std::tuple<int, int> toPoint(int idx) const;

    const int toRaw(int x, int y) const;

private:

    std::vector<Cell> grid;

    int width, height;
};


#endif //CELLS_BOARD_H
