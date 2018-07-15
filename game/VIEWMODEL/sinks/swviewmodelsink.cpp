#include "swviewmodelsink.h"
#include "../swviewmodel.h"

SWViewModelSink::SWViewModelSink(SWViewModel *ptr)
{
    ptr_SWViewModel = ptr;
}

void SWViewModelSink::OnPropertyChanged(const std::string& str){
    ptr_SWViewModel->Fire_OnPropertyChanged(str);
}
