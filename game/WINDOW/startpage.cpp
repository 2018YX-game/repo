#include "../WINDOW/startpage.h"
#include "ui_startpage.h"

startpage::startpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startpage)
{
    ui->setupUi(this);
}

startpage::~startpage()
{
    delete ui;
}


void startpage::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand){
    _ptrCommand=ptrCommand;
}

void startpage::on_startbutton_clicked()
{
    _ptrCommand->Exec();
}

void startpage::on_quitbutton_clicked()
{
    qApp->exit(0);
}
