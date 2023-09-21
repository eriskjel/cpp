#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "ChessBoardPrint.cpp"
#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
        square_column.resize(8);
}

void ChessBoard::printBoard() {
    for (int y = 7; y >= 0; --y) {
        for (int x = 0; x < 8; ++x) {
            if (squares[x][y]) {
                cout << squares[x][y]->shortName() << ' ';
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

bool ChessBoard::movePiece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
        if (piece_from->validMove(from_x, from_y, to_x, to_y)) {
            cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
            auto &piece_to = squares[to_x][to_y];
            if (piece_to) {
                if (piece_from->color != piece_to->color) {
                    cout << piece_to->type() << " is being removed from " << to << endl;
                    if (auto king = dynamic_cast<King *>(piece_to.get()))
                        cout << king->colorToString() << " lost the game" << endl;
                } else {
                    // piece in the from square has the same color as the piece in the to square
                    cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                    return false;
                }
            }
            piece_to = move(piece_from);
            if (afterPieceMove){
                afterPieceMove();
            }
            return true;
        } else {
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
        }
    } else {
        cout << "no piece at " << from << endl;
        return false;
    }
}

ChessBoard::Piece::Piece(Color color) : color(color) {
    // Initialization code here
}

std::string ChessBoard::Piece::colorToString() const {
    if (color == Color::WHITE)
        return "white";
    else
        return "black";
}

bool ChessBoard::Piece::validMove(int fromX, int fromY, int toX, int toY) const {
    return 0;
}

ChessBoard::Piece::~Piece() {

}

bool ChessBoard::King::validMove(int from_x, int from_y, int to_x, int to_y) const {
    if(std::abs(to_x - from_x) <= 1 &&  std::abs(to_y - from_y) <= 1){
        return true;
    }
    return false;
}

bool ChessBoard::Knight::validMove(int from_x, int from_y, int to_x, int to_y) const {
    if((abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1) or (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2)){
        return true;
    }
    return false;
}


ChessBoard::King::King(Color color) : Piece(color) {
    // Initialization code
}

char ChessBoard::King::shortName() const {
    return color == Color::WHITE ? 'K' : 'k';
}

std::string ChessBoard::King::type() const {
    return colorToString() + " king";
}


ChessBoard::Knight::Knight(Color color) : Piece(color) {
    // Initialization code
}

char ChessBoard::Knight::shortName() const {
    return color == Color::WHITE ? 'K' : 'k';
}

std::string ChessBoard::Knight::type() const {
    return colorToString() + " knight";
}


int main() {
    ChessBoard board;
    ChessBoardPrint boardPrint(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.movePiece("e3", "e2");
    board.movePiece("e1", "e3");
    board.movePiece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;

    cout << "Initial board:" << endl;
    board.printBoard();
    cout << endl;


    board.movePiece("e1", "e2");
    board.movePiece("g8", "h6");
    board.movePiece("b1", "c3");
    board.movePiece("h6", "g8");
    board.movePiece("c3", "d5");
    board.movePiece("g8", "h6");
    board.movePiece("d5", "f6");
    board.movePiece("h6", "g8");
    board.movePiece("f6", "e8");
}