#include "gamewindowsetsink.h"
#include "../gamewindow.h"
gameWindowSetSink::gameWindowSetSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}
void gameWindowSetSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str=="layoutCommand"){
        if(bOK==false){
            QMessageBox MSG;
            MSG.setWindowTitle(QString("error!"));
            MSG.exec();
      //      QMessageBox::information(NULL, str, "Content",QMessageBox::NoButton );

        }
    }

}
