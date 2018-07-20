#include "../WINDOW/gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    _ptrgWindowPROSink= std::make_shared<gamewindowProSink>(gamewindowProSink(this));
    _ptrnewLayoutCommandSink=std::make_shared<newLayoutCommandSink>(newLayoutCommandSink(this));
    _ptrPointChangeTrackingSink=std::make_shared<pointChangeTrackingSink>(pointChangeTrackingSink(this));
    _ptrGameCompleteSink=std::make_shared<gameCompleteSink>(gameCompleteSink(this));
    set_Martix(NULL);
}


std::shared_ptr<IPropertyNotification> gamewindow::getPtrWindowProSink(void){

    return std::static_pointer_cast<IPropertyNotification>(_ptrgWindowPROSink);
}

std::shared_ptr<ICommandNotification> gamewindow::getPtrNewLayoutSink(void){

    return std::static_pointer_cast<ICommandNotification>(_ptrnewLayoutCommandSink);
}

std::shared_ptr<ICommandNotification> gamewindow::getPtrPointChangeTrackingSink(void){
     return std::static_pointer_cast<ICommandNotification>(_ptrPointChangeTrackingSink);
}

std::shared_ptr<IPropertyNotification> gamewindow::getPtrGameCompleteSink(void){
     return std::static_pointer_cast<IPropertyNotification>(_ptrGameCompleteSink);
}

void gamewindow::set_ptrPointChangeTrackingCommand(std::shared_ptr<ICommandBase> ptrPointChangeTrackingCommand){
    _ptrPointChangeTrackingCommand = ptrPointChangeTrackingCommand;
}

void gamewindow::set_ptrGameCompleteCommand(std::shared_ptr<ICommandBase> ptrGameCompleteCommand){
    _ptrGameCompleteCommand = ptrGameCompleteCommand;
}

void gamewindow::openForm(const std::string& str){
    _ptrGameCompleteCommand->SetParameter(_new_any_space_::any_cast<std::string>(str));
    _ptrGameCompleteCommand->Exec();
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


      int col = this->_spMartix->getMatrixCol();
      int row = this->_spMartix->getMatrixRow();

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
              bool isExist=this->_spMartix->getMatrixPointIsExist(i+1,j+1);

              if(isExist == 1){
                  if(isStart==1){
                      if(color==1){
                          QPen pen;
                          pen.setWidth(7);
                          pen.setBrush(QColor(0, 160, 230));
                          painter.setPen(pen);
                          painter.setBrush(Qt::white);
                          painter.setRenderHint(QPainter::Antialiasing, true);
                          painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

                      }
                      else {
                          QPen pen;
                          pen.setWidth(7);
                          pen.setBrush(QColor(0, 160, 230));
                          painter.setPen(pen);
                          painter.setBrush(Qt::black);
                          painter.setRenderHint(QPainter::Antialiasing, true);
                          painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

                      }
                  }
                  else if (color==1){
                      painter.setPen(Qt::white);
                      painter.setBrush(Qt::white);
                      painter.setRenderHint(QPainter::Antialiasing, true);
                      painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

                  }
                  else{
                      painter.setPen(Qt::black);
                      painter.setBrush(Qt::black);
                      painter.setRenderHint(QPainter::Antialiasing, true);
                      painter.drawEllipse(40 + 80 * j, 40 + 80 * i, 40, 40);

                  }
              }
              else{
                  ;
              }

              }
          }
          //画出经过的轨迹
          painter.setPen(QPen(QColor(178, 58, 238),5));
          painter.setRenderHint(QPainter::Antialiasing, true);
          for(int i=0;i<this->_spMartix->getTrackSize()-1;i++){
              int start_x = (this->_spMartix->getTrack()[i].row-1)*80+60;
              int start_y = (this->_spMartix->getTrack()[i].col-1)*80+60;
              int end_x = (this->_spMartix->getTrack()[i+1].row-1)*80+60;
              int end_y = (this->_spMartix->getTrack()[i+1].col-1)*80+60;
              painter.drawLine(QPointF(start_y,start_x),QPointF(end_y,end_x));
          }
          for(int i=0;i<this->_spMartix->getTrackSize();i++){
              QPen pen;
              bool color=this->_spMartix->getMatrixPointColor(this->_spMartix->getTrack()[i].row,this->_spMartix->getTrack()[i].col);

              pen.setWidth(7);
              pen.setBrush(QColor(178, 58, 238));
              painter.setPen(pen);
              painter.setBrush(Qt::white);

              if(color)
                  painter.setBrush(Qt::white);
              else
                  painter.setBrush(Qt::black);

              painter.setRenderHint(QPainter::Antialiasing, true);
              painter.drawEllipse(40 + 80 * (this->_spMartix->getTrack()[i].col-1), 40 + 80 * (this->_spMartix->getTrack()[i].row-1), 40, 40);
          }

      }
}


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
            _ptrPointChangeTrackingCommand->SetParameter(_new_any_space_::any_cast<std::string>(a));
            _ptrPointChangeTrackingCommand->Exec();
            gamewindow::update();
        }
        else{
            ;
        }
    }
}

void gamewindow::mouseReleaseEvent(QMouseEvent *e){
    qDebug()<<0<<0;
    std::string a=std::to_string(0)+" "+std::to_string(0);
    _ptrPointChangeTrackingCommand->SetParameter(_new_any_space_::any_cast<std::string>(a));
    _ptrPointChangeTrackingCommand->Exec();
    gamewindow::update();
}
