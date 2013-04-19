#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "icell.h"


/**
	class for empty cell
 */
class EmptyCell:
        public ICell
{
public:
    
    EmptyCell();
    virtual ~EmptyCell();
    /**
    	Save current class to binary data class
    	@returns raw data of class in BinaryData format
     */
    virtual BinaryData Serilize();
    /**
    	Load current class from binary data
    	@param BinaryData& binary data to load from
     */
    virtual void DeSerilize(BinaryData& );
    /**
     Load current cell from string data
     @param str string to initialize current cell
     @param trow_ex tell whether exception should be thrown if load from string was unseccessful
     */
    virtual void LoadFromString(const std::string& str, bool trow_ex);
    /**
    	print current cell to string format
    	@returns string format of current cell printing
     */
    virtual std::string PrintToString() const;
    /**
     compute current cell and return resulting cell that was computed from current cell
     @param recursive_depth current depth of recursion for given computation
     @returns pointer to computed cell
     */
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);
};

#endif // EMPTYCELL_H
