#include "gamecompletecommand.h"
#include "../app.h"



 gamecompletecommand::gamecompletecommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}
gamecompletecommand::~gamecompletecommand()
{}
void gamecompletecommand::SetParameter(const _new_any_space_::any& param)
{}
void gamecompletecommand::Exec()
{
    (ptrApp->getGameWindow())->close();
    (ptrApp->getFormWindow())->show();
}
