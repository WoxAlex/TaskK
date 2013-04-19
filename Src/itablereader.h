#ifndef ITABLEREADER_H
#define ITABLEREADER_H

#include "icellstorage.h"

/**
	Interface for method for reading table
 */ 
class ITableReader
{
public:
    ITableReader();
    virtual ~ITableReader();

    /**
    	Read table
        @param table table object to read table to
     */
    virtual void ReadTable(ICellStorage& table) = 0;

};

#endif // ITABLEREADER_H
