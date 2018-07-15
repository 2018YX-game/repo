#include "gameWindowSink.h"
#include "../gamewindow.h"
gameWindowSink::gameWindowSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}

 void gameWindowSink::OnPropertyChanged(const std::string& str){
    if(str=="SWMaritx"){
    ptr_gamewindow->update();
    }

}
