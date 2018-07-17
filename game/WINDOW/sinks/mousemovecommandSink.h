#ifndef MOUSEMOVECOMMAND_H
#define MOUSEMOVECOMMAND_H
#include"../../common/etlbase.h"
#include "qmessagebox.h"

class gamewindow;
class mouseMoveCommandSink: public ICommandNotification
{
public:
    mouseMoveCommandSink(gamewindow *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    gamewindow * ptr_gamewindow;
};
#endif // MOUSEMOVECOMMAND_H
