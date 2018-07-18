#include "../WINDOW/gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    _ptrgWindowPROSink= std::make_shared<gamewindowProSink>(gamewindowProSink(this));
    _ptrnewLayoutCommandSink=std::make_shared<newLayoutCommandSink>(newLayoutCommandSink(this));
    _ptrMouseMoveCommandSink=std::make_shared<mouseMoveCommandSink>(mouseMoveCommandSink(this));
    set_Martix(NULL);
}
std::shared_ptr<IPropertyNotification> gamewindow::getPtrWindowProSink(void){

    return std::static_pointer_cast<IPropertyNotification>(_ptrgWindowPROSink);
}
std::shared_ptr<ICommandNotification> gamewindow::getPtrWindowSetSink(void){

    return std::static_pointer_cast<ICommandNotification>(_ptrnewLayoutCommandSink);
}
std::shared_ptr<ICommandNotification> gamewindow::getPtrMouseMoveCommandSink(void){
     return std::static_pointer_cast<ICommandNotification>(_ptrMouseMoveCommandSink);
}

/*void gamewindow::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand){
    _ptrCommand=ptrCommand;
}*/
void gamewindow::set_ptrMouseMoveCommand(std::shared_ptr<ICommandBase> ptrMouseMoveCommand){
    _ptrMouseMoveCommand=ptrMouseMoveCommand;
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


      int col = this->_spMartix->getMatrixCol(); int row = this->_spMartix->getMatrixRow();

      painter.setBrush(Qt::gray);
      painter.drawRect(this->rect());
      int i, j;
      if(row==0&&col==0){
          ;
      }
      else{
    this->resize(60 + 80 * col, 60 + 80 * row);

      for (i = 0; i < row; i++) {
          for (j = 0; j < col; j++) {

  bool color=this->_spMartix->getMatrixPointColor(i+1,j+1);
  bool isStart=this->_spMartix->getMatrixPointIsStart(i+1,j+1);

              if(isStart==1){
                  if(color==1){
                      QPen pen;
                      pen.setWidth(7);
                      pen.setBrush(Qt::black);
                      painter.setPen(pen);
                      painter.setBrush(Qt::white);
                      painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

                  }
                  else {
                      QPen pen;
                      pen.setWidth(7);
                      pen.setBrush(Qt::white);
                      painter.setPen(pen);
                      painter.setBrush(Qt::black);
                      painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

                  }
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

/*void gamewindow::on_secondButton_clicked()
{
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(2));
    _ptrCommand->Exec();
}

void gamewindow::on_firstButton_clicked()
{
    _ptrCommand->SetParameter(_new_any_space_::any_cast<int>(1));
    _ptrCommand->Exec();
}*/
void gamewindow::mouseMoveEvent(QMouseEvent *e){
 //   e->x();
    e->accept();
    QPoint p=e->pos();
    int x=p.x();
    int y=p.y();
    int col1 = this->_spMartix->getMatrixCol();
    int row1 = this->_spMartix->getMatrixRow();

//    qDebug()<<x<<y;
    if(x>=40&&y>=40){
        int row =(y-40)/ 80+1;
        int col=(x-40)/80+1;
        if(row>row1||col>col1){
            ;
        }
        else if((y-row*80-40)<=40&&(x-col*80-40)<=40){
            qDebug()<<row<<col;
                std::string a=std::to_string(row)+" "+std::to_string(col);
           _ptrMouseMoveCommand->SetParameter(_new_any_space_::any_cast<std::string>(a));
              _ptrMouseMoveCommand->Exec();
              gamewindow::update();
        }
        else{
            ;
        }
    }
}
