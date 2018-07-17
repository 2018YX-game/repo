#ifndef SWVIEWMODEL_H
#define SWVIEWMODEL_H

#include "../MODEL/swmodel.h"
#include "../common/etlbase.h"
#include "sinks/swviewmodelsink.h"
#include "commands/layoutcommand.h"
#include "commands/mousemovecommand.h"

class SWViewModel:public Proxy_PropertyNotification<SWViewModel>,
        public Proxy_CommandNotification<SWViewModel>
{
public:
    SWViewModel();
    ~SWViewModel(){}
    void setSWModel(std::shared_ptr<SWModel> sp_SWModel);
    std::shared_ptr<SWMatrix> getSWMatrix();
    std::shared_ptr<ICommandBase> getLayoutCommand();
    std::shared_ptr<ICommandBase> getMouseMoveCommand();
    void Exec_layout_command(int level);
    void Exec_mouseMove_command(int row, int col);

private:
    std::shared_ptr<SWModel> sp_SWModel_;
    std::shared_ptr<SWViewModelSink> sp_SWViewModelSink_;
    std::shared_ptr<layoutCommand> sp_layoutCommand_;
    std::shared_ptr<mouseMoveCommand> sp_mouseMoveCommand_;
};

#endif // SWVIEWMODEL_H
