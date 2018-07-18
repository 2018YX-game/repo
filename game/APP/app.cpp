#include <QApplication>
#include "app.h"

GameAPP::GameAPP(){}
GameAPP::~GameAPP(){}
void GameAPP::run()
{
    model = std::make_shared<SWModel>();
    viewmodel = std::make_shared<SWViewModel>();

    viewmodel->setSWModel(model);

/*
    _gamewindow.set_ptrCommand(viewmodel->getLayoutCommand());
    _gamewindow.set_ptrMouseMoveCommand(viewmodel->getMouseMoveCommand());
    _gamewindow.set_Martix(viewmodel->getSWMatrix());
    viewmodel->AddPropertyNotification(_gamewindow.getPtrWindowProSink());
    viewmodel->AddCommandNotification(_gamewindow.getPtrWindowSetSink());
    viewmodel->AddCommandNotification(_gamewindow.getPtrMouseMoveCommandSink());
*/
    sp_StartButtonCommand_ = std::make_shared<StartButtonCommand>(this);

    _startpagewindow.set_ptrCommand(std::static_pointer_cast<ICommandBase>(this->sp_StartButtonCommand_));
    _startpagewindow.show();



}
startpage* GameAPP::getStartPage()
{
    return &_startpagewindow;
}
gamewindow* GameAPP::getGameWindow()
{
    return &_gamewindow;
}

