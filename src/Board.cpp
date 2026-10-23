#include "Board.h"
#include <iostream> 
#include <windows.h>
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

void Board::draw(Tetromino* piece) {
    bool isPiece = false;
    COORD cursorPosition;
    cursorPosition.X = 0; // stawi kursor na zerowe koordynaty. dokladnie lewy gorny rog 
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition); // trik, zeby konsola nie mrogala. pozwala na odrysowanie nowych symboli w konsole
    for (int i = 0; i < height; i++) {
        std::cout << "#";

        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 0)
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