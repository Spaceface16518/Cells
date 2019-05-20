//
// Created by Amrit Rathie on 2019-05-13.
//

#include "Cell.h"

bool Cell::operator<(const Cell &rhs) const {
    return alive < rhs.alive;
}

bool Cell::operator>(const Cell &rhs) const {
    return rhs < *this;
}

bool Cell::operator<=(const Cell &rhs) const {
    return !(rhs < *this);
}

bool Cell::operator>=(const Cell &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    os << "alive: " << bool(cell.alive);
    return os;
}

char Cell::operator+(const Cell &rhs) const {
    return this->alive + rhs.alive;
}

Cell::Cell(char alive) : alive(alive) {}

Cell::Cell() : alive(0) {}

void Cell::setAlive(char state) {
    Cell::alive = state;
}

void Cell::setAlive(bool state) {
    Cell::alive = static_cast<char>(state);
}

const bool Cell::isAlive() const {
    return bool(this->alive);
}

void Cell::makeAlive() {
    this->setAlive(static_cast<char>(1));
}

void Cell::makeDead() {
    this->setAlive(static_cast<char>(0));
}

char Cell::getStateValue() const {
    return alive;
}
