#ifndef POINTCHANGETRACKINGSINK_H
#define POINTCHANGETRACKINGSINK_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"

class gamewindow;
class pointChangeTrackingSink: public ICommandNotification
{
public:
    pointChangeTrackingSink(gamewindow *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    gamewindow * ptr_gamewindow;
};
#endif // POINTCHANGETRACKINGSINK_H
