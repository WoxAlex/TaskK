#ifndef ICELLSTORAGE_H
#define ICELLSTORAGE_H

#include "icell.h"
#include "memory"
#include "exception"
#include "string"

class MaxMemoryException: public std::exception
{
    MaxMemoryException();
    const char* what();
};

class ICellStorage
{
public:
    ICellStorage();
    virtual void CreateTable(int w, int h) =0;

    virtual std::shared_ptr<ICell> GetCell(int x, int y) const =0;
    virtual std::shared_ptr<ICell> GetCell(const std::string& Name, int& x, int& y) const =0;
    virtual void SetCell(int x, int y, std::shared_ptr<ICell> cell) =0;

};

#endif // ICELLSTORAGE_H
