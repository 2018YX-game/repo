#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include"memory"
#include <QWidget>
#include<qpainter.h>
#include "QMouseEvent"
#include "qdebug.h"
#include"../common/SWMatrix.h"
#include"../common/etlbase.h"
#include "sinks/gamewindowprosink.h"
#include "sinks/gamewindowsetsink.h"
#include "sinks/mousemovecommandSink.h"

namespace Ui {
class gamewindow;
}

 class gamewindow : public QWidget
{
    Q_OBJECT

public:
     void mouseMoveEvent(QMouseEvent *e);
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();
    void set_Martix(std::shared_ptr<SWMatrix> spMartix);
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);
    std::shared_ptr<IPropertyNotification> getPtrWindowProSink(void);
    std::shared_ptr<ICommandNotification> getPtrWindowSetSink(void);
    std::shared_ptr<ICommandNotification> getPtrMouseMoveCommandSink(void);
    void paintEvent(QPaintEvent *);
    void set_ptrMouseMoveCommand(std::shared_ptr<ICommandBase> ptrMouseMoveCommand);
private slots:


    void on_secondButton_clicked();

    void on_firstButton_clicked();

 private:
    Ui::gamewindow *ui;
    std::shared_ptr<SWMatrix> _spMartix;
    std::shared_ptr<gamewindowProSink> _ptrgWindowPROSink;
    std::shared_ptr<mouseMoveCommandSink> _ptrMouseMoveCommandSink;
    std::shared_ptr<gameWindowSetSink> _ptrWindowSetSink;
    std::shared_ptr<ICommandBase> _ptrMouseMoveCommand;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // GAMEWINDOW_H
