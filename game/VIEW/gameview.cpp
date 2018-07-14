#include "gameview.h"
#include "ui_gameview.h"

gameView::gameView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameView)
{
    set_Martix(NULL);
    ui->setupUi(this);
    setMouseTracking(true);//设置鼠标可跟踪

}

gameView::~gameView()
{
    delete ui;
}
void gameView::set_Martix(std::shared_ptr<SWMatrix> spMartix){
    this->_spMartix=spMartix;
}
void gameView::paintEvent(QPaintEvent * event){
    QPainter painter(this);
   int col= this->_spMartix->getMatrixCol();
   int row= this->_spMartix->getMatrixRow();
 //  this->resize(QSize(col*100,row*50));
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            painter.setPen(Qt::black);
            painter.setBrush(Qt::black);
            painter.drawEllipse(20+40*j,20+60*i,40,40);
        }
    }


}
