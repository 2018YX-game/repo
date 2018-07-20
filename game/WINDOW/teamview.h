#ifndef TEAMVIEW_H
#define TEAMVIEW_H

#include <QDialog>
#include"../common/etlbase.h"

namespace Ui {
class TeamView;
}

class TeamView : public QDialog
{
    Q_OBJECT

public:
    explicit TeamView(QWidget *parent = 0);
    ~TeamView();
    void setStartPageCommand(std::shared_ptr<ICommandBase> ptr_startpage);

private slots:

    void on_backButton_clicked();

    void on_contactButton_clicked();

private:
    Ui::TeamView *ui;
    std::shared_ptr<ICommandBase> _ptrStartPageCommand;
};

#endif // TEAMVIEW_H
