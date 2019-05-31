//
// Created by pawel on 28.05.19.
//

#include "Board.h"
Board::Board() {

}
bool Board::isWall(int x, int y) const {
    if(board[y][x].isWall) return true;
    return false;
}
bool Board::hasMine(int x, int y) const {
    if(board[y][x].hasMine) return true;
    return false;
}
bool Board::isBrick(int x, int y) const {
    if(board[y][x].isBrick) return true;
    return false;
}
void Board::setMine(int x, int y) {
    if(hasMine(x,y)) return;
    if(isBrick(x,y)) return;
    if(isWall(x,y)) return;
    board[y][x].hasMine=true;
}