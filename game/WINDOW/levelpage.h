#ifndef LEVELPAGE_H
#define LEVELPAGE_H

#include <QWidget>
#include"../common/etlbase.h"

namespace Ui {
class levelPage;
}

class levelPage : public QWidget
{
    Q_OBJECT

public:
    explicit levelPage(QWidget *parent = 0);
    ~levelPage();
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);
    void set_ptrOpenCommand(std::shared_ptr<ICommandBase> ptrCommand);
    void openGameWindow();

private slots:
    void on_level1_clicked();
    void on_level2_clicked();
    void on_level3_clicked();
    void on_level4_clicked();
    void on_level5_clicked();
    void on_level6_clicked();
    void on_level7_clicked();
    void on_level8_clicked();
    void on_level9_clicked();
    void on_level10_clicked();

private:
    Ui::levelPage *ui;
    int level;
    std::shared_ptr<ICommandBase> _ptrCommand;
    std::shared_ptr<ICommandBase> _ptrOpenCommand;
};

#endif // LEVELPAGE_H
