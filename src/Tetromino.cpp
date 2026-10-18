#include "Tetromino.h"
#include "Board.h"
#include <iostream>

void Tetromino::move(int dx, int dy) {
    x += dx;
    y += dy;
}
Tetromino