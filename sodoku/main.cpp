//
//  main.cpp
//  sodoku
//
//  Created by Nathan Fusselman on 12/19/20.
//

#include "board.hpp"

#include <iostream>

int main(int argc, const char * argv[]) {
    Board myBoard = Board();
    int choice;
    int difficulty = 50;
    while (true) {
        std::cout << "Welcome to Nathan's Sudoku Ganerator/Solver" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "1 - Generate New Board" << std::endl;
        std::cout << "2 - Set Difficulty (Default: 50)" << std::endl;
        std::cout << "3 - Display Answer" << std::endl;
        std::cout << "Enter Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                return 1;
                break;
            case 1:
                myBoard.generateRandom(difficulty);
                std::cout << myBoard << std::endl;
                break;
            case 2:
                std::cout << "\t Enter Difficulty: ";
                std::cin >> difficulty;
                break;
            case 3:
                myBoard.showAnswer();
                std::cout << myBoard << std::endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
