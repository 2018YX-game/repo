#ifndef SWMATRIX_H
#define SWMATRIX_H

#include <vector>

class SWPoint
{
private:
    bool color;
    bool isStart;
    bool isMoveOn;
public:
    SWPoint(){
        color = 0;
        isStart = 0;
        isMoveOn = 0;
    }
    SWPoint(bool givenColor, bool givenIsStart, bool givenIsMoveOn){
        color = givenColor;
        isStart = givenIsStart;
        isMoveOn = givenIsMoveOn;
    }
    ~SWPoint(){}
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

class SWMatrix
{
private:
    int row;
    int col;
   std::vector<SWPoint> sameWorldMatrix;
public:
    SWMatrix(){}
    ~SWMatrix(){}
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
    bool getMatrixPointColor(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index].color;
    }
    bool getMatrixPointIsStart(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index].isStart;
    }
    bool getMatrixPointIsMoveOn(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index].isMoveOn;
    }
    SWPoint& getMatrixPoint(int pointRow, int pointCol) {
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index];
    }
    int getMatrixRow() const{
        return row;
    }
    int getMatrixCol() const{
        return col;
    }
};



#endif // SWMATRIX_H
