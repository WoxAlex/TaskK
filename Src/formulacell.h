#ifndef FORMULACELL_H
#define FORMULACELL_H

#include "icell.h"
#include "iformulacomputer.h"

enum FormulaOperators
{
    FormulaAdd,FormulaSub,FormulaMul,FormulaDiv
};

class FormulaCell:
        public ICell
{
public:
    FormulaCell();
    ~FormulaCell();
    virtual BinaryData Serilize();
    virtual void DeSerilize(BinaryData& data);
    virtual void LoadFromString(const std::string& str, bool trow_ex);
    virtual std::string PrintToString() const;
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);

    std::vector<FormulaOperators> operators;
    std::vector< std::string > arguments;
private:
    void split(const std::string &s, std::vector<std::string>& elems, std::vector<FormulaOperators>& operators);
    std::shared_ptr<IFormulaComputer> computer;
};

// "=+++"

#endif // FORMULACELL_H
