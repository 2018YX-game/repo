#include "teamviewcommand.h"
#include "../app.h"

teamViewCommand::teamViewCommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}

void teamViewCommand::Exec()
{
    (ptrApp->getStartPage())->close();
    (ptrApp->getTeamView())->show();
}
