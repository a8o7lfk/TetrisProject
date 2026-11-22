#include "include/Entities/Shapes.h"
// Oshape
Oshape::Oshape() {
    for (int i = 0; i < 2; i++) {
        for ( int j = 0; j < 2; j++) {
            matrix[i][j] = 1;
        }
    }
}
void Oshape::rotate() {
}

// Ishape
Ishape::Ishape() {
    for (int j = 0; j < 4; j++) {
        matrix[1][j] = 1;
    }
}
void Ishape::rotate() {
    int temp[4][4] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[j][3 - i] = matrix[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

// Lshape
Lshape::Lshape() {
    for (int j = 0; j < 3; j++) {
        matrix[j][0] = 1;
    }
    matrix[2][1] = 1;
}

void Lshape::rotate() {
    int temp[4][4] = {0};
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            temp[j][2 - i] = matrix[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0 ; j < 4; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}