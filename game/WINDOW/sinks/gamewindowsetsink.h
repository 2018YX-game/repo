#ifndef GAMEWINDOWSETSINK_H
#define GAMEWINDOWSETSINK_H

#include"../../common/etlbase.h"

class gamewindow;
class gameWindowSETSink: public ICommandNotification
{
public:
    gameWindowSETSink(gamewindow *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    gamewindow * ptr_gamewindow;
};
#endif // GAMEWINDOWSETSINK_H
