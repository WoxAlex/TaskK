#include "tablewriter.h"
#include <iostream>
TableWriter::TableWriter()
{
}

void TableWriter::PrintTable(int width, int height, const std::shared_ptr<ICellStorage> &storage)
{

    for(int y = 0; y<height; ++y)
    {
        if (y > 0)
            std::cout << std::endl;
        for(int x = 0; x<width; ++x)
        {
            if (x > 0)
                std::cout << "\t";
            std::cout << storage->GetCell(x,y)->PrintToString();

        }
    }

}
