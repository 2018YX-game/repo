
#ifndef GAMEWINDOWPROWSINK_H
#define GAMEWINDOWPROWSINK_H

#include"../../common/etlbase.h"

class gamewindow;
class gamewindowProSink: public IPropertyNotification
{
public:
    gamewindowProSink(gamewindow *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
    gamewindow * ptr_gamewindow;
};

#endif // GAMEWINDOWPROSINK_H
