//
// Created by pawel on 28.05.19.
//

#ifndef BOMBERMAN_BOARD_H
#define BOMBERMAN_BOARD_H

struct Field{
    bool isWall=0;
    bool isBrick=0;
    bool hasMine=0;
};
class Board {
Field board[50][50];
public:
    Board();
    void setMine(int x, int y);
    bool isWall(int x, int y) const;
    bool isBrick(int x, int y) const;
    bool hasMine(int x, int y) const;
};


#endif //BOMBERMAN_BOARD_H
