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
#include "sinks/newlayoutcommandsink.h"
#include "sinks/mousemovecommandsink.h"
#include "sinks/gamecompletesink.h"

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
    std::shared_ptr<IPropertyNotification> getPtrWindowProSink(void);
    std::shared_ptr<ICommandNotification> getPtrWindowSetSink(void);
    std::shared_ptr<ICommandNotification> getPtrMouseMoveCommandSink(void);
    std::shared_ptr<IPropertyNotification> getPtrGameCompleteSink(void);
    void paintEvent(QPaintEvent *);
    void set_ptrMouseMoveCommand(std::shared_ptr<ICommandBase> ptrMouseMoveCommand);
    void set_ptrGameCompleteCommand(std::shared_ptr<ICommandBase> ptrGameCompleteCommand);
    void openForm();

 private:
    Ui::gamewindow *ui;
    std::shared_ptr<SWMatrix> _spMartix;
    std::shared_ptr<gamewindowProSink> _ptrgWindowPROSink;
    std::shared_ptr<mouseMoveCommandSink> _ptrMouseMoveCommandSink;
    std::shared_ptr<newLayoutCommandSink> _ptrnewLayoutCommandSink;
    std::shared_ptr<gameCompleteSink> _ptrGameCompleteSink;
    std::shared_ptr<ICommandBase> _ptrMouseMoveCommand;
    std::shared_ptr<ICommandBase> _ptrGameCompleteCommand;
};

#endif // GAMEWINDOW_H
