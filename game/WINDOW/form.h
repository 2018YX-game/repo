#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include"../common/etlbase.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void setMenuCommand(std::shared_ptr<ICommandBase> ptr_menu);
    void setNextCommand(std::shared_ptr<ICommandBase> ptr_next);
    void setAgainCommand(std::shared_ptr<ICommandBase> ptr_again);

private slots:
    void on_menuButton_clicked();
    void on_nextButton_clicked();
    void on_againButton_clicked();

private:
    Ui::Form *ui;
    std::shared_ptr<ICommandBase> ptr_menuCommand;
    std::shared_ptr<ICommandBase> ptr_nextCommand;
    std::shared_ptr<ICommandBase> ptr_againCommand;
};

#endif // FORM_H
