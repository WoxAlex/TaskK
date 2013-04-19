#ifndef SIMPLECELLSTORAGE_H
#define SIMPLECELLSTORAGE_H

#include "icellstorage.h"

class SimpleCellStorage:
        public ICellStorage
{
public:
    SimpleCellStorage();
    void CreateTable(int w, int h);

    std::shared_ptr<ICell> GetCell(int x, int y) const;
    std::shared_ptr<ICell> GetCell(const std::string& Name, int& x, int& y) const;
    void SetCell(int x, int y, std::shared_ptr<ICell> cell);
private:
    std::vector< std::vector < std::shared_ptr<ICell> > > data;
    int width;
    int height;
};

#endif // SIMPLECELLSTORAGE_H
