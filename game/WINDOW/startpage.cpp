#include "startpage.h"
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



void startpage::on_startbutton_clicked()
{

}

void startpage::on_quitbutton_clicked()
{

}
