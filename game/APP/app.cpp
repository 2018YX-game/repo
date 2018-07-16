#include <QApplication>
#include "../APP/app.h"

APP::APP()
{
    model = std::make_shared<SWModel>();
    viewmodel = std::make_shared<SWViewModel>();

    viewmodel->setSWModel(model);

    window1.set_ptrCommand(viewmodel->getLayoutCommand());
    window2.set_ptrCommand(viewmodel->getLayoutCommand());
    window2.set_Martix(viewmodel->getSWMatrix());
    viewmodel->AddPropertyNotification(window2.getPtrWindowProSink());
    viewmodel->AddCommandNotification(window2.getPtrWindowSetSink());
}

void APP::run()
{
    window1.show();

}
