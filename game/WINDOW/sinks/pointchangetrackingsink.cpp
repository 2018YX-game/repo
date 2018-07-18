#include "../gamewindow.h"
#include "pointchangetrackingsink.h"
pointChangeTrackingSink::pointChangeTrackingSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}
void pointChangeTrackingSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="mouseMoveCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();


        }
    }

}
