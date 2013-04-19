#ifndef FORMULACELL_H
#define FORMULACELL_H

#include "icell.h"
#include "iformulacomputer.h"

enum FormulaOperators
{
    FormulaAdd,FormulaSub,FormulaMul,FormulaDiv
};

/**
	class for formula cell computation
 */
class FormulaCell:
        public ICell
{
public:
    FormulaCell();
    virtual ~FormulaCell();
    /**
         Save current class to binary data class
         @returns raw data of class in BinaryData format
     */
    virtual BinaryData Serilize();
    /**
         Load current class from binary data
         @param BinaryData& binary data to load from
     */
    virtual void DeSerilize(BinaryData& data);
<<<<<<< HEAD
    virtual void LoadFromString(const std::string& str, bool trow_ex);
=======
    /**
         Load current cell from string data
         @param str string to initialize current cell
     */
     virtual void LoadFromString(const std::string& str);
    /**
         print current cell to string format
         @returns string format of current cell printing
     */
>>>>>>> Comments
    virtual std::string PrintToString() const;
    /**
         compute current cell and return resulting cell that was computed from current cell
         @param recursive_depth current depth of recursion for given computation
         @returns pointer to computed cell
     */
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);

    /**
    	formula operators
     */
    std::vector<FormulaOperators> operators;
    /**
    	formula arguments
     */
    std::vector< std::string > arguments;
private:
    void split(const std::string &s, std::vector<std::string>& elems, std::vector<FormulaOperators>& operators);
    std::shared_ptr<IFormulaComputer> computer;
};

// "=+++"

#endif // FORMULACELL_H
