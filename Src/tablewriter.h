#ifndef TABLEWRITER_H
#define TABLEWRITER_H

#include "icellstorage.h"

/**
	Algorith for printing table
 */
class TableWriter
{
public:
    TableWriter();
    /**
    	Print given table to standart output
    	@param table table to print
     */
    static void PrintTable(const ICellStorage &table);


};

#endif // TABLEWRITER_H
