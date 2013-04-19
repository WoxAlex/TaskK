#ifndef SIMPLECELLSTORAGE_H
#define SIMPLECELLSTORAGE_H

#include "icellstorage.h"

/**
	Simple table storage that store table as matrix of cells
 */
class SimpleCellStorage:
        public ICellStorage
{
public:
    SimpleCellStorage();
    virtual ~SimpleCellStorage();
    
    /**
         create table with given size
         @param w table width (colums number)
         @param h table heigth (rows number)
     */
    void CreateTable(int w, int h);
    /**
         Get number of rows
         @returns number of rows
     */
    int GetHeight() const;
    /**
         Get number of columns
         @returns number of columns
     */
    int GetWidth() const;

    /**
         Get cell from given coordinates
         @param x x coordinate in table
         @param y y coordinate in table
         @returns cell with given coordinates
     */
    std::shared_ptr<ICell> GetCell(int x, int y) const;
    
    /**
         Get cell with test index (like A1, B1 etc..) and compute corresponding x, y coordinates of cell
         @param Name given string cell index
         @param x corresponding x coordinate
         @param y corresponding y coordinate
         @returns cell from given coordinate
     */
    std::shared_ptr<ICell> GetCell(const std::string& Name, int& x, int& y) const;
    
    /**
         Set cell in given location
         @param x x coordinate of cell
         @param y y coordinato of cell
         @param cell cell to put in given location in the table
     */
    void SetCell(int x, int y, std::shared_ptr<ICell> cell);
private:
    std::vector< std::vector < std::shared_ptr<ICell> > > data;
    int width;
    int height;
};

#endif // SIMPLECELLSTORAGE_H
