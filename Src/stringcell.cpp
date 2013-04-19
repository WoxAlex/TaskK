#include "stringcell.h"
#include <cstring>
#include <stdexcept>
#include <utility>
#include <iostream>


StringCell::StringCell()
{
    this->setCellType(String);
    this->setCellAccess(NotComputed);
}

StringCell::~StringCell()
{
}

BinaryData StringCell::Serilize()
{
    BinaryData out;
    out << this->data;
    return out;
}

void StringCell::DeSerilize(BinaryData &data)
{
    data >> this->data;
}

std::shared_ptr<ICell> StringCell::ComputeResult(int)
{
    if(this->getAccessType() != Computed)
    {
        this->setCellAccess(Computed);
    }
    return std::shared_ptr<StringCell>(new StringCell(*this));
}

std::shared_ptr<ICell> StringCell::operator +(const ICell &in) const
{
    if(dynamic_cast<const StringCell*>(&in) != NULL)
    {
        return this->operator +(dynamic_cast<const StringCell&>(in));
    }

    return this->ICell::operator +(in);

//    std::shared_ptr<StringCell> out = std::shared_ptr<StringCell>();
////    out.setCellAccess(Computed);
////    out.data = this->data + dynamic_cast<const StringCell& >(in).data + "++";
//    std::cout << " string" << out->data << std::endl;
//    return out;
}

std::shared_ptr<ICell> StringCell::operator +(const StringCell& in) const
{

    std::shared_ptr<StringCell> out = std::shared_ptr<StringCell>(new StringCell());
    out->setCellAccess(Computed);
    out->data = this->data + in.data;
    return out;
}

std::string StringCell::PrintToString() const
{
    return this->data;
}

void StringCell::LoadFromString(const std::string &str)
{
    if(str[0] == '\'')
    {
        this->data = str.substr(1);

    }else
    {
        throw std::invalid_argument("This cell type is not string");
    }
}
