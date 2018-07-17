#ifndef GAMEWINDOWSETSINK_H
#define GAMEWINDOWSETSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"

class gamewindow;
class gameWindowSetSink: public ICommandNotification
{
public:
    gameWindowSetSink(gamewindow *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    gamewindow * ptr_gamewindow;
};
#endif // GAMEWINDOWSETSINK_H
