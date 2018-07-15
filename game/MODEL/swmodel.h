#ifndef SWMODEL_H
#define SWMODEL_H
#include "../common/SWMatrix.h"
#include <memory>
#include "../common/etlbase.h"

class SWModel: public Proxy_PropertyNotification<SWModel>
{
public:
    SWModel();
    ~SWModel();
    std::shared_ptr<SWMatrix> getSWMatrix();
    void newLayout(int level);

private:
    std::shared_ptr<SWMatrix> sp_SWMatrix;
};

#endif // SWMODEL_H
