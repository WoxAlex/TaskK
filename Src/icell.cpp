#include "icell.h"
#include "errorcell.h"
#include "stringcell.h"
#include "formulacell.h"
#include "intcell.h"
#include "emptycell.h"

#include <iostream>
#include <stdexcept>
#include <utility>

std::shared_ptr<IComputer> ICell::formulacomputer = std::shared_ptr<IComputer>(NULL);

ICell::ICell()
      :celltype(NullCell),
      cellaccess(NotComputed)

{
}

ICell::~ICell()
{
}

CellTypes ICell::getCellType()
{
    return this->celltype;
}

CellAccess ICell::getAccessType()
{
    return this->cellaccess;
}

//std::shared_ptr<ICell> ICell::GetResultPtr()
//{
//    if(cellaccess == NotComputed)
//        this->ComputeResult();
//    if(cellaccess == Computing)
//        throw std::logic_error("This cell already computing");
//    if(cellaccess == Computed)
//        return this->result;

//    throw std::logic_error("Can't create cell result");
//    return this->result;
//}

//void ICell::SetResultPtr(std::shared_ptr<ICell> res)
//{
//    this->result = res;
//}

BinaryData &operator >>(BinaryData &data, ICell *&cell)
{
    CellTypes celltype;
    CellAccess cellaccess;
    BinaryData cell_data;
    data >> (int&)celltype >> (int&)cellaccess >> cell_data;


    cell = ICell::CellFactureMethod(celltype);
    cell->cellaccess = cellaccess;
    cell->DeSerilize(cell_data);

//    data >> (int&)celltype;
//    if(celltype != NullCell)
//    {
//        BinaryData cell_result;
//        data >> cell_result;
//        cell->result = std::shared_ptr<ICell>(ICell::CellFactureMethod(celltype));
//        cell->result->DeSerilize(cell_result);

//    }else
//    {
//        cell->result=NULL;
//    }

    return data;
}

BinaryData &operator <<(BinaryData &data, ICell &cell)
{
    BinaryData cell_data = cell.Serilize();
    data << cell.celltype << cell.cellaccess << cell_data;

//    if(cell.result != NULL)
//    {
//        data<< cell.result->celltype << cell.result->Serilize();

//    }else
//    {
//        data << NullCell;
//    }

    return data;
}

std::shared_ptr<ICell> ICell::operator +(const std::shared_ptr<ICell> &) const
{
    return std::shared_ptr<ICell>(new ErrorCell("Error operator"));
}
std::shared_ptr<ICell> ICell::operator -(const std::shared_ptr<ICell> &) const
{
    return std::shared_ptr<ICell>(new ErrorCell("Error operator"));
}
std::shared_ptr<ICell> ICell::operator *(const std::shared_ptr<ICell> &) const
{
    return std::shared_ptr<ICell>(new ErrorCell("Error operator"));
}
std::shared_ptr<ICell> ICell::operator /(const std::shared_ptr<ICell>& ) const
{
    return std::shared_ptr<ICell>(new ErrorCell("Error operator"));
}

void ICell::setCellType(const CellTypes &type)
{
    this->celltype = type;
}

void ICell::setCellAccess(const CellAccess &type)
{
    this->cellaccess = type;
}

ICell *ICell::CellFactureMethod(const std::string & str)
{
    ICell* out;
    switch(ICell::GetCellType(str))
    {
        case String: out = new StringCell(); break;
        case Int: out = new IntCell(); break;
        case Formula: out = new FormulaCell(ICell::formulacomputer); break;
        case Empty: out = new EmptyCell(); break;
        default: throw std::logic_error("Unknown cell type");
    }
    out->LoadFromString(str);
    return out;
}

CellTypes ICell::GetCellType(const std::string &str)
{
    if (str.length() == 0)
        return Empty;
    if (str[0] == '=')
        return Formula;
    if (str[0] == '\'')
        return String;
    if (('0' <= str[0]) && (str[0] <='9'))
        return Int;
    return CellIdx;
}

ICell *ICell::CellFactureMethod(const CellTypes &id)
{
    switch(id)
    {
    case String: return new StringCell();
    case Int: return new IntCell();
    case Formula: return new FormulaCell(ICell::formulacomputer);
    case Empty: return new EmptyCell();
    case NullCell: return NULL;
    case Error: return new ErrorCell();
    default: throw std::logic_error("Unknown cell type");
    }


}

void ICell::SetFormulaComputer(std::shared_ptr<IComputer> &comp)
{
    ICell::formulacomputer = comp;
}



