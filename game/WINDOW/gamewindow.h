#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

namespace Ui {
class gamewindow;
}

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();

private slots:
    void on_returntostartButton_clicked();

private:
    Ui::gamewindow *ui;
};

#endif // GAMEWINDOW_H
