#include "simpleformulacomputer.h"

#include "formulacell.h"
#include "emptycell.h"
#include "errorcell.h"
#include "iostream"

SimpleFormulaComputer::SimpleFormulaComputer(ICellStorage& table, int max_depth)
    :table(table),
      depth(max_depth)
{
}

std::shared_ptr<ICell> SimpleFormulaComputer::CompMe(FormulaCell &f, int recurdive_depth)
{
    if (recurdive_depth > this->depth)
        throw MaxRecurciveDepthException();
    // if cell : "="
    if((f.arguments.size()  == f.operators.size())  && (f.arguments.size() == 0))
    {
        return std::shared_ptr<EmptyCell>(new EmptyCell());
    }

    if(f.arguments.size()  != (f.operators.size() +1))
    {
        return std::shared_ptr<ErrorCell>(new ErrorCell("Incorrect formula"));
    }

    std::shared_ptr<ICell> out;

    std::shared_ptr<ICell> next;

    if(ICell::GetCellType(f.arguments[0]) == CellIdx)
    {
        int x,y;
        try
        {
            out = this->table.GetCell(f.arguments[0],x,y);
            if(out->getAccessType() != Computed)
            {
                out = out->ComputeResult(recurdive_depth+1);
                this->table.SetCell(x,y,out);
            }
        }
        catch(std::logic_error& e)
        {
            std::string msg = std::string(e.what());
            if(msg == "Error in cell name")
                out = std::shared_ptr<ICell>(new ErrorCell("Error cell name"));
                else if(msg == "Error in cell address")
                out = std::shared_ptr<ICell>(new ErrorCell("Error cell address"));
                else if(msg == "This cell already computing")
                out = std::shared_ptr<ICell>(new ErrorCell("Cycle in formula"));
                else
                throw e;
        }
        catch(MaxRecurciveDepthException& ex)
        {
            if(!ex.isSetted())
                throw MaxRecurciveDepthException(x,y);
            throw ex;
        }
    }else
    {
        out = ICell::CellFactureMethod(f.arguments[0]);

    }

    for(size_t i = 1; i<f.arguments.size(); ++i)
    {
        if(ICell::GetCellType(f.arguments[i]) == CellIdx)
        {

            int x,y;
            try
            {
                next = this->table.GetCell(f.arguments[i],x,y);
                if(next->getAccessType() != Computed)
                {
                    next = next->ComputeResult(recurdive_depth+1);
                    this->table.SetCell(x,y,next);
                }
            }
            catch(std::logic_error& e)
            {
                std::string msg = std::string(e.what());
                if(msg == "Error in cell name")
                    next = std::shared_ptr<ICell>(new ErrorCell("Error cell name"));
                    else if(msg == "Error in cell address")
                    next = std::shared_ptr<ICell>(new ErrorCell("Error cell address"));
                    else if(msg == "This cell already computing")
                    out = std::shared_ptr<ICell>(new ErrorCell("Cycle in formula"));
                    else
                    throw e;
            }
            catch(MaxRecurciveDepthException& ex)
            {
                if(!ex.isSetted())
                    throw MaxRecurciveDepthException(x,y);
                throw ex;
            }
        }else
        {
            next = ICell::CellFactureMethod(f.arguments[i]);
        }
        if(next->getAccessType() == Computing)
            out = std::shared_ptr<ICell>(new ErrorCell("Cycle in formula"));
        else
        {
            switch (f.operators[i-1]) {
            case FormulaAdd:
                out = *out+next;
                break;
            case FormulaSub:
                out = *out-next;
                break;
            case FormulaMul:
                out = *out*next;
                break;
            case FormulaDiv:
                out = *out/next;
                break;
            }
        }
    }
    out = out->ComputeResult(recurdive_depth+1);
    return out;
}
