#include "include/Entities/Tetromino.h"


void Tetromino::move(int dx, int dy) {
    x += dx;
    y += dy;
}

Tetromino::Tetromino(int x, int y) : x(x), y(y), matrix{} {

}

