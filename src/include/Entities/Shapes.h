#include "Tetromino.h"
#pragma once

class Oshape : public Tetromino {
    public: 
        Oshape();
        void rotate() override; // <- override, zmienia metode w klasie pochodnej
};

class Ishape : public Tetromino {
    public: 
        Ishape();
        void rotate() override;
};