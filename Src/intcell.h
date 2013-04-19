#ifndef INTCELL_H
#define INTCELL_H

#include "icell.h"
#include <limits>

template <class TYPE>
bool overflowAdd(TYPE a,TYPE b)
{

    return ((a!=0)
            &&(b!=0)
            &&((a > 0) == (b > 0))
            && ((llabs(a) > (std::numeric_limits<TYPE>::max() - llabs(b)))));
}

template <class TYPE>
bool overflowSub(TYPE a,TYPE b)
{
    return overflowAdd<TYPE>(a,-1*b);
}

template <class TYPE>
bool overflowMul(TYPE a,TYPE b)
{
    if ( b  == 0 )
        return false;
    else
        return llabs(a) > std::numeric_limits<TYPE>::max()/llabs(b);
}

class IntCell:
        public ICell
{
public:
    IntCell();

    virtual ~IntCell();

    virtual BinaryData Serilize();
    virtual void DeSerilize(BinaryData& data);

    virtual void LoadFromString(const std::string& str);
    virtual std::string PrintToString() const;
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);

    std::shared_ptr<ICell> operator +(const ICell& ) const;
    std::shared_ptr<ICell> operator +(const IntCell& ) const;

    std::shared_ptr<ICell> operator -(const ICell& ) const;
    std::shared_ptr<ICell> operator -(const IntCell& ) const;

    std::shared_ptr<ICell> operator *(const ICell& ) const;
    std::shared_ptr<ICell> operator *(const IntCell& ) const;

    std::shared_ptr<ICell> operator /(const ICell& ) const;
    std::shared_ptr<ICell> operator /(const IntCell& ) const;
protected:
    long long int val;
    bool error;
};

#endif // INTCELL_H
