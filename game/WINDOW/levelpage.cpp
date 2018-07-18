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
    _ptrCommand=ptrCommand;
}

int levelPage::getLevel(){
    return level;
}

void levelPage::on_level1_clicked(){
    level = 1;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level2_clicked(){
    level = 2;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level3_clicked(){
    level = 3;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level4_clicked(){
    level = 4;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level5_clicked(){
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(5));
    _ptrCommand->Exec();
}

void levelPage::on_level6_clicked(){
    level = 6;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level7_clicked(){
    level = 7;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level8_clicked(){
    level = 8;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level9_clicked(){
    level = 9;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}

void levelPage::on_level10_clicked(){
    level = 10;
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(level));
    _ptrCommand->Exec();
}
