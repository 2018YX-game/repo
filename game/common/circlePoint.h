#ifndef CIRCLEPOINT_H
#define CIRCLEPOINT_H

#include <vector>

class circlePoint
{
private:
    bool color;
    bool isStart;
    bool isMoveOn;
public:
    point(){
        color = 0;
        isStart = 0;
        isMoveOn = 0;
    }
    point(bool givenColor, bool givenIsStart, bool givenIsMoveOn){
        color = givenColor;
        isStart = givenIsStart;
        isMoveOn = givenIsMoveOn;
    }
    ~point(){}
    void setColor(bool givenColor){
        color = givenColor;
    }
    bool getColor() const {
        return color;
    }
    void setIsStart(bool givenIsStart){
        isStart = givenIsStart;
    }
    bool getIsStart() const {
        return isStart;
    }
    void setIsMoveOn(bool givenIsMoveOn){
        isMoveOn = givenIsMoveOn;
    }
    bool getIsMoveOn() const {
        return isMoveOn;
    }
};

class gameMap
{
private:
    int row;
    int col;
    vector<circlePoint> sameWorldMatrix;
public:
    gameMap(){}
    ~gameMap(){}
    void initialMatrix(int givenRow, int givenCol){
        row = givenRow;
        col = givenCol;
        sameWorldMatrix.resize(row * col);
    }
    void setMatrixPointColor(int pointRow, int pointCol, bool givenColor){
        int index = (pointRow - 1) * col + pointCol - 1;
        sameWorldMatrix[index].setColor(givenColor);
    }
    void setMatrixPointIsStart(int pointRow, int pointCol, bool givenIsStart){
        int index = (pointRow - 1) * col + pointCol - 1;
        sameWorldMatrix[index].setIsStart(givenIsStart);
    }
    void setMatrixPointIsMoveOn(int pointRow, int pointCol, bool givenIsMoveOn){
        int index = (pointRow - 1) * col + pointCol - 1;
        sameWorldMatrix[index].setIsMoveOn(givenIsMoveOn);
    }
    circlePoint& getMatrixPoint(int pointRow, int pointCol) const{
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index];
    }
    int getMatrixSize() const{
        return sameWorldMatrix.size();
    }
    int getMatrixRow() const{
        return row;
    }
    int getMatrixCol() const{
        return col;
    }
};



#endif // CIRCLEPOINT_H
