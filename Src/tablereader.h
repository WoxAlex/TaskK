#ifndef TABLEREADER_H
#define TABLEREADER_H

#include "itablereader.h"


class TableReader
        :public ITableReader
{
public:
    TableReader();
    virtual void ReadTable(ICellStorage& table);
    virtual ~TableReader();
private:



};

#endif // TABLEREADER_H
