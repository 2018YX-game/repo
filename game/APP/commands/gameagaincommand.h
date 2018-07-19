#ifndef GAMEAGAINCOMMAND_H
#define GAMEAGAINCOMMAND_H


#include "../../common/etlbase.h"

class GameAPP;
class gameAgainCommand: public ICommandBase
{
private:
    GameAPP *ptrApp;
public:
    gameAgainCommand(GameAPP *ptr_App);
    ~gameAgainCommand();
    virtual void SetParameter(const _new_any_space_::any& param);
    virtual void Exec();
};

#endif // GAMEAGAINCOMMAND_H
