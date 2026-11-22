#include "Board.h"
#include <iostream> 
#include <windows.h>
#include "Tetromino.h"

Board::Board(int w, int h) : width(w), height(h) {
    grid = new int*[height];

    for (int i = 0; i < height; i++) {
        grid[i] = new int[width];
        for(int j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < height; i++) { 
        delete[] grid[i];
    }
    delete[] grid;

}
void Board::clearLines() {
    for (int i = height - 1; i >= 0; i--) {
        bool isFull = true;
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 0) {
                isFull = false;
                break;
            }
        }
        if (isFull) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < width; j++) {
                    grid[k][j] = grid[k-1][j];
                    
                }
            }
            i++;
            for (int j = 0; j < width; j++) {
                grid[0][j] = 0;
            }
        }
    }
    
}
void Board::lockPiece(Tetromino* piece) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece->getMatrix(i, j) == 1) {
                int X = piece->getX() + j;
                int Y = piece->getY() + i;
                grid[Y][X] = 1;
            }
        }
    }
}
bool Board::isCollision(Tetromino* piece, int dx, int dy) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece->getMatrix(i, j) == 0) {
                continue;
            }
            if (piece->getMatrix(i, j) == 1) {
                int future_x = piece->getX() + j + dx;
                int future_y = piece->getY() + i + dy;
                if (future_x < 0 || future_x >= width || future_y >= height)
                    return true; 
                if (grid[future_y][future_x] != 0) 
                    return true;
            }
        }
    }
    return false;
}
void Board::draw(Tetromino* piece) {
    bool isPiece = false;
    std::cout << "\x1B[H";
    for (int i = 0; i < height; i++) {
        std::cout << "#";

        for (int j = 0; j < width; j++) {
            bool isPiece = false;
            int px = piece->getX();
            int py = piece->getY();

            if (j >= px && j < px + 4 && i >= py && i < py + 4)  {
                if (piece->getMatrix(i - py, j - px) == 1) {
                    isPiece = true;
                }
            }
            if (isPiece == true) {
                std::cout << "@";
            }
            else if (grid[i][j] != 0) {
                std::cout << "X";
            }
            else if (grid[i][j] == 0)
                std::cout << ".";
            else    
                std::cout << "#";

        }
        std::cout << "#";
        std::cout << "\n";
    }

    for (int j = 0; j < width + 2; j++) {
        std::cout << "#";
    }
}