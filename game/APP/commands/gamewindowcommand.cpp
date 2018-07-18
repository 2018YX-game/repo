#include "gamewndowcommand.h"
#include "../app.h"

gameWindowCommand::gameWindowCommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}
gameWindowCommand::~gameWindowCommand()
{}
void gameWindowCommand::SetParameter(const _new_any_space_::any& param)
{}
void gameWindowCommand::Exec()
{
    (ptrApp->getLevelPageWindow())->close();
    (ptrApp->getGameWindow())->show();
}
