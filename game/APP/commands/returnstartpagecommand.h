#ifndef RETURNSTARTPAGECOMMAND_H
#define RETURNSTARTPAGECOMMAND_H
#include "../../common/etlbase.h"

class GameAPP;
class returnStartPageCommand: public ICommandBase
{
public:
    returnStartPageCommand(GameAPP *ptr_App);
    ~returnStartPageCommand(){}
    virtual void SetParameter(const _new_any_space_::any& param){}
    virtual void Exec();

private:
    GameAPP *ptrApp;
};

#endif // RETURNSTARTPAGECOMMAND_H
