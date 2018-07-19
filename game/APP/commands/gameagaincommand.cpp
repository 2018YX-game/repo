#include "gameagaincommand.h"
#include "../app.h"



 gameAgainCommand::gameAgainCommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}
gameAgainCommand::~gameAgainCommand()
{}
void gameAgainCommand::SetParameter(const _new_any_space_::any& param)
{}
void gameAgainCommand::Exec()
{
    (ptrApp->getFormWindow())->close();
    (ptrApp->getGameWindow())->show();
}
