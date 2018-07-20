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
#include "sinks/pointchangetrackingsink.h"
#include "sinks/gamecompletesink.h"

namespace Ui {
class gamewindow;
}

 class gamewindow : public QWidget
{
    Q_OBJECT

public:
     void mouseMoveEvent(QMouseEvent *e);
     void mouseReleaseEvent(QMouseEvent *e);
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();
    void set_Martix(std::shared_ptr<SWMatrix> spMartix);
    std::shared_ptr<IPropertyNotification> getPtrWindowProSink(void);
    std::shared_ptr<ICommandNotification> getPtrNewLayoutSink(void);
    std::shared_ptr<ICommandNotification> getPtrPointChangeTrackingSink(void);
    std::shared_ptr<IPropertyNotification> getPtrGameCompleteSink(void);
    void paintEvent(QPaintEvent *);
    void set_ptrPointChangeTrackingCommand(std::shared_ptr<ICommandBase> ptrPointChangeTrackingCommand);
    void set_ptrGameCompleteCommand(std::shared_ptr<ICommandBase> ptrGameCompleteCommand);
    void setGameAgainCommand(std::shared_ptr<ICommandBase> ptr_newgame);
    void openForm(const std::string& str);
    void setLabel(const std::string& str);

 private slots:
    void on_pushButton_clicked();


 private:
    Ui::gamewindow *ui;
    std::shared_ptr<SWMatrix> _spMartix;
    std::shared_ptr<gamewindowProSink> _ptrgWindowPROSink;
    std::shared_ptr<pointChangeTrackingSink> _ptrPointChangeTrackingSink;
    std::shared_ptr<newLayoutCommandSink> _ptrnewLayoutCommandSink;
    std::shared_ptr<gameCompleteSink> _ptrGameCompleteSink;
    std::shared_ptr<ICommandBase> _ptrPointChangeTrackingCommand;
    std::shared_ptr<ICommandBase> _ptrGameCompleteCommand;
    std::shared_ptr<ICommandBase> _ptrGameAgainCommand;
};

#endif // GAMEWINDOW_H
