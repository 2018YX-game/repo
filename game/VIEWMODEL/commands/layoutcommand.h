#ifndef LAYOUTCOMMAND_H
#define LAYOUTCOMMAND_H

#include "../../common/etlbase.h"
//#include "../swviewmodel.h"

class SWViewModel;
class layoutCommand: public ICommandBase
{
public:
    layoutCommand(SWViewModel *ptr_SWViewModel);
    virtual void SetParameter(const _new_any_space_::any& param);
    virtual void Exec();

private:
    SWViewModel *ptr_SWViewModel_;
    int SWLevel;
};

#endif // LAYOUTCOMMAND_H
