#include "gamecompletecommand.h"
#include "../app.h"



 gamecompletecommand::gamecompletecommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}
gamecompletecommand::~gamecompletecommand()
{}
void gamecompletecommand::SetParameter(const _new_any_space_::any& param)
{
    _str=_new_any_space_::any_cast<std::string>(param);
}
void gamecompletecommand::Exec()
{
    (ptrApp->getGameWindow())->repaint();
    Sleep(500);
    (ptrApp->getGameWindow())->close();
    (ptrApp->getFormWindow())->show();
     (ptrApp->getFormWindow())->setLabel(_str);
}
