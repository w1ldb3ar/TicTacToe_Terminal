#include <iostream>
#include"Player.h"
int main() {
    

    Board board;
    XPlayer Xplayer(&board);
    OPlayer Oplayer(&board);

    Player* currentPlayer = &Xplayer;
    bool gameOver = false;
    int totalMoves = 0;

    cout << "Welcome to Tic Tac Toe!" <<endl;
    board.printBoard();

    while (!gameOver) {
        char move;
        cout << "Player"<<(currentPlayer==&Xplayer ? "X" : "O" )<<"'s turn. Enter a move (A-I): ";
        cin >> move;

        if (currentPlayer->makeMove(move)) {
            board.printBoard();
            totalMoves++;

            if (currentPlayer->haveTriple()){
                if (currentPlayer == &Xplayer) {
                    cout << "Congratulation Player X wins!" <<endl;
                 }else if(currentPlayer == &Oplayer)
                    cout << "Congratulation Player O wins!" <<endl;
                    gameOver = true;    
            } else if (totalMoves == 9) {
                cout << "WOW what a match the result was a tie!" << endl;
                gameOver = true;
            }
            currentPlayer = (currentPlayer == &Xplayer) ? static_cast<Player*>(&Oplayer) : static_cast<Player*>(&Xplayer);
        } else {
            cout << "This was an invalid move. Please try again." <<endl;
        }
    }

    return 0;
}
