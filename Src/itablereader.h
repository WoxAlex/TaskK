#ifndef ITABLEREADER_H
#define ITABLEREADER_H

#include "icellstorage.h"
class ITableReader
{
public:
    ITableReader();
    virtual void ReadTable(ICellStorage& table) = 0;
    virtual ~ITableReader();

};

#endif // ITABLEREADER_H
