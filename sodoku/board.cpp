//
//  board.cpp
//  sodoku
//
//  Created by Nathan Fusselman on 12/19/20.
//

#include "board.hpp"

#include <iostream>

Board::Board(int difficulty) {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            for (int z = 0; z < 10; z++) {
                optionsBoard[x][y][z] = -1;
            }
            activeBoard[x][y] = x;
            ansBoard[x][y] = -1;
        }
    }
}

Board::~Board() {}

std::ostream& operator<<(std::ostream& os, Board myBoard) {
    for (int y = 1; y < 10; y++) {
        if (y == 4 || y == 7)
            os << "=======================================" << std::endl;
        else
            os << "---------------------------------------" << std::endl;
        os << "|";
        for (int x = 1; x < 10; x++) {
            if (x == 4 || x == 7)
                os << "|";
            if (myBoard.activeBoard[x][y] != -1) {
                os << " " << myBoard.activeBoard[x][y] << " |";
            } else {
                os << "   |";
            }
        }
        os << std::endl;
    }
    os << "---------------------------------------";
    return os;
}

