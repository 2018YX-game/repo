#include <QApplication>
#include "app.h"

GameAPP::GameAPP(){}
GameAPP::~GameAPP(){}
void GameAPP::run()
{
    model = std::make_shared<SWModel>();
    viewmodel = std::make_shared<SWViewModel>();

    viewmodel->setSWModel(model);
    _gameWindow.setGameAgainCommand(viewmodel->getLayoutCommand());
    _formWindow.setNewGameCommand(viewmodel->getLayoutCommand());
    _levelPageWindow.set_ptrCommand(viewmodel->getLayoutCommand());
    _gameWindow.set_ptrPointChangeTrackingCommand(viewmodel->getMouseMoveCommand());
    _gameWindow.set_Martix(viewmodel->getSWMatrix());
    _formWindow.setMartix(viewmodel->getSWMatrix());

    viewmodel->AddPropertyNotification(_gameWindow.getPtrWindowProSink());
    viewmodel->AddCommandNotification(_gameWindow.getPtrNewLayoutSink());
    viewmodel->AddCommandNotification(_gameWindow.getPtrPointChangeTrackingSink());
    viewmodel->AddPropertyNotification(_gameWindow.getPtrGameCompleteSink());

    _spStartButtonCommand = std::make_shared<StartButtonCommand>(this);
    _spGameWindowCommand = std::make_shared<gameWindowCommand>(this);
    _spGameCompleteCommand = std::make_shared<gamecompletecommand>(this);
    _spGameAgainCommand = std::make_shared<gameAgainCommand>(this);
    _spTeamViewCommand = std::make_shared<teamViewCommand>(this);
    _spReturnStartPageCommand = std::make_shared<returnStartPageCommand>(this);

    _startpageWindow.set_ptrCommand(std::static_pointer_cast<ICommandBase>(this->_spStartButtonCommand));
    _startpageWindow.set_ptrTeamButtonCommand(std::static_pointer_cast<ICommandBase>(this->_spTeamViewCommand));
    _formWindow.setMenuCommand(std::static_pointer_cast<ICommandBase>(this->_spStartButtonCommand));
    _levelPageWindow.set_ptrOpenCommand(std::static_pointer_cast<ICommandBase>(this->_spGameWindowCommand));
    _gameWindow.set_ptrGameCompleteCommand(std::static_pointer_cast<ICommandBase>(this->_spGameCompleteCommand));
    _formWindow.setOpenCommand(std::static_pointer_cast<ICommandBase>(this->_spGameAgainCommand));
    _teamViewWindow.setStartPageCommand(std::static_pointer_cast<ICommandBase>(this->_spReturnStartPageCommand));
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

TeamView* GameAPP::getTeamView(){
    return &_teamViewWindow;
}

