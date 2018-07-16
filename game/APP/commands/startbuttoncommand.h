#ifndef STARTBUTTONCOMMAND_H
#define STARTBUTTONCOMMAND_H
#include "../../common/etlbase.h"

class GameAPP;
class StartButtonCommand: public ICommandBase
{
private:
    GameAPP *ptrApp;
public:
    StartButtonCommand(GameAPP *ptr_App);
    ~StartButtonCommand();
    virtual void SetParameter(const _new_any_space_::any& param);
    virtual void Exec();
};


#endif // STARTBUTTONCOMMAND_H
