#include "returnstartpagecommand.h"
#include "../app.h"

returnStartPageCommand::returnStartPageCommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}

void returnStartPageCommand::Exec()
{
    (ptrApp->getTeamView())->close();
    (ptrApp->getStartPage())->show();
}
