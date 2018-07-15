#include "swviewmodelsink.h"

SWViewModelSink::SWViewModelSink(SWViewModel *ptr)
{
    ptr_SWViewModel = ptr;
}

virtual void OnPropertyChanged(const std::string& str){
    ptr_SWViewModel->Fire_OnPropertyChanged(str);
}
