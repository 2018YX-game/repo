#ifndef STARTPAGE_H
#define STARTPAGE_H
#include "gamewindow.h"
#include "levelpage.h"
#include "teamview.h"
#include <QMainWindow>

namespace Ui {
class startpage;
}

class startpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit startpage(QWidget *parent = 0);
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);
    void set_ptrTeamButtonCommand(std::shared_ptr<ICommandBase> ptrTeamButtonCommand);
    ~startpage();

private slots:


    void on_startbutton_clicked();

    void on_quitbutton_clicked();

    void on_teambutton_clicked();

private:
    Ui::startpage *ui;
    std::shared_ptr<ICommandBase> _ptrTeamButtonCommand;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // STARTPAGE_H
