#include "swviewmodelsink.h"
#include "../swviewmodel.h"

SWViewModelSink::SWViewModelSink(SWViewModel *ptr)
{
    ptr_SWViewModel = ptr;
}

virtual void SWViewModelSink::OnPropertyChanged(const std::string& str){
    ptr_SWViewModel->Fire_OnPropertyChanged(str);
}
