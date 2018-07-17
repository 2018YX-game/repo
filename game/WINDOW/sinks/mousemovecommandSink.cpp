#include "../gamewindow.h"
#include "mousemovecommandSink.h"
mouseMoveCommandSink::gameWindowSetSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}
void mouseMoveCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="mouseMoveCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();


        }
    }

}
