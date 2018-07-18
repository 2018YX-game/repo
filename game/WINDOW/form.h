#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include"../common/etlbase.h"
#include"../common/SWMatrix.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void setMartix(std::shared_ptr<SWMatrix> spMartix);
    void setMenuCommand(std::shared_ptr<ICommandBase> ptr_menu);
    void setOpenCommand(std::shared_ptr<ICommandBase> ptr_open);
    void setNewGameCommand(std::shared_ptr<ICommandBase> ptr_newgame);

private slots:
    void on_menuButton_clicked();
    void on_nextButton_clicked();
    void on_againButton_clicked();

private:
    Ui::Form *ui;
    int level;
    std::shared_ptr<SWMatrix> _spMartix;
    std::shared_ptr<ICommandBase> ptr_newGameCommand;
    std::shared_ptr<ICommandBase> ptr_menuCommand;
    std::shared_ptr<ICommandBase> ptr_openCommand;
};

#endif // FORM_H
