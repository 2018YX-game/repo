#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setMartix(std::shared_ptr<SWMatrix> spMartix){
    _spMartix = spMartix;
}

void Form::setMenuCommand(std::shared_ptr<ICommandBase> ptr_menu){
    ptr_menuCommand = ptr_menu;
}

void Form::setOpenCommand(std::shared_ptr<ICommandBase> ptr_open){
    ptr_openCommand = ptr_open;
}

void Form::setNewGameCommand(std::shared_ptr<ICommandBase> ptr_newgame){
    ptr_newGameCommand = ptr_newgame;
}

void Form::on_menuButton_clicked(){
    ptr_menuCommand->Exec();
}

void Form::on_nextButton_clicked(){
    int level = 1+ _spMartix->getMatrixLevel();
    ptr_newGameCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    ptr_newGameCommand->Exec();
    ptr_openCommand->Exec();
}

void Form::on_againButton_clicked(){
    int level = _spMartix->getMatrixLevel();
    ptr_newGameCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    ptr_newGameCommand->Exec();
    ptr_openCommand->Exec();
}

void Form::setLabel(const std::string& str){
    if(str == "GameComplete"){
        ui->output->setText("Succeed!");
    }
    else if(str == "GameFailed"){
        ui->output->setText("Fail!");
    }
}
