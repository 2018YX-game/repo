#ifndef APP_H
#define APP_H

#include "../MODEL/swmodel.h"
#include "../VIEWMODEL/swviewmodel.h"
#include "../WINDOW/gamewindow.h"
#include "../WINDOW/startpage.h"
#include "commands/startbuttoncommand.h"


class GameAPP
{
private:
    startpage _startpagewindow;
    gamewindow _gamewindow;
    std::shared_ptr<SWModel> model;
    std::shared_ptr<SWViewModel> viewmodel;

    std::shared_ptr<StartButtonCommand> sp_StartButtonCommand_;

public:
    GameAPP();
    ~GameAPP();
    void run();
    startpage* getStartPage();
    gamewindow* getGameWindow();
};


#endif // APP_H
