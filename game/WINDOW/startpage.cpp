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



void startpage::on_startbutton_clicked()
{
    //ui->close();
    gameui = new gamewindow();
    gameui->show();
}

void startpage::on_quitbutton_clicked()
{
    qApp->exit(0);
}
