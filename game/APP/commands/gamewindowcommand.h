#ifndef GAMEWINDOWCOMMAND_H
#define GAMEWINDOWCOMMAND_H
#include "../../common/etlbase.h"

class GameAPP;
class gameWindowCommand: public ICommandBase
{
private:
    GameAPP *ptrApp;
public:
    gameWindowCommand(GameAPP *ptr_App);
    ~gameWindowCommand();
    virtual void SetParameter(const _new_any_space_::any& param);
    virtual void Exec();
};

#endif // GAMEWNDOWCOMMAND_H
