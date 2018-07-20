#ifndef TEAMVIEWCOMMAND_H
#define TEAMVIEWCOMMAND_H
#include "../../common/etlbase.h"

class GameAPP;
class teamViewCommand: public ICommandBase
{
public:
    teamViewCommand(GameAPP *ptr_App);
    ~teamViewCommand(){}
    virtual void SetParameter(const _new_any_space_::any& param){}
    virtual void Exec();

private:
    GameAPP *ptrApp;
};

#endif // TEAMVIEWCOMMAND_H
