#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include"../common/SWMatrix.h"
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
void paintEvent(QPaintEvent *);
private slots:
    void on_returntostartButton_clicked();

private:
    Ui::gamewindow *ui;
    std::shared_ptr<SWMatrix> _spMartix;
};

#endif // GAMEWINDOW_H
