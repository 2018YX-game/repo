#include "swmodel.h"

SWModel::SWModel()
{
    sp_SWMatrix = std::make_shared<SWMatrix>();
}

std::shared_ptr<SWMatrix> SWModel::getSWMatrix(){
    return sp_SWMatrix;
}

void SWModel::newLayout(int row, int col){
    sp_SWMatrix->initialMatrix(row,col);
    for(int j=1;j<=col;j++){
        sp_SWMatrix->setMatrixPointColor(row,j);
    }
    sp_SWMatrix->setMatrixPointIsStart(row,1);
    Fire_OnPropertyChanged("SWMatrix");
}
