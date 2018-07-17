#include "../gamewindow.h"
#include "mousemovecommandsink.h"
mouseMoveCommandSink::mouseMoveCommandSink(gamewindow *ptr)
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
