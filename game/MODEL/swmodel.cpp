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
    if(level == 1){
        int row = 5;
        int col = 5;
        sp_SWMatrix->initialMatrix(row,col);
        for(int j=1;j<=col;j++){
            sp_SWMatrix->setMatrixPointColor(3,j,1);
        }
        sp_SWMatrix->setMatrixPointIsStart(row,1,1);
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
