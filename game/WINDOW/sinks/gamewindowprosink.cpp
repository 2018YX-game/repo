#include "gamewindowprosink.h"
#include "../gamewindow.h"
gamewindowProSink::gamewindowProSink(gamewindow *ptr)
{

    ptr_gamewindow = ptr;
}

 void gamewindowProSink::OnPropertyChanged(const std::string& str){
    if(str=="SWMaritx"){
    ptr_gamewindow->update();
    }

}
