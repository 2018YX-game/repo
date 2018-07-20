#ifndef APP_H
#define APP_H


#include "../MODEL/swmodel.h"
#include "../VIEWMODEL/swviewmodel.h"
#include "../WINDOW/gamewindow.h"
#include "../WINDOW/startpage.h"
#include "../WINDOW/form.h"
#include "../WINDOW/levelpage.h"
#include "../WINDOW/teamview.h"
#include "commands/startbuttoncommand.h"
#include "commands/gamewindowcommand.h"
#include "commands/gamecompletecommand.h"
#include "commands/gameagaincommand.h"
#include "commands/teamviewcommand.h"
#include "commands/returnstartpagecommand.h"

class GameAPP
{
private:
    startpage _startpageWindow;
    Form _formWindow;
    levelPage _levelPageWindow;
    gamewindow _gameWindow;
    TeamView _teamViewWindow;
    std::shared_ptr<SWModel> model;
    std::shared_ptr<SWViewModel> viewmodel;
    std::shared_ptr<gameAgainCommand> _spGameAgainCommand;
    std::shared_ptr<gamecompletecommand> _spGameCompleteCommand;
    std::shared_ptr<StartButtonCommand> _spStartButtonCommand;
    std::shared_ptr<gameWindowCommand> _spGameWindowCommand;
    std::shared_ptr<teamViewCommand> _spTeamViewCommand;
    std::shared_ptr<returnStartPageCommand> _spReturnStartPageCommand;

public:
    GameAPP();
    ~GameAPP();
    void run();
    startpage* getStartPage();
    gamewindow* getGameWindow();
    Form* getFormWindow();
    levelPage* getLevelPageWindow();
    TeamView* getTeamView();
};


#endif // APP_H
