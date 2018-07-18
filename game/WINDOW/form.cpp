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

void Form::setMenuCommand(std::shared_ptr<ICommandBase> ptr_menu){
    ptr_menuCommand = ptr_menu;
}

void Form::setNextCommand(std::shared_ptr<ICommandBase> ptr_next){
    ptr_nextCommand = ptr_next;
}

void Form::setAgainCommand(std::shared_ptr<ICommandBase> ptr_again){
    ptr_againCommand = ptr_again;
}


void Form::on_menuButton_clicked(){
    ptr_menuCommand->Exec();
}

void Form::on_nextButton_clicked(){
    ptr_nextCommand->Exec();
}

void Form::on_againButton_clicked(){
    ptr_againCommand->Exec();
}
