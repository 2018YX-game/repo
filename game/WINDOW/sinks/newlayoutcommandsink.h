#ifndef NEWLAYOUTCOMMANDSINK_H
#define NEWLAYOUTCOMMANDSINK_H

#include"../../common/etlbase.h"
#include "qmessagebox.h"

class gamewindow;
class newLayoutCommandSink: public ICommandNotification
{
public:
    newLayoutCommandSink(gamewindow *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    gamewindow * ptr_gamewindow;
};
#endif // newLayoutCommandSink_H
