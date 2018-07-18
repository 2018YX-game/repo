#include "gamecompletesink.h"
#include "../gamewindow.h"

gameCompleteSink::gameCompleteSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}

void gameCompleteSink::OnPropertyChanged(const std::string& str){
    if(str=="GameComplete"){
        ptr_gamewindow->openForm();
    }
}
