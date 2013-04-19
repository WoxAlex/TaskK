#ifndef ITABLEREADER_H
#define ITABLEREADER_H

#include "icellstorage.h"
class ITableReader
{
public:
    ITableReader();
    virtual void ReadTable() = 0;
    virtual void ComputeTable() = 0;
    virtual std::shared_ptr<ICellStorage> GetTable() = 0;
    virtual ~ITableReader();

};

#endif // ITABLEREADER_H
