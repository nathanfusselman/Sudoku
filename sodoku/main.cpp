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
    std::cout << myBoard << std::endl;
    return 0;
}
