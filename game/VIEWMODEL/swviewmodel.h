#ifndef SWVIEWMODEL_H
#define SWVIEWMODEL_H

#include "../MODEL/swmodel.h"

class SWViewModelSink;
class SWViewModel:public Proxy_PropertyNotification<SWViewModel>
{
public:
    SWViewModel();
    ~SWViewModel();
    void setSWModel(std::shared_ptr<SWModel> sp_SWModel);
    std::shared_ptr<SWMatrix> getSWMatrix();

private:
    std::shared_ptr<SWModel> sp_SWModel_;
    std::shared_ptr<SWViewModelSink> sp_SWViewModelSink_;
};

#endif // SWVIEWMODEL_H
