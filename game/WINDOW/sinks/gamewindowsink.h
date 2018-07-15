#ifndef GAMEWINDOWSINK_H
#define GAMEWINDOWSINK_H
#include"../etlbase.h"

class gamewindow;
class gameWindowSink: public IPropertyNotification
{
public:
    gameWindowSink(gamewindow *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
    gamewindow * ptr_gamewindow;
};

#endif // GAMEWINDOWSINK_H
