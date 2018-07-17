#include "mousemovecommand.h"
#include "../swviewmodel.h"

mouseMoveCommand::mouseMoveCommand(SWViewModel *ptr_SWViewModel)
{
    ptr_SWViewModel_ = ptr_SWViewModel;
}

void mouseMoveCommand::SetParameter(const _new_any_space_::any& param)
{
    mouseOnRow = 0;
    mouseOnCol = 0;
    std::string coor = _new_any_space_::any_cast<std::string>(param);
    int i = 0;
    while (i < coor.size()){
        if(coor[i] >= '0' && coor[i] <= '9'){
            if(mouseOnRow == 0)
                mouseOnRow = coor[i] - '0' + 0;
            else
                mouseOnCol = coor[i] - '0' + 0;
        }
        else if(coor[i] == ' '){
            ;
        }
        i++;
    }

    //mouseOnRow = _new_any_space_::any_cast<int>(param);
    //mouseOnCol = _new_any_space_::any_cast<int>(param);
}

void mouseMoveCommand::Exec()
{
    ptr_SWViewModel_->Exec_mouseMove_command(mouseOnRow,mouseOnCol);
    ptr_SWViewModel_->Fire_OnCommandComplete("mouseMoveCommand", true);
}
