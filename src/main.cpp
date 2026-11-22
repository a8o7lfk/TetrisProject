#include "include/Entities/Board.h"
#include <stdlib.h>
#include <windows.h>
#include "include/Entities/Shapes.h"
#include <conio.h> // nie dziala na linux :,-(
#include <cstdlib> // generatory radnomowych liczb na podstawie czasu
#include <ctime>


int main() {
    srand(time(NULL)); // inicjalizacja gemeratpra
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

        if (button == 'w') {
            currentPiece->rotate();
            if (board.isCollision(currentPiece, 0, 0)) {
                currentPiece->rotate();
            }
        }

        if (!(board.isCollision(currentPiece, 0, 1))) {
            currentPiece->move(0, 1);
        } else {
            int r = rand() % 2;
            board.lockPiece(currentPiece);
            board.clearLines();
            delete currentPiece;
            if (r == 0) {
                currentPiece = new Oshape();
            }
            else if (r == 1) {
                currentPiece = new Ishape();
            }
            
        }
        button = ' ';
        Sleep(500);
    }
    

    return 0;
}

