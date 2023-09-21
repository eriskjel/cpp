//
// Created by eriks on 21/09/2023.
//



#include <iostream>
#include "ChessBoard.h"

using namespace std;

class ChessBoardPrint{
public:
    ChessBoardPrint(ChessBoard& chessBoard) : chessBoard(chessBoard) {
        chessBoard.afterPieceMove = [this](){
            this->print_board();
        };
    };

    void print_board() {
        for (int y = 7; y >= 0; --y) {
            for (int x = 0; x < 8; ++x) {
                if (chessBoard.squares[x][y]) {
                    cout << chessBoard.squares[x][y]->shortName() << ' ';
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
private:
    ChessBoard& chessBoard;

};