#include "gamewindowsetsink.h"
#include "../gamewindow.h"
gameWindowSETSink::gameWindowSETSink(gamewindow *ptr)
{
    ptr_gamewindow = ptr;
}
void gameWindowSETSink::OnCommandComplete(const std::string& str, bool bOK)
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
