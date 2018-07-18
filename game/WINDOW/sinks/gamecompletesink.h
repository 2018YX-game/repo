#ifndef GAMECOMPLETESINK_H
#define GAMECOMPLETESINK_H

#include"../../common/etlbase.h"

class gamewindow;
class gameCompleteSink: public IPropertyNotification
{
public:
    gameCompleteSink(gamewindow *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
    gamewindow * ptr_gamewindow;
};

#endif // GAMECOMPLETESINK_H
