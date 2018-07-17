#include "swmodel.h"

SWModel::SWModel()
{
    sp_SWMatrix = std::make_shared<SWMatrix>();
}

std::shared_ptr<SWMatrix> SWModel::getSWMatrix(){
    return sp_SWMatrix;
}

void SWModel::newLayout(int level)
{
    lastRow = 0;
    lastCol = 0;
    if(level == 1){
        int row = 5;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col);
        for(int j=1;j<=col;j++){
            sp_SWMatrix->setMatrixPointColor(3,j,1);
        }
        sp_SWMatrix->setMatrixPointIsStart(3,1,1);
        Fire_OnPropertyChanged("SWMatrix");
    }
    if(level == 2){
        int row = 5;
        int col = 4;
        sp_SWMatrix->initialMatrix(row,col);
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
}

void SWModel::mouseMoveChange(int curRow, int curCol)
{

    int cur_IsStart = sp_SWMatrix->getMatrixPointIsStart(curRow,curCol);
    bool cur_IsMoveOn = sp_SWMatrix->getMatrixPointIsMoveOn(curRow,curCol);





    if(lastRow==0 && lastCol==0){
        if(cur_IsStart){
            lastRow = curRow;
            lastCol = curCol;
            sp_SWMatrix->setMatrixPointIsMoveOn(curRow,curCol,1);
        }
    }




    else if(curRow==lastRow && curCol==lastCol){
        int nrow = sp_SWMatrix->getMatrixRow();
        int ncol = sp_SWMatrix->getMatrixCol();
        bool curColor = sp_SWMatrix->getMatrixPointColor(curRow,curCol);
        bool flag = 0;
        for(int i=1; i<=nrow; i++){
            for(int j=1;j<=ncol;j++){
                if(i!=curRow || j!=curCol){
                    bool tempColor = sp_SWMatrix->getMatrixPointColor(i,j);
                    if(tempColor == curColor){
                        flag =1;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            if(curColor==0){
                sp_SWMatrix->setMatrixPointColor(curRow,curCol,1);
            }
            else{
                sp_SWMatrix->setMatrixPointColor(curRow,curCol,0);
            }
            sp_SWMatrix->setMatrixPointIsStart(lastRow,lastCol,0);
        }
    }







    else if(curRow!=lastRow || curCol!=lastCol){
        int delta_row = curRow - lastRow;
        int delta_col = curCol - lastCol;
         int last_IsStart = sp_SWMatrix->getMatrixPointIsStart(lastRow,lastCol);
        if(!cur_IsMoveOn){




            if((delta_row==0 && delta_col==1)||(delta_row==0 && delta_col==-1)||(delta_row==-1 && delta_col==0)||(delta_row==1 && delta_col==0)){
                sp_SWMatrix->setMatrixPointIsStart(curRow,curCol,1);
                sp_SWMatrix->setMatrixPointIsStart(lastRow,lastCol,0);
                sp_SWMatrix->setMatrixPointIsMoveOn(curRow,curCol,1);
                if(sp_SWMatrix->getMatrixPointColor(lastRow,lastCol)==0){
                    sp_SWMatrix->setMatrixPointColor(lastRow,lastCol,1);
                }
                else{
                    sp_SWMatrix->setMatrixPointColor(lastRow,lastCol,0);
                }
                lastRow = curRow;
                lastCol = curCol;
            }




            else if(cur_IsStart){
                int nrow = sp_SWMatrix->getMatrixRow();
                int ncol = sp_SWMatrix->getMatrixCol();
                for(int i=1; i<=nrow; i++){
                    for(int j=1;j<=ncol;j++){
                        sp_SWMatrix->setMatrixPointIsMoveOn(i,j,0);
                    }
                }
            sp_SWMatrix->setMatrixPointIsMoveOn(3,3,0);
                sp_SWMatrix->setMatrixPointIsStart(lastRow,lastCol,0);
                sp_SWMatrix->setMatrixPointIsMoveOn(curRow,curCol,1);

                if(sp_SWMatrix->getMatrixPointColor(lastRow,lastCol)==0){
                    sp_SWMatrix->setMatrixPointColor(lastRow,lastCol,1);
                }
                else{
                    sp_SWMatrix->setMatrixPointColor(lastRow,lastCol,0);
                }
                lastRow = curRow;
                lastCol = curCol;
            }




            else{
    ;
            }




        }





        else{
            ;
        }
    }




    else{
        ;
    }




    Fire_OnPropertyChanged("SWMatrix");
}
