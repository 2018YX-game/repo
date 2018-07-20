#include "teamview.h"
#include "ui_teamview.h"
#include <QDesktopServices>
#include <QUrl>

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

void TeamView::on_contactButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/2018YX-game/repo")));
}
