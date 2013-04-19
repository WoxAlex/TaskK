#include "tablewriter.h"
#include <iostream>
TableWriter::TableWriter()
{
}

void TableWriter::PrintTable(const ICellStorage &table)
{

    for(int y = 0; y<table.GetHeight(); ++y)
    {
        if (y > 0 && table.GetWidth() > 0)
            std::cout << std::endl;
        for(int x = 0; x<table.GetWidth(); ++x)
        {
            if (x > 0)
                std::cout << "\t";
            std::cout << table.GetCell(x,y)->PrintToString();

        }
    }

}
