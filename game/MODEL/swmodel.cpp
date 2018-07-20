#include "swmodel.h"
#include "Windows.h"
SWModel::SWModel()
{
    sp_SWMatrix = std::make_shared<SWMatrix>();
}

std::shared_ptr<SWMatrix> SWModel::getSWMatrix(){
    return sp_SWMatrix;
}

void SWModel::newLayout(int level)
{

    if(level == 1||level==11){
        int row = 5;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col,1);

        sp_SWMatrix->setMatrixPointIsExist(1,1,0);
        sp_SWMatrix->setMatrixPointIsExist(1,5,0);
        sp_SWMatrix->setMatrixPointIsExist(1,1,0);
        sp_SWMatrix->setMatrixPointIsExist(5,1,0);
        sp_SWMatrix->setMatrixPointIsExist(5,5,0);

        for(int j=1;j<=col;j++){
            sp_SWMatrix->setMatrixPointColor(3,j,1);
        }
        sp_SWMatrix->setMatrixPointIsStart(3,1,1);
        Fire_OnPropertyChanged("SWMatrix");
    }
   else if(level == 2){
        int row = 5;
        int col = 4;
        sp_SWMatrix->initialMatrix(row,col,2);
        for(int i=1;i<=row;i++){
            sp_SWMatrix->setMatrixPointColor(i,3,1);
        }
        for(int j=1;j<=col;j++){
            sp_SWMatrix->setMatrixPointColor(3,j,1);
        }
        sp_SWMatrix->setMatrixPointColor(3,3,0);
        sp_SWMatrix->setMatrixPointIsStart(1,3,1);
        sp_SWMatrix->setMatrixPointIsStart(3,4,1);
        Fire_OnPropertyChanged("SWMatrix");
    }
    else if(level==4){
        int row = 5;
        int col = 4;
        sp_SWMatrix->initialMatrix(row,col,4);

        sp_SWMatrix->setMatrixPointIsExist(1,2,0);
        sp_SWMatrix->setMatrixPointIsExist(1,3,0);
        sp_SWMatrix->setMatrixPointIsExist(1,4,0);
        sp_SWMatrix->setMatrixPointIsExist(5,1,0);
        sp_SWMatrix->setMatrixPointIsExist(5,2,0);
        sp_SWMatrix->setMatrixPointIsExist(5,3,0);

        sp_SWMatrix->setMatrixPointColor(2,1,1);
        sp_SWMatrix->setMatrixPointColor(3,2,1);
        sp_SWMatrix->setMatrixPointColor(3,3,1);
        sp_SWMatrix->setMatrixPointColor(4,4,1);
        sp_SWMatrix->setMatrixPointIsStart(2,1,1);
        sp_SWMatrix->setMatrixPointIsStart(4,4,1);

        Fire_OnPropertyChanged("SWMatrix");
    }
   else  if(level==5){
        int row = 5;
        int col = 4;
        sp_SWMatrix->initialMatrix(row,col,5);
        for(int j=1;j<=col;j++){
            sp_SWMatrix->setMatrixPointColor(2,j,1);
            sp_SWMatrix->setMatrixPointColor(4,j,1);
        }
        sp_SWMatrix->setMatrixPointIsStart(5,1,1);
        sp_SWMatrix->setMatrixPointIsStart(5,4,1);

        Fire_OnPropertyChanged("SWMatrix");
    }
    else if(level==3){
        int row = 6;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col,3);

        sp_SWMatrix->setMatrixPointColor(1,2,1);
        sp_SWMatrix->setMatrixPointColor(1,4,1);
        sp_SWMatrix->setMatrixPointColor(2,2,1);
        sp_SWMatrix->setMatrixPointColor(2,4,1);
        sp_SWMatrix->setMatrixPointColor(3,1,1);
        sp_SWMatrix->setMatrixPointColor(3,3,1);
        sp_SWMatrix->setMatrixPointColor(3,5,1);
        sp_SWMatrix->setMatrixPointColor(4,2,1);
        sp_SWMatrix->setMatrixPointColor(4,4,1);
        sp_SWMatrix->setMatrixPointColor(5,2,1);
        sp_SWMatrix->setMatrixPointColor(5,3,1);
        sp_SWMatrix->setMatrixPointColor(5,4,1);

        sp_SWMatrix->setMatrixPointIsStart(1,2,1);
        sp_SWMatrix->setMatrixPointIsStart(3,5,1);
        Fire_OnPropertyChanged("SWMatrix");
    }
    else if(level==6){
        int row = 6;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col,6);

        sp_SWMatrix->setMatrixPointIsExist(1,1,0);
        sp_SWMatrix->setMatrixPointIsExist(1,5,0);

        sp_SWMatrix->setMatrixPointColor(1,2,1);
        sp_SWMatrix->setMatrixPointColor(2,1,1);
        sp_SWMatrix->setMatrixPointColor(2,3,1);
        sp_SWMatrix->setMatrixPointColor(2,4,1);
        sp_SWMatrix->setMatrixPointColor(3,2,1);
        sp_SWMatrix->setMatrixPointColor(3,4,1);
        sp_SWMatrix->setMatrixPointColor(4,2,1);
        sp_SWMatrix->setMatrixPointColor(4,4,1);
        sp_SWMatrix->setMatrixPointColor(5,2,1);
        sp_SWMatrix->setMatrixPointColor(5,3,1);
        sp_SWMatrix->setMatrixPointColor(5,5,1);
        sp_SWMatrix->setMatrixPointColor(6,4,1);

        sp_SWMatrix->setMatrixPointIsStart(1,2,1);
        sp_SWMatrix->setMatrixPointIsStart(6,4,1);
        Fire_OnPropertyChanged("SWMatrix");
    }
   else  if(level==7){
        int row = 6;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col,7);

        for(int i=2;i<=5;i++){
            sp_SWMatrix->setMatrixPointColor(i,1,1);
            sp_SWMatrix->setMatrixPointColor(i,2,1);
            sp_SWMatrix->setMatrixPointColor(i,4,1);
            sp_SWMatrix->setMatrixPointColor(i,5,1);
        }

        sp_SWMatrix->setMatrixPointIsStart(6,1,1);
        sp_SWMatrix->setMatrixPointIsStart(6,5,1);
        Fire_OnPropertyChanged("SWMatrix");
    }
    else if(level==8){
        int row = 5;
        int col = 4;
        sp_SWMatrix->initialMatrix(row,col,8);

        sp_SWMatrix->setMatrixPointColor(1,1,1);
        sp_SWMatrix->setMatrixPointColor(2,1,1);
        sp_SWMatrix->setMatrixPointColor(4,1,1);
        sp_SWMatrix->setMatrixPointColor(5,1,1);
        sp_SWMatrix->setMatrixPointColor(1,3,1);
        sp_SWMatrix->setMatrixPointColor(5,3,1);

        sp_SWMatrix->setMatrixPointIsStart(1,2,1);
        sp_SWMatrix->setMatrixPointIsStart(3,4,1);
        sp_SWMatrix->setMatrixPointIsStart(5,2,1);

        Fire_OnPropertyChanged("SWMatrix");
    }
    else if(level==9){
        int row = 6;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col,9);

        sp_SWMatrix->setMatrixPointIsExist(1,1,0);
        sp_SWMatrix->setMatrixPointIsExist(1,2,0);
        sp_SWMatrix->setMatrixPointIsExist(1,4,0);
        sp_SWMatrix->setMatrixPointIsExist(1,5,0);

        sp_SWMatrix->setMatrixPointColor(2,2,1);
        sp_SWMatrix->setMatrixPointColor(2,4,1);
        sp_SWMatrix->setMatrixPointColor(3,2,1);
        sp_SWMatrix->setMatrixPointColor(3,4,1);
        sp_SWMatrix->setMatrixPointColor(4,1,1);
        sp_SWMatrix->setMatrixPointColor(4,2,1);
        sp_SWMatrix->setMatrixPointColor(4,4,1);
        sp_SWMatrix->setMatrixPointColor(4,5,1);
        sp_SWMatrix->setMatrixPointColor(5,1,1);
        sp_SWMatrix->setMatrixPointColor(5,5,1);
        sp_SWMatrix->setMatrixPointColor(6,1,1);
        sp_SWMatrix->setMatrixPointColor(6,2,1);
        sp_SWMatrix->setMatrixPointColor(6,4,1);
        sp_SWMatrix->setMatrixPointColor(6,5,1);

        sp_SWMatrix->setMatrixPointIsStart(1,3,1);
        sp_SWMatrix->setMatrixPointIsStart(6,3,1);

        Fire_OnPropertyChanged("SWMatrix");
    }
    else if(level==10){
        int row = 6;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col,10);

        sp_SWMatrix->setMatrixPointIsExist(1,4,0);
        sp_SWMatrix->setMatrixPointIsExist(1,5,0);
        sp_SWMatrix->setMatrixPointIsExist(2,4,0);
        sp_SWMatrix->setMatrixPointIsExist(2,5,0);
        sp_SWMatrix->setMatrixPointIsExist(5,1,0);
        sp_SWMatrix->setMatrixPointIsExist(5,2,0);
        sp_SWMatrix->setMatrixPointIsExist(6,1,0);
        sp_SWMatrix->setMatrixPointIsExist(6,2,0);

        sp_SWMatrix->setMatrixPointColor(1,1,1);
        sp_SWMatrix->setMatrixPointColor(2,1,1);
        sp_SWMatrix->setMatrixPointColor(2,2,1);
        sp_SWMatrix->setMatrixPointColor(3,2,1);
        sp_SWMatrix->setMatrixPointColor(4,4,1);
        sp_SWMatrix->setMatrixPointColor(5,4,1);
        sp_SWMatrix->setMatrixPointColor(5,5,1);
        sp_SWMatrix->setMatrixPointColor(6,5,1);


        sp_SWMatrix->setMatrixPointIsStart(1,1,1);
        sp_SWMatrix->setMatrixPointIsStart(6,4,1);

        Fire_OnPropertyChanged("SWMatrix");
    }

}


void SWModel::changePointColor(int curRow, int curCol){
    if(sp_SWMatrix->getMatrixPointColor(curRow,curCol)==0){
        sp_SWMatrix->setMatrixPointColor(curRow,curCol,1);
    }
    else{
        sp_SWMatrix->setMatrixPointColor(curRow,curCol,0);
    }
}

void SWModel::mouseMoveChange(int curRow, int curCol)
{
    if(curCol==0){
        if(sp_SWMatrix->isTrackNotNull()==0){
            return; //如果track为空，不做任何事
        }
complete:   std::vector<passPoint> track=sp_SWMatrix->getTrack();
        sp_SWMatrix->setMatrixPointIsStart( track[0].row,track[0].col,0);
        for(int i = 0; i < track.size(); i++){
            changePointColor(track[i].row,track[i].col);//翻转每个点的颜色
        }
        sp_SWMatrix->trackClear(); //清空track
        //检查逻辑
        int nrow = sp_SWMatrix->getMatrixRow();
        int ncol = sp_SWMatrix->getMatrixCol();
        bool flag = 0;
        int IsStart_flag =0;
        int curColor = -1;
        for(int i=1;i<=nrow;i++){
            for(int j=1;j<=ncol;j++){
                if(sp_SWMatrix->getMatrixPointIsExist(i,j)==0) continue;
            IsStart_flag+=sp_SWMatrix->getMatrixPointIsStart(i,j);
            if(curColor==-1)curColor=sp_SWMatrix->getMatrixPointColor(i,j);
            if(curColor!=sp_SWMatrix->getMatrixPointColor(i,j)) flag=1;
            }
        }

            if(IsStart_flag==0){
                Fire_OnPropertyChanged("SWMatrix");
//                Sleep(1000);
                if(!flag)  Fire_OnPropertyChanged("GameComplete");
                else  Fire_OnPropertyChanged("GameFailed");
            }
            return ;
        }
    else if(sp_SWMatrix->isTrackNotNull()==0){
        if(sp_SWMatrix->getMatrixPointIsStart(curRow,curCol))
            sp_SWMatrix->setTrackFront(curRow,curCol); //如果是起点，记录起点
        return ; //不是起点，do nothing
    }
    else if(sp_SWMatrix->getLastPointofTrack().row==curRow&&sp_SWMatrix->getLastPointofTrack().col==curCol){
        ;//停留在当前点，do nothing
    }

    else{
        passPoint lastpoint=sp_SWMatrix->getLastPointofTrack();
        int delta_row = curRow - lastpoint.row;
        int delta_col = curCol - lastpoint.col;
        if((delta_row==0 && delta_col==1)||(delta_row==0 && delta_col==-1)
                ||(delta_row==-1 && delta_col==0)||(delta_row==1 && delta_col==0)){
            if(sp_SWMatrix->getMatrixPointIsExist(curRow,curCol)==0) return ;
            if(sp_SWMatrix->isPassOn(curRow,curCol)){
               passPoint secondlastpoint = sp_SWMatrix->getSecondLastPointofTrack();
               if(secondlastpoint.col==0){
                   ;
               }
               else if(secondlastpoint.col=curCol&&secondlastpoint.row==curRow){
                   sp_SWMatrix->setTrackBack();
                   return ;
               }
               else{
                return;
               }
            }
        sp_SWMatrix->setTrackFront(curRow,curCol);//纪录新点
        }
        else if(sp_SWMatrix->isPassOn(curRow,curCol)){
            ;
        }
        else{//其他情况，本次连线结束
       //     goto complete;
        }
    }
    Fire_OnPropertyChanged("SWMatrix");
}
