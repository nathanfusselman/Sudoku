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
    int activeBoard[9][9];
    int ansBoard[9][9];
    int optionsBoard[9][9][9];
    void newAnswerBoard();
    bool generateAnswer();
    bool checkValid(int x, int y, int value);
    void clearBoards();
public:
    explicit Board();
    ~Board();
    void generateRandom(int difficulty);
    void showAnswer();
};

#endif /* board_hpp */
