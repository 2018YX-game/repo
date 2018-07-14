#ifndef STRUCTURE_H
#define STRUCTURE_H

#define ROW 5
#define COL 5

struct point
{
    bool color;
    bool isStart;
    bool isMoveOn;

    point():color(0),isStart(0),isMoveOn(0) {}
};

struct  point matrix[ROW][COL];


#endif // STRUCTURE_H
