#ifndef TABLEREADER_H
#define TABLEREADER_H

#include "itablereader.h"


/**
     Interface for method for reading table from input stream
 */
class TableReader
        :public ITableReader
{
public:
    TableReader();
    virtual ~TableReader();

    
    /**
     Read table from standart input stream to given table object
     @param table table object to read table to
     */
    virtual void ReadTable(ICellStorage& table);
private:



};

#endif // TABLEREADER_H
