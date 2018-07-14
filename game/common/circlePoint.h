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

class matrix
{
private:
    int row;
    int col;
    vector<circlePoint> sameWorldMatrix;
public:
    matrix(){}
    ~matrix(){
        sameWorldMatrix.~ vector<circlePoint>();
    }
    void initialMatrix(int givenRow, int givenCol){
        row = givenRow;
        col = givenCol;
        for(int i=0;i<row * col;i++){
            sameWorldMatrix.push_back(circlePoint());
        }
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
    circlePoint getMatrixPoint(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index];
    }
};



#endif // CIRCLEPOINT_H
