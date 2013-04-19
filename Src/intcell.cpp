#include "intcell.h"
#include "errorcell.h"
#include <stdlib.h>
#include <sstream>

#include <iostream>
IntCell::IntCell()
    :val(0),
      error(false)
{
    this->setCellType(Int);
    this->setCellAccess(NotComputed);
}

IntCell::~IntCell()
{
}

BinaryData IntCell::Serilize()
{
    BinaryData out(sizeof(long long int));
    *(long long int* )(out.data) =  this->val;
    return out;
}

void IntCell::DeSerilize(BinaryData &data)
{
    this->val = *(long long int* )data.data;
}

void IntCell::LoadFromString(const std::string &str)
{
    std::istringstream iss(str);
    //iss >> std::ws >> this->val >> std::ws; if ' 999 ' is corect
    iss >> this->val;
    //std::cout << this->val << std::endl;
    if(!iss.eof() || this->val < 0)
    {
        //this->SetResultPtr(std::shared_ptr<ErrorCell>( new ErrorCell("Can't convert to uint")));
        error = true;
        this->setCellAccess(Computed);
    }
}

std::string IntCell::PrintToString() const
{
    std::ostringstream oss("");
    oss << this->val;
    return oss.str();
}

std::shared_ptr<ICell> IntCell::ComputeResult(int)
{
    this->setCellAccess(Computed);
    if(error)
        return std::shared_ptr<ErrorCell>(new ErrorCell("Can't convert to uint"));
    return std::shared_ptr<IntCell>(new IntCell(*this));
}

std::shared_ptr<ICell> IntCell::operator +(const std::shared_ptr<ICell> &in) const
{
    if(dynamic_cast<IntCell*>(in.get()) != NULL)
    {
        return this->operator +(dynamic_cast<const IntCell&>(*in));
    }

    return this->ICell::operator +(in);

}

std::shared_ptr<ICell> IntCell::operator +(const IntCell &in) const
{
    std::shared_ptr<IntCell> out = std::shared_ptr<IntCell>(new IntCell());
    out->setCellAccess(Computed);
    out->val = this->val + in.val;
    //todo:add overflow detect and return ErrorCell
    return out;
}

std::shared_ptr<ICell> IntCell::operator -(const std::shared_ptr<ICell> & in) const
{
    if(dynamic_cast<IntCell*>(in.get()) != NULL)
    {
        return this->operator -(dynamic_cast<const IntCell&>(*in));
    }

    return this->ICell::operator +(in);

}

std::shared_ptr<ICell> IntCell::operator -(const IntCell &in) const
{
    std::shared_ptr<IntCell> out = std::shared_ptr<IntCell>(new IntCell());
    out->setCellAccess(Computed);
    out->val = this->val - in.val;
    //todo:add overflow detect and return ErrorCell
    return out;
}

std::shared_ptr<ICell> IntCell::operator *(const std::shared_ptr<ICell> & in) const
{
    if(dynamic_cast<IntCell*>(in.get()) != NULL)
    {
        return this->operator *(dynamic_cast<const IntCell&>(*in));
    }

    return this->ICell::operator +(in);

}

std::shared_ptr<ICell> IntCell::operator *(const IntCell &in) const
{
    std::shared_ptr<IntCell> out = std::shared_ptr<IntCell>(new IntCell());
    out->setCellAccess(Computed);
    out->val = this->val * in.val;
    //todo:add overflow detect and return ErrorCell
    return out;
}

std::shared_ptr<ICell> IntCell::operator /(const std::shared_ptr<ICell> & in) const
{
    if(dynamic_cast<IntCell*>(in.get()) != NULL)
    {
        return this->operator /(dynamic_cast<const IntCell&>(*in));
    }

    return this->ICell::operator +(in);

}

std::shared_ptr<ICell> IntCell::operator /(const IntCell &in) const
{
    if(in.val == 0)
        return std::shared_ptr<ICell>(new ErrorCell("Div 0"));
    std::shared_ptr<IntCell> out = std::shared_ptr<IntCell>(new IntCell());
    out->setCellAccess(Computed);
    out->val = this->val / in.val;
    return out;
}
