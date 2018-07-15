#include "gamewindowsetsink.h"
#include "../gamewindow.h"
gameWindowSETSink::gameWindowSETSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}
void gameWindowSETSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="layoutCommand"){
        if(bOk==false){
            QMessageBox::information(NULL, str, "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        }
    }

}
