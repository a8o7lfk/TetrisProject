#pragma once

class Tetromino {
    private:
        int x, y;
        int matrix[4][4];
    public:
        Tetromino();
        virtual ~Tetromino() {} //polimorfizm

        void move(int dx, int dy);
        virtual void rotate() = 0;
};