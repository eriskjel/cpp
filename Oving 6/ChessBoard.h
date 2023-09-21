//
// Created by eriks on 21/09/2023.
//

#ifndef OVING_6_CHESSBOARD_H
#define OVING_6_CHESSBOARD_H

#pragma once
#include <memory>
#include <vector>
#include <functional>


class ChessBoard {
public:
    enum class Color { WHITE, BLACK};

    ChessBoard();
    void printBoard();
    bool movePiece(const std::string &from, const std::string &to);
    std::function<void()> afterPieceMove;

    class Piece{
    public:
        Piece(Color color);
        virtual ~Piece();
        virtual char shortName() const = 0;
        virtual std::string type() const = 0;
        virtual bool validMove(int fromX, int fromY, int toX, int toY) const;
        Color color;
        virtual std::string colorToString() const;
    };

    class King : public Piece {
    public:
        King(Color color);
        char shortName() const override;
        std::string type() const override;
        bool validMove(int from_x, int from_y, int to_x, int to_y) const override;
    };

    class Knight : public Piece {
    public:
        Knight(Color color);
        char shortName() const override;
        std::string type() const override;
        bool validMove(int from_x, int from_y, int to_x, int to_y) const override;
    };

    std::vector<std::vector<std::unique_ptr<Piece>>> squares;
};


#endif //OVING_6_CHESSBOARD_H
