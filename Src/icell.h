#ifndef ICELL_H
#define ICELL_H


#include "binarydata.h"
#include "iformulacomputer.h"
#include <string>
#include <memory>

class ErrorCell;
class StringCell;

enum CellAccess{NotComputed,
                Computing,
                Computed
               };

enum CellTypes{String,
                Empty,
                Int,
                Formula,
                NullCell,
                Error,
                CellIdx
               };

/**
	Generic cell classes
 */
class ICell
{
public:
    ICell();
    virtual ~ICell();

    /**
         Save current class to binary data class
         @returns raw data of class in BinaryData format
     */
    virtual BinaryData Serilize() = 0;
    /**
         Load current class from binary data
         @param BinaryData& binary data to load from
     */
    virtual void DeSerilize(BinaryData& data) = 0;
<<<<<<< HEAD
    virtual void LoadFromString(const std::string& str, bool trow_ex) = 0;
=======
    /**
         Load current cell from string data
         @param str string to initialize current cell
     */
    virtual void LoadFromString(const std::string& str) = 0;
    /**
         print current cell to string format
         @returns string format of current cell printing
     */
>>>>>>> Comments
    virtual std::string PrintToString() const = 0;
    /**
         compute current cell and return resulting cell that was computed from current cell
         @param recursive_depth current depth of recursion for given computation
         @returns pointer to computed cell
     */
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth) = 0;

    /**
    	return current cell type
    	@returns current cell type
     */
    CellTypes getCellType();
    /**
    	return current cell's computational statuc (computed, computing, not computed)
    	@returns current cell's computational statuc
     */
    CellAccess getAccessType();


    /**
    	load cell from given binary data
    	@param data binary data to load cell from
    	@param cell cell to load
    	@returns binary data
     */
    friend BinaryData & operator >>(BinaryData &data, std::shared_ptr<ICell>& cell);
    /**
         save given cell to binary data
         @param data binary data to save given cell in given binry data
         @param cell given save to save
         @returns binary data
     */
    friend BinaryData & operator <<(BinaryData &data, ICell & cell);


    /**
    	default operator + for cell (generate error in not re-defined in son class)
    	@param ICell& second argument of operator
    	@returns pointer to result cell
     */
    virtual std::shared_ptr<ICell> operator +(const ICell& ) const;
    /**
         default operator - for cell (generate error in not re-defined in son class)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    virtual std::shared_ptr<ICell> operator -(const ICell& ) const;
    /**
         default operator * for cell (generate error in not re-defined in son class)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    virtual std::shared_ptr<ICell> operator *(const ICell& ) const;
    /**
         default operator / for cell (generate error in not re-defined in son class)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    virtual std::shared_ptr<ICell> operator /(const ICell& ) const;

    /**
    	Set global formula computer for all cells
    	@param comp formula computer to set 
     */
    static void SetFormulaComputer(std::shared_ptr<IFormulaComputer>& comp);

    /**
    	Compute cell type from string that decribe cell
    	@param str string that describe cell
    	@returns cell type of decribed cell
     */
    static CellTypes GetCellType(const std::string& str);
<<<<<<< HEAD
    static std::shared_ptr<ICell> CellFactureMethod(const std::string& str, bool throw_ex);
=======
    /**
    	Generate cell object from string
    	@param str string to generate cell from
    	@returns pointer to created cell object
     */
    static std::shared_ptr<ICell> CellFactureMethod(const std::string& str);
    /**
    	Generate cell object of given cell type
    	@param id cell type
    	@returns pointer to created cell object
     */
>>>>>>> Comments
    static std::shared_ptr<ICell> CellFactureMethod(const CellTypes& id);

protected:
    void setCellType(const CellTypes& type);
    void setCellAccess(const CellAccess& type);
    static std::shared_ptr<IFormulaComputer> formulacomputer;

private:
    CellTypes celltype;
    CellAccess cellaccess;

};

#endif // ICELL_H
