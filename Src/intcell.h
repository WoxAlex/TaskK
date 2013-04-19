#ifndef INTCELL_H
#define INTCELL_H

#include "icell.h"
#include <limits>
#include <complex>

/**
	check if sum of given argument cause type overflow
	@param a first argument
	@param b second argument
	@returns true is sum cause overflow, false otherwise
 */
template <class TYPE>
bool overflowAdd(TYPE a,TYPE b)
{

    return ((a!=0)
            &&(b!=0)
            &&((a > 0) == (b > 0))
            && ((llabs(a) > (std::numeric_limits<TYPE>::max() - llabs(b)))));
}

/**
 check if substraction of given argument cause type overflow
 @param a first argument
 @param b second argument
 @returns true is substraction cause overflow, false otherwise
 */
template <class TYPE>
bool overflowSub(TYPE a,TYPE b)
{
    return overflowAdd<TYPE>(a,-1*b);
}

/**
 check if multiplication of given argument cause type overflow
 @param a first argument
 @param b second argument
 @returns true is multiplication cause overflow, false otherwise
 */
template <class TYPE>
bool overflowMul(TYPE a,TYPE b)
{
    if ( b  == 0 )
        return false;
    else
        return llabs(a) > std::numeric_limits<TYPE>::max()/llabs(b);
}

/**
	class for numeric cell
 */
class IntCell:
        public ICell
{
public:
    IntCell();
    virtual ~IntCell();

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

    /**
         operator + for int cell with any cell (perform add only for int cells)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator +(const ICell& ) const;
    /**
         operator + for int cells
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator +(const IntCell& ) const;
    /**
         operator - for int cell with any cell (perform add only for int cells)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator -(const ICell& ) const;
    /**
         operator + for int cells
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator -(const IntCell& ) const;
    /**
         operator * for int cell with any cell (perform add only for int cells)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator *(const ICell& ) const;
    /**
         operator + for int cells
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator *(const IntCell& ) const;

    /**
         operator / for int cell with any cell (perform add only for int cells)
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator /(const ICell& ) const;
    /**
         operator + for int cells
         @param ICell& second argument of operator
         @returns pointer to result cell
     */
    std::shared_ptr<ICell> operator /(const IntCell& ) const;
protected:
    long long int val;
    bool error;
};

#endif // INTCELL_H
