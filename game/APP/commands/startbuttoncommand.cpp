#include "startbuttoncommand.h"
#include "../app.h"

StartButtonCommand::StartButtonCommand(GameAPP *ptr_App)
{
    ptrApp = ptr_App;
}
StartButtonCommand::~StartButtonCommand()
{}
void StartButtonCommand::SetParameter(const _new_any_space_::any& param)
{}
void StartButtonCommand::Exec()
{
    ptrApp->window1.close();
    ptrApp->window2.show();
}
