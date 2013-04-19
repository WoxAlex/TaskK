#include "emptycell.h"
#include <stdexcept>

EmptyCell::EmptyCell()
{
    this->setCellType(Empty);
    this->setCellAccess(NotComputed);
}

EmptyCell::~EmptyCell()
{
}

BinaryData EmptyCell::Serilize()
{
    return BinaryData(0);
}

void EmptyCell::DeSerilize(BinaryData &)
{

}

void EmptyCell::LoadFromString(const std::string &str, bool)
{
    if(str != "")
        throw std::logic_error("Empty cell not empty");
}

std::string EmptyCell::PrintToString() const
{
    return "";
}

std::shared_ptr<ICell> EmptyCell::ComputeResult(int )
{
    this->setCellAccess(Computed);
    return std::shared_ptr<EmptyCell>(new EmptyCell(*this));
}
