#ifndef ERRORCELL_H
#define ERRORCELL_H

#include "icell.h"

class ErrorCell:
        public ICell
{
public:
    ErrorCell();
    ErrorCell(const std::string& error_str);
    virtual ~ErrorCell();

    virtual BinaryData Serilize();
    virtual void DeSerilize(BinaryData& data);
    virtual void LoadFromString(const std::string& str);
    virtual std::string PrintToString() const;
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);

    std::shared_ptr<ICell> operator +(const std::shared_ptr<ICell>& ) const;
    std::shared_ptr<ICell> operator -(const std::shared_ptr<ICell>& ) const;
    std::shared_ptr<ICell> operator *(const std::shared_ptr<ICell>& ) const;
    std::shared_ptr<ICell> operator /(const std::shared_ptr<ICell>& ) const;
protected:
    std::string error;
};

#endif // ERRORCELL_H
