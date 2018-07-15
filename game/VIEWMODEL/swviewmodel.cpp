#include "swviewmodel.h"
#include "sinks/swviewmodelsink.h"

SWViewModel::SWViewModel(){
    sp_SWViewModelSink_ = std::make_shared<SWViewModelSink>(this);
}

void SWViewModel::setSWModel(std::shared_ptr<SWModel> sp_SWModel){
    sp_SWModel_ = sp_SWModel;
    sp_SWModel_->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(sp_SWViewModelSink_));
}

std::shared_ptr<SWMatrix> SWViewModel::getSWMatrix(){
    return sp_SWModel_->getSWMatrix();
}
