#ifndef ERRORCELL_H
#define ERRORCELL_H

#include "icell.h"

/**
	class for error cell
 */
class ErrorCell:
        public ICell
{
public:
    
    /**
    	constructor that initialize error class with given error comment
    	@param error_str error comment
     */
    ErrorCell(const std::string& error_str);
    ErrorCell();
    virtual ~ErrorCell();

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
    	operator + for error cell (return current error cell for any second argument)
    	@param ICell& second argument
    	@returns result cell 
     */
    std::shared_ptr<ICell> operator +(const ICell& ) const;
    /**
     operator - for error cell (return current error cell for any second argument)
     @param ICell& second argument
     @returns result cell
     */
    std::shared_ptr<ICell> operator -(const ICell& ) const;
    /**
     operator * for error cell (return current error cell for any second argument)
     @param ICell& second argument
     @returns result cell
     */
    std::shared_ptr<ICell> operator *(const ICell& ) const;
    /**
     operator / for error cell (return current error cell for any second argument)
     @param ICell& second argument
     @returns result cell
     */
    std::shared_ptr<ICell> operator /(const ICell& ) const;
protected:
    std::string error;
};

#endif // ERRORCELL_H
