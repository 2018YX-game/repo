#include "newlayoutcommandsink.h"
#include "../gamewindow.h"
newLayoutCommandSink::newLayoutCommandSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}
void newLayoutCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="layoutCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();

        }
    }

}
