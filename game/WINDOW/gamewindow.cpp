#include "../WINDOW/gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    _ptrgWindowPROSink= std::make_shared<gameWindowPROSink>(gameWindowPROSink(this));
    _ptrWindowSetSink=std::make_shared<gameWindowSETSink>(gameWindowSETSink(this));
    set_Martix(NULL);
}
std::shared_ptr<IPropertyNotification> gamewindow::getPtrWindowProSink(void){

    return std::static_pointer_cast<IPropertyNotification>(_ptrgWindowPROSink);
}
std::shared_ptr<ICommandNotification> gamewindow::getPtrWindowSetSink(void){

    return std::static_pointer_cast<ICommandNotification>(_ptrWindowSetSink);
}

void gamewindow::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand){
    _ptrCommand=ptrCommand;
}



gamewindow::~gamewindow()
{
    delete ui;
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

      int col = this->_spMartix->getMatrixCol(); int row = this->_spMartix->getMatrixRow();

  //      int col=5;int row=5;

      painter.setBrush(Qt::blue);
      painter.drawRect(this->rect());
      int i, j;
      if(row==0&&col==0){
          ;
      }
      else{
    this->resize(100 + 80 * col, 100 + 80 * row);

      for (i = 0; i < row; i++) {
          for (j = 0; j < col; j++) {
  //  bool color =0;bool isStart=0;
  bool color=this->_spMartix->getMatrixPointColor(i+1,j+1); bool isStart=this->_spMartix->getMatrixPointIsStart(i+1,j+1);

              if(isStart==1){

              }
              else if (color==1){
                  painter.setPen(Qt::white);
                  painter.setBrush(Qt::white);
                  painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

              }
              else{
                  painter.setPen(Qt::black);
                  painter.setBrush(Qt::black);
                  painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

              }
            }
      }
      }
  }

void gamewindow::on_secondButton_clicked()
{

}

void gamewindow::on_firstButton_clicked()
{
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(1));
    _ptrCommand->Exec();
}
