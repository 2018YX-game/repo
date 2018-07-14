#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "memory.h"
#include "SWMatrix.h"
#include <QWidget>
#include<qpainter.h>
#include <QtUiPlugin/QDesignerExportWidget>
namespace Ui {
class gameView;
}

class QDESIGNER_WIDGET_EXPORT gameView : public QWidget
{
private:
    Q_OBJECT;
    QPainter *painter;
    Ui::gameView *ui;
    std::shared_ptr<SWMatrix> _spMartix;
public:
    explicit gameView(QWidget *parent = 0);
    ~gameView();
void set_Martix(std::shared_ptr<SWMatrix> spMartix);
    void  paintEvent(QPaintEvent *event);


};

#endif // GAMEVIEW_H
