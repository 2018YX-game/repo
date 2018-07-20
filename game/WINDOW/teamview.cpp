#include "teamview.h"
#include "ui_teamview.h"

TeamView::TeamView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamView)
{
    ui->setupUi(this);
}

TeamView::~TeamView()
{
    delete ui;
}

void TeamView::setStartPageCommand(std::shared_ptr<ICommandBase> ptr_startpage){
    _ptrStartPageCommand = ptr_startpage;
}

void TeamView::on_backButton_clicked()
{
    _ptrStartPageCommand->Exec();
}
