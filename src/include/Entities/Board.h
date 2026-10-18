#pragma once //* zeby plik nie laczyl sie dwa razy

class Board {
    private:
        int width, height;
        int** grid;
    public:
        Board(int w, int h); //* konstuktor
        ~Board(); //*destruktor
        void draw(); //*wyswietlenie jest metoda

};