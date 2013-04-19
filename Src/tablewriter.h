#ifndef TABLEWRITER_H
#define TABLEWRITER_H

#include "icellstorage.h"

class TableWriter
{
public:
    TableWriter();
    static void PrintTable(const ICellStorage &table);


};

#endif // TABLEWRITER_H
