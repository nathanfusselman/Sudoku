//
//  board.hpp
//  sodoku
//
//  Created by Nathan Fusselman on 12/19/20.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <string>

class Board {
    friend std::ostream& operator<<(std::ostream& os, const Board myBoard);
private:
    int activeBoard[10][10];
    int ansBoard[10][10];
    int optionsBoard[10][10][10];
public:
    explicit Board(int difficulty = 0);
    ~Board();
    void generateRandom(int difficulty);
};

#endif /* board_hpp */
