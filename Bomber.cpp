//
// Created by pawel on 31.05.19.
//

#include "Bomber.h"
 Bomber::Bomber(Board &b,int number):field(b) {
    PlayerNumber=number;
    isAlive= true;
    countBomb=0;
    if(PlayerNumber==1)
    {
        position.y=1;
        position.x=1;
    }
    if(PlayerNumber==2)
    {
        position.y=field.getheight()-2;
        position.x=field.getwidth()-2;
    }
}
void Bomber::setBomb() {
    if(countBomb>4) return;
    field.setBomb(position.x,position.y);
    countBomb++;
}
bool Bomber::getAlive() const {
    if(isAlive) return true;
    else return false;
}
int Bomber::getcountBomb() const {
    return countBomb;
}
void Bomber::move(Direction dir) {
    if(dir=Up)
    {
        if(field.isBrick(position.x,position.y+1)) return;
        if(field.isWall(position.x,position.y+1)) return;
        position.y=position.y+1;
    }
    if(dir=Down)
    {
        if(field.isBrick(position.x,position.y-1)) return;
        if(field.isWall(position.x,position.y-1)) return;
        position.y=position.y-1;
    }
    if(dir=Left)
    {
        if(field.isBrick(position.x-1,position.y)) return;
        if(field.isWall(position.x-1,position.y)) return;
        position.x=position.x-1;
    }
    if(dir=Right)
    {
        if(field.isBrick(position.x+1,position.y)) return;
        if(field.isWall(position.x+1,position.y)) return;
        position.x=position.x+1;
    }
}