//
// Created by pawel on 28.05.19.
//

#ifndef BOMBERMAN_BOARD_H
#define BOMBERMAN_BOARD_H

struct Field{
    bool isWall= false;
    bool isBrick= false;
    bool hasMine= false;
    bool isReservated= false;
};
class Board {
Field board[50][50];
int width;
int height;
int countBrick;
public:
    Board(int width, int height);
    void setMine(int x, int y);
    bool isWall(int x, int y) const;
    bool isBrick(int x, int y) const;
    bool hasMine(int x, int y) const;
    void debugdisplay()const;
};


#endif //BOMBERMAN_BOARD_H
