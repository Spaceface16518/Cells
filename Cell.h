//
// Created by Amrit Rathie on 2019-05-13.
//

#ifndef CELLS_CELL_H
#define CELLS_CELL_H


#include <ostream>

class Cell {
public:
    explicit Cell(char alive);

    Cell();

    bool operator<(const Cell &rhs) const;

    bool operator>(const Cell &rhs) const;

    bool operator<=(const Cell &rhs) const;

    bool operator>=(const Cell &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

    char operator+(const Cell &rhs) const;

    void setAlive(char state);

    void setAlive(bool state);

    const bool isAlive() const;

    void makeAlive();

    void makeDead();

    char getStateValue() const;

    // TODO: actual display function
private:
    char alive;
};


#endif //CELLS_CELL_H
