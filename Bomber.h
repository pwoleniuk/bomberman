//
// Created by pawel on 31.05.19.
//

#ifndef BOMBERMAN_BOMBER_H
#define BOMBERMAN_BOMBER_H


#include "Board.h"

struct Pos {
    int x;
    int y;
};
enum Direction {Up,Right,Down,Left};

class Bomber {
    int PlayerNumber;
    Pos position;
    bool isAlive;
    int countBomb;
    Board &field;
public:
    Bomber(Board &b,int number);

    void setBomb();

    bool getAlive() const;

    int getcountBomb() const;

    void move(Direction dir);

};


#endif //BOMBERMAN_BOMBER_H
