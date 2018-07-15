#ifndef STARTPAGE_H
#define STARTPAGE_H
#include "gamewindow.h"
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
    ~startpage();

private slots:


    void on_startbutton_clicked();

    void on_quitbutton_clicked();

private:
    Ui::startpage *ui;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // STARTPAGE_H
