#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include"../common/SWMatrix.h"
#include"../common/etlbase.h"
#include "sinks/gamewindowprosink.h"
#include "sinks/gamewindowsetsink.h"
#include"memory"
#include <QWidget>
#include<qpainter.h>
namespace Ui {
class gamewindow;
}

 class gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();
    void set_Martix(std::shared_ptr<SWMatrix> spMartix);
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);
    std::shared_ptr<IPropertyNotification> getPtrWindowProSink(void);
    std::shared_ptr<ICommandNotification> getPtrWindowSetSink(void);
    void paintEvent(QPaintEvent *);
private slots:


    void on_secondButton_clicked();

    void on_firstButton_clicked();

 private:
    Ui::gamewindow *ui;
    std::shared_ptr<SWMatrix> _spMartix;
    std::shared_ptr<gameWindowPROSink> _ptrgWindowPROSink;
    std::shared_ptr<gameWindowSETSink> _ptrWindowSetSink;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // GAMEWINDOW_H
