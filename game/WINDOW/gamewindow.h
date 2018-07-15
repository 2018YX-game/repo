#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include"SWMatrix.h"
#include"etlbase.h"
#include "sinks/gamewindowsink.h"
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
    std::shared_ptr<IPropertyNotification> getPtrWindowSink(void);
void paintEvent(QPaintEvent *);
private slots:
    void on_returntostartButton_clicked();

private:
    Ui::gamewindow *ui;
    std::shared_ptr<SWMatrix> _spMartix;
    std::shared_ptr<gameWindowSink> _ptrgWindowSink;
};

#endif // GAMEWINDOW_H
