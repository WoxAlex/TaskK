#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "icell.h"

class StringCell:
        public ICell
{
public:
    StringCell();
    virtual ~StringCell();

    virtual BinaryData Serilize();
    virtual void DeSerilize(BinaryData& data);

    virtual void LoadFromString(const std::string& str);
    virtual std::string PrintToString() const;
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);

<<<<<<< HEAD
    std::shared_ptr<ICell> operator +(const ICell& ) const;
    std::shared_ptr<ICell> operator +(const StringCell& ) const;
=======
    //std::shared_ptr<ICell> operator +(const std::shared_ptr<ICell>& ) const;
    //std::shared_ptr<ICell> operator +(const StringCell& ) const;
>>>>>>> Put formula computer into tablecomputer

protected:
    std::string data;
};

#endif // STRINGCELL_H
