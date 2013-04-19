#include "errorcell.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
ErrorCell::ErrorCell()
{
    this->setCellType(Error);
}

ErrorCell::ErrorCell(const std::string &error_str)
    :error(error_str)
{
    this->setCellType(Error);
}

ErrorCell::~ErrorCell()
{
}

BinaryData ErrorCell::Serilize()
{
    BinaryData out;
    out << this->error;
    return out;
}

void ErrorCell::DeSerilize(BinaryData &data)
{
    data >> this->error;
}

void ErrorCell::LoadFromString(const std::string &)
{
    throw std::logic_error("ErrorCell can't load from string");
}

std::string ErrorCell::PrintToString() const
{
    return '#' + this->error;
}

std::shared_ptr<ICell> ErrorCell::ComputeResult(int)
{
    if(this->getAccessType() != Computed)
    {
        this->setCellAccess(Computed);
    }
    return std::shared_ptr<ErrorCell>(new ErrorCell(*this));
}

std::shared_ptr<ICell> ErrorCell::operator +(const std::shared_ptr<ICell> &) const
{
    return std::shared_ptr<ICell>(new ErrorCell(*this));
}
