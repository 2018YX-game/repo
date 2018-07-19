#ifndef SWMATRIX_H
#define SWMATRIX_H

#include <vector>

class SWPoint
{
private:
    bool color;
    int isStart;
    bool isExist;
public:
    SWPoint(){
        color = 0;
        isStart = 0;
        isExist = 1;
    }
    SWPoint(bool givenColor, int givenIsStart, bool givenIsExist){
        color = givenColor;
        isStart = givenIsStart;
        isExist = givenIsExist;
    }
    ~SWPoint(){}
    void setColor(bool givenColor){
        color = givenColor;
    }
    bool getColor() const {
        return color;
    }
    void setIsStart(int givenIsStart){
        isStart = givenIsStart;
    }
    int getIsStart() const {
        return isStart;
    }
    void setIsExist(bool givenIsExist){
        isExist = givenIsExist;
    }
    bool getIsExist() const {
        return isExist;
    }
};

typedef struct passingPointCoordinate{
    int row;
    int col;
}passPoint;

class SWMatrix
{
private:
    int row;
    int col;
    int level;
    std::vector<SWPoint> sameWorldMatrix;
    std::vector<passPoint> track;
public:
    SWMatrix(){
         row=0;
         col=0;
    }
    ~SWMatrix(){}
    void initialMatrix(int givenRow, int givenCol, int givenLevel){
        row = givenRow;
        col = givenCol;
        level = givenLevel;
        sameWorldMatrix.resize(0);
        sameWorldMatrix.resize(row * col);
        track.resize(0);
    }
    void setMatrixPointColor(int pointRow, int pointCol, bool givenColor){
        int index = (pointRow - 1) * col + pointCol - 1;
        sameWorldMatrix[index].setColor(givenColor);
    }
    void setMatrixPointIsStart(int pointRow, int pointCol, int givenIsStart){
        int index = (pointRow - 1) * col + pointCol - 1;
        sameWorldMatrix[index].setIsStart(givenIsStart);
    }
    void setMatrixPointIsExist(int pointRow, int pointCol, bool givenIsExist){
        int index = (pointRow - 1) * col + pointCol - 1;
        sameWorldMatrix[index].setIsExist(givenIsExist);
    }

    void setTrackFront(int pointRow, int pointCol){
        passPoint p;
        p.row = pointRow;
        p.col = pointCol;
        track.push_back(p);
    }
    void setTrackBack(){
        track.pop_back();
    }

    void trackClear(){
        track.clear();
    }

    passPoint getLastPointofTrack(){
        return track.back();
    }

    bool isTrackNotNull(){
        if(track.size() == 0) return false;
        return true;
    }

    int getTrackSize(){
        return (int)track.size();
    }

    bool isPassOn(int givenRow, int givenCol){
        for(int i = 0; i < track.size(); i++){
            if(track[i].row == givenRow && track[i].col == givenCol){
                return true;
            }
        }
        return false;
    }

    std::vector<passPoint>&getTrack(){
        return track;
    }

    bool getMatrixPointColor(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index].getColor();
    }
    int getMatrixPointIsStart(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index].getIsStart();
    }
    bool getMatrixPointIsExist(int pointRow, int pointCol){
        int index = (pointRow - 1) * col + pointCol - 1;
        return sameWorldMatrix[index].getIsExist();
    }
    int getMatrixRow() const{
        return row;
    }
    int getMatrixCol() const{
        return col;
    }
    int getMatrixLevel() const{
        return level;
    }
};



#endif // SWMATRIX_H
