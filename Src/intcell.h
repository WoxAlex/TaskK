#ifndef INTCELL_H
#define INTCELL_H

#include "icell.h"
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
