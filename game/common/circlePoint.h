#ifndef CIRCLEPOINT_H
#define CIRCLEPOINT_H

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



#endif // CIRCLEPOINT_H
