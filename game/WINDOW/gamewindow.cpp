#include "gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    set_Martix(NULL);
}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::on_returntostartButton_clicked()
{

}
void gamewindow::set_Martix(std::shared_ptr<SWMatrix> spMartix){
    this->_spMartix=spMartix;
}
void gamewindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
/*    painter.setPen(QPen(Qt::blue,4));//设置画笔形式
    painter.drawLine(20,20,220,220);//画直线
    painter.drawLine(20,220,220,20);
    painter.drawEllipse(20,20,200,200);//画圆
    painter.drawRect(40,40,200,200);//画矩形
    */
    int col= this->_spMartix->getMatrixCol();
      int row= this->_spMartix->getMatrixRow();
  //  int col=5;int row=5;
       int i,j;
       for(i=0;i<row;i++){
           for(j=0;j<col;j++){
               painter.setPen(Qt::black);
               painter.setBrush(Qt::black);
               painter.drawEllipse(40+80*j,40+80*i,40,40);
           }
       }
}
