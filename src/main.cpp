#include "Board.h"
#include <stdlib.h>
#include <windows.h>
#include "Shapes.h"
#include <conio.h> // nie dziala na linux :,-(

int main() {
    char button;
    system("cls");
    Board board(10, 20); // stworzenie obiektu, board 10x20 
    Tetromino* currentPiece = new Oshape(); // stworzenie nowego wskaznika(currentPiece) typu Tetromino i wydzielenie pamieci
    

    while (true) {
        board.draw(currentPiece);
        if (_kbhit())
            button = _getch();
        if (button == 'a') {
            if (!(board.isCollision(currentPiece, -1, 0)))
                currentPiece->move(-1, 0);
        }

        if (button == 'd') {
            if (!(board.isCollision(currentPiece, 1, 0)))
                currentPiece->move(1, 0);
        }

        if (!(board.isCollision(currentPiece, 0, 1)))
            currentPiece->move(0, 1);
        else 
            break;
        button = ' ';
        Sleep(500);
    }
    

    return 0;
}

