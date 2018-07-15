#include "layoutcommand.h"
#include "../swviewmodel.h"

layoutCommand::layoutCommand(SWViewModel *ptr_SWViewModel)
{
    ptr_SWViewModel_ = ptr_SWViewModel;
}

void layoutCommand::SetParameter(const _new_any_space_::any& param)
{
    SWLevel = _new_any_space_::any_cast<int>(param);
}

void layoutCommand::Exec()
{
    ptr_SWViewModel_->Exec_layout_command(SWLevel);
}
