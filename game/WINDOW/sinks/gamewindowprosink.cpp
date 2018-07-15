#include "gamewindowprosink.h"
#include "../gamewindow.h"
gameWindowPROSink::gameWindowPROSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}

 void gameWindowPROSink::OnPropertyChanged(const std::string& str){
    if(str=="SWMaritx"){
    ptr_gamewindow->update();
    }

}
