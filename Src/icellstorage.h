#ifndef ICELLSTORAGE_H
#define ICELLSTORAGE_H

#include "icell.h"
#include "memory"
#include "exception"
#include "string"

/**
	exception class for error when there is no memory for computations
 */
class MaxMemoryException: public std::exception
{
    MaxMemoryException();
    const char* what();
};

/**
	interface for storing tables data
 */
class ICellStorage
{
public:
    ICellStorage();
    virtual ~ICellStorage();

    /**
    	create table with given size
    	@param w table width (colums number)
    	@param h table heigth (rows number)
     */
    virtual void CreateTable(int w, int h) =0;

    /**
    	Get number of rows
    	@returns number of rows
     */
    virtual int GetHeight() const = 0;
    /**
    	Get number of colums 
    	@returns number of colums
     */
    virtual int GetWidth() const = 0;

    /**
    	Get cell from given coordinates
    	@param x x coordinate in table
    	@param y y coordinate in table
    	@returns cell with given coordinates
     */
    virtual std::shared_ptr<ICell> GetCell(int x, int y) const =0;
    /**
    	Get cell with test index (like A1, B1 etc..) and compute corresponding x, y coordinates of cell
    	@param Name given string cell index
    	@param x corresponding x coordinate
    	@param y corresponding y coordinate
    	@returns cell from given coordinate
     */
    virtual std::shared_ptr<ICell> GetCell(const std::string& Name, int& x, int& y) const =0;
    /**
    	Set cell in given location
    	@param x x coordinate of cell
    	@param y y coordinato of cell
    	@param cell cell to put in given location in the table
     */
    virtual void SetCell(int x, int y, std::shared_ptr<ICell> cell) =0;

};

#endif // ICELLSTORAGE_H
