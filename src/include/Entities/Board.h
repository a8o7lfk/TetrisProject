#pragma once //* zeby plik nie laczyl sie dwa razy
#include "Tetromino.h"

class Board {
    private:
        int width, height;
        int** grid;
    public:
        Board(int w, int h); //* konstuktor
        ~Board(); //*destruktor
        void draw(Tetromino* piece); //*wyswietlenie jest metoda

};