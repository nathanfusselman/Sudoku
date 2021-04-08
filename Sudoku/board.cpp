//
//  board.cpp
//  Sudoku
//
//  Created by Nathan Fusselman on 12/19/20.
//

#include "board.hpp"

#include <iostream>

Board::Board() {
    clearBoards();
}

Board::~Board() {}

std::ostream& operator<<(std::ostream& os, Board myBoard) {
    for (int y = 0; y < 9; y++) {
        if (y == 3 || y == 6)
            os << "=======================================" << std::endl;
        else
            os << "---------------------------------------" << std::endl;
        os << "|";
        for (int x = 0; x < 9; x++) {
            if (x == 3 || x == 6)
                os << "|";
            if (myBoard.activeBoard[x][y] != 0) {
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

void Board::clearBoards() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            for (int z = 0; z < 9; z++) {
                optionsBoard[x][y][z] = 0;
            }
            activeBoard[x][y] = 0;
            ansBoard[x][y] = 0;
        }
    }
}

void Board::newAnswerBoard() {
    do {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                ansBoard[x][y] = 0;
            }
        }
    }
    while (!generateAnswer());
}

//This is beyond bad and needs major optimization
bool Board::generateAnswer() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            int trys = 0;
            do {
                ansBoard[x][y] = rand() % 9 + 1;
                trys++;
            }
            while (!checkValid(x, y, ansBoard[x][y]) && trys != 100);
            if (trys == 100) {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkValid(int x, int y, int value) {
    //Tests Rowas and Columns
    for (int n = 0; n < 9; n++) {
        if (ansBoard[x][n] == value && n != y)
            return false;
        if (ansBoard[n][y] == value && n != x)
            return false;
    }
    //Tests Blocks
    for (int testY = y - y%3; testY < (y - y%3) + 3; testY++) {
        for (int testX = x - x%3; testX < (x - x%3) + 3; testX++) {
            if (ansBoard[testX][testY] == value && testX != x && testY != y)
                return false;
        }
    }
    return true;
}

void Board::generateRandom(int difficulty) {
    clearBoards();
    newAnswerBoard();
    if (difficulty > 81)
        difficulty = 81;
    while (difficulty > 0) {
        int loc = rand() % 81;
        if (activeBoard[loc%9][loc/9] == 0) {
            activeBoard[loc%9][loc/9] = ansBoard[loc%9][loc/9];
            difficulty--;
        }
    }
}

void Board::showAnswer() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            activeBoard[x][y] =  ansBoard[x][y];
        }
    }
}
