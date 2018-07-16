#ifndef APP_H
#define APP_H
#include "../MODEL/swmodel.h"
#include "../VIEWMODEL/swviewmodel.h"
#include "../WINDOW/gamewindow.h"
#include "../WINDOW/startpage.h"


class APP
{
private:
    startpage window1;
    gamewindow window2;
    std::shared_ptr<SWModel> model;
    std::shared_ptr<SWViewModel> viewmodel;
public:
    APP();
    void run();
};


#endif // APP_H
