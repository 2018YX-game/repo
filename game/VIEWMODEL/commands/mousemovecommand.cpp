#include "mousemovecommand.h"
#include "../swviewmodel.h"

mouseMoveCommand::mouseMoveCommand(SWViewModel *ptr_SWViewModel)
{
    ptr_SWViewModel_ = ptr_SWViewModel;
}

void mouseMoveCommand::SetParameter(const _new_any_space_::any& param)
{
    mouseOnRow = _new_any_space_::any_cast<int>(param[0]);
    mouseOnCol = _new_any_space_::any_cast<int>(param[1]);
}

void mouseMoveCommand::Exec()
{
    ptr_SWViewModel_->Exec_mouseMove_command(mouseOnRow,mouseOnCol);
    ptr_SWViewModel_->Fire_OnCommandComplete("mouseMoveCommand", true);
}
