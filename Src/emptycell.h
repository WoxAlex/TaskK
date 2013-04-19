#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "icell.h"
class EmptyCell:
        public ICell
{
public:
    EmptyCell();
    virtual ~EmptyCell();
    virtual BinaryData Serilize();
    virtual void DeSerilize(BinaryData& );

    virtual void LoadFromString(const std::string& str);
    virtual std::string PrintToString() const;
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);
};

#endif // EMPTYCELL_H
