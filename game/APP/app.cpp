#include <QApplication>
#include "app.h"

GameAPP::GameAPP(){}
GameAPP::~GameAPP(){}
void GameAPP::run()
{
    model = std::make_shared<SWModel>();
    viewmodel = std::make_shared<SWViewModel>();

    viewmodel->setSWModel(model);


    window2.set_ptrCommand(viewmodel->getLayoutCommand());
    window2.set_Martix(viewmodel->getSWMatrix());
    viewmodel->AddPropertyNotification(window2.getPtrWindowProSink());
    viewmodel->AddCommandNotification(window2.getPtrWindowSetSink());

    sp_StartButtonCommand_ = std::make_shared<StartButtonCommand>(this);

    window1.set_ptrCommand(std::static_pointer_cast<ICommandBase>(this->sp_StartButtonCommand_));
    window1.show();



}


