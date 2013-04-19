#ifndef TABLEWRITER_H
#define TABLEWRITER_H

#include "icellstorage.h"

class TableWriter
{
public:
    TableWriter();
    static void PrintTable(int width, int height, const std::shared_ptr<ICellStorage> &storage);


};

#endif // TABLEWRITER_H
