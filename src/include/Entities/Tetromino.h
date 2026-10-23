#pragma once

class Tetromino {
    protected:
        int x, y;
        int matrix[4][4];
    public:
        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
        
        int getMatrix(int x, int y) {
            return matrix[x][y];
        }

        Tetromino(int x = 3, int y = 0);
        virtual ~Tetromino() {} //polimorfizm

        void move(int dx, int dy);
        virtual void rotate() = 0;
};