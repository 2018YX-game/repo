#ifndef SWVIEWMODEL_H
#define SWVIEWMODEL_H

#include "../MODEL/swmodel.h"
#include "../common/etlbase.h"

class SWViewModelSink;
class layoutCommand;
class SWViewModel:public Proxy_PropertyNotification<SWViewModel>, public Proxy_CommandNotification<SWViewModel>
{
public:
    SWViewModel();
    ~SWViewModel();
    void setSWModel(std::shared_ptr<SWModel> sp_SWModel);
    std::shared_ptr<SWMatrix> getSWMatrix();
    void Exec_layout_command(int level);

private:
    std::shared_ptr<SWModel> sp_SWModel_;
    std::shared_ptr<SWViewModelSink> sp_SWViewModelSink_;
    std::shared_ptr<layoutCommand> sp_layoutCommand_;
};

#endif // SWVIEWMODEL_H
