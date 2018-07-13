#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QMainWindow>

namespace Ui {
class startpage;
}

class startpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit startpage(QWidget *parent = 0);
    ~startpage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::startpage *ui;
};

#endif // STARTPAGE_H
