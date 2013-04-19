#ifndef TABLEREADER_H
#define TABLEREADER_H

#include "itablereader.h"


class TableReader
        :public ITableReader
{
public:
    TableReader();
    virtual void ReadTable();
    virtual void ComputeTable();
    virtual std::shared_ptr<ICellStorage> GetTable();

    virtual ~TableReader();
    int width;
    int height;
private:

    std::shared_ptr<ICellStorage> storage;


};

#endif // TABLEREADER_H
