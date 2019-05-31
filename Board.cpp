//
// Created by pawel on 28.05.19.
//

#include "Board.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Board::Board(int width, int height) {
this->width=width;
this->height=height;
for(int line=0;line<height;++line)
{
board[line][0].isWall= true;
board[line][width-1].isWall= true;
}
for(int col=0;col<width;++col)
{
    board[0][col].isWall= true;
    board[height-1][col].isWall= true;
}
for(int line=2;line<height;line=line+2)
{
    for(int col=2;col<width;col=col+2)
    {
        board[line][col].isWall=true;
    }
}

board[1][1].isReservated= true;
board[1][2].isReservated= true;
board[2][1].isReservated= true;
board[height-2][width-2].isReservated= true;
board[height-2][width-3].isReservated= true;
board[height-3][width-2].isReservated= true;
countBrick=0.4*width*height;
int brick=countBrick;
srand( time( NULL ) );
int line;
int col;
while(brick>0)
{
line=rand()%height;
col=rand()%width;
if(board[line][col].isReservated) continue;
if(board[line][col].isWall) continue;
if(board[line][col].isBrick) continue;
board[line][col].isBrick= true;
--brick;
}
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
void Board::debugdisplay() const {
    for(int line=0; line<height ;++line)
    {
        for(int col=0; col<width ;++col)
        {
            cout<<"[";
         if(board[line][col].hasMine) cout<<"M";
         else cout<<".";
         if(board[line][col].isWall) cout<<"W";
         else cout<<".";
         if(board[line][col].isBrick) cout<<"B";
         else cout<<".";
         if(board[line][col].isReservated) cout<<"R";
         else cout<<".";
            cout<<"]";
        }
        cout<<endl;
    }
}