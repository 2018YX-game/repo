#include <QApplication>
#include "app.h"

GameAPP::GameAPP(){}
GameAPP::~GameAPP(){}
void GameAPP::run()
{
    model = std::make_shared<SWModel>();
    viewmodel = std::make_shared<SWViewModel>();

    viewmodel->setSWModel(model);


    _levelPageWindow.set_ptrCommand(viewmodel->getLayoutCommand());
    _gameWindow.set_ptrMouseMoveCommand(viewmodel->getMouseMoveCommand());
    _gameWindow.set_Martix(viewmodel->getSWMatrix());
    viewmodel->AddPropertyNotification(_gameWindow.getPtrWindowProSink());
    viewmodel->AddCommandNotification(_gameWindow.getPtrWindowSetSink());
    viewmodel->AddCommandNotification(_gameWindow.getPtrMouseMoveCommandSink());

    sp_StartButtonCommand_ = std::make_shared<StartButtonCommand>(this);
    _spGameWindowCommand = std::make_shared<gameWindowCommand>(this);
    _spGameCompleteCommand = std::make_shared<gamecompletecommand>(this);
    _startpageWindow.set_ptrCommand(std::static_pointer_cast<ICommandBase>(this->sp_StartButtonCommand_));
    _levelPageWindow.set_ptrOpenCommand(std::static_pointer_cast<ICommandBase>(this->_spGameWindowCommand));
    _gameWindow.set_ptrGameCompleteCommand(std::static_pointer_cast<ICommandBase>(this->_spGameCompleteCommand));

    _startpageWindow.show();
}
startpage* GameAPP::getStartPage()
{
    return &_startpageWindow;
}
gamewindow* GameAPP::getGameWindow()
{
    return &_gameWindow;
}
Form* GameAPP::getFormWindow(){
    return & _formWindow;
}
levelPage* GameAPP::getLevelPageWindow(){
    return &_levelPageWindow;
}

