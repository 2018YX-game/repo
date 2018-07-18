#include "levelpage.h"
#include "ui_levelpage.h"

levelPage::levelPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levelPage)
{
    ui->setupUi(this);
    level = 0;
}

levelPage::~levelPage()
{
    delete ui;
}

void levelPage::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand){
    _ptrCommand = ptrCommand;
}

void levelPage::set_ptrOpenCommand(std::shared_ptr<ICommandBase> ptrCommand){
    _ptrOpenCommand = ptrCommand;
}

void levelPage::openGameWindow(){
    _ptrOpenCommand->Exec();
}

void levelPage::on_level1_clicked(){
    openGameWindow();
    level = 1;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level2_clicked(){
    openGameWindow();
    level = 2;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level3_clicked(){
    openGameWindow();
    level = 3;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level4_clicked(){
    openGameWindow();
    level = 4;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level5_clicked(){
    openGameWindow();
    level = 5;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level6_clicked(){
    openGameWindow();
    level = 6;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level7_clicked(){
    openGameWindow();
    level = 7;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level8_clicked(){
    openGameWindow();
    level = 8;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level9_clicked(){
    openGameWindow();
    level = 9;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level10_clicked(){
    openGameWindow();
    level = 10;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}
