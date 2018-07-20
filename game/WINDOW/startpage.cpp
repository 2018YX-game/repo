#include "../WINDOW/startpage.h"
#include "ui_startpage.h"

startpage::startpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startpage)
{
    ui->setupUi(this);
  //  this->resize(400, 300);
   // QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   // sizePolicy.setHorizontalStretch(0);
   // sizePolicy.setVerticalStretch(0);
   // sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
   // this->setSizePolicy(sizePolicy);
   // this->setMinimumSize(QSize(400, 300));
 //   this->setMaximumSize(QSize(400, 300));

    this->setWindowTitle(tr("The Same World"));//可执行程序标题
    this->setWindowIcon(QIcon("logo.ico"));//可执行程序图标
}

startpage::~startpage()
{
    delete ui;
}


void startpage::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand){
    _ptrCommand=ptrCommand;
}

void startpage::set_ptrTeamButtonCommand(std::shared_ptr<ICommandBase> ptrTeamButtonCommand){
    _ptrTeamButtonCommand=ptrTeamButtonCommand;
}

void startpage::on_startbutton_clicked()
{
    _ptrCommand->Exec();
}

void startpage::on_quitbutton_clicked()
{
    qApp->exit(0);
}

void startpage::on_teambutton_clicked()
{
    _ptrTeamButtonCommand->Exec();
}
