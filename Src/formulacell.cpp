#include "formulacell.h"
#include "errorcell.h"
#include "icellstorage.h"
#include <iostream>
#include <algorithm>

inline FormulaOperators charToOperator(char c){

    switch (c) {
        case '+': return FormulaAdd;
        case '-': return FormulaSub;
        case '*': return FormulaMul;
        case '/': return FormulaDiv;
    }
    throw std::invalid_argument("This char is not formula operator");
}

inline bool space(char c){

    return (c == '+') || (c == '-') || (c == '/') || (c == '*');
}

inline bool notspace(char c){
    return !space(c);
}

FormulaCell::FormulaCell(std::shared_ptr<IFormulaComputer> comp)
    :computer(comp)
{
    this->setCellType(Formula);
    this->setCellAccess(NotComputed);
}

FormulaCell::~FormulaCell()
{
}

std::shared_ptr<ICell> FormulaCell::ComputeResult(int recursive_depth)
{
    if(this->getAccessType() == Computing)
    {
        return std::shared_ptr<ErrorCell>(new ErrorCell("Cycle in formula"));
        this->setCellAccess(Computed);
    }
    try{
        this->setCellAccess(Computing);
        std::shared_ptr<ICell> out = this->computer->CompMe(*this, recursive_depth);
        this->setCellAccess(Computed);
        return out;
    }catch(MaxMemoryException& ex)
    {
        this->setCellAccess(NotComputed);
        throw ex;
    }catch(MaxRecurciveDepthException& ex)
    {
        this->setCellAccess(NotComputed);
        throw ex;
    }

}

std::string FormulaCell::PrintToString() const
{
    throw std::logic_error("Can't print formula");
}

void FormulaCell::LoadFromString(const std::string &str)
{
    if(str[0] != '=')
        throw std::invalid_argument("This cell type is not formula");
    split(str.substr(1), this->arguments, this->operators);

}

BinaryData FormulaCell::Serilize()
{
    BinaryData out;
    out << (int)this->operators.size();
    for(size_t i = 0; i < this->operators.size(); ++i)
        out << this->operators[i];
    out << (int)this->arguments.size();
    for(size_t i = 0; i < this->arguments.size(); ++i)
        out << this->arguments[i];
    return out;
}

void FormulaCell::DeSerilize(BinaryData &data)
{
    int size;
    data >> size;
    this->operators.resize(size);
    for(size_t i = 0; i < this->operators.size(); ++i)
        data >> (int&)this->operators[i];
    data >> size;
    this->arguments.resize(size);
    for(size_t i = 0; i < this->arguments.size(); ++i)
        data >> this->arguments[i];

}



void FormulaCell::split(const std::string &s, std::vector<std::string>& elems, std::vector<FormulaOperators>& operators) {

    elems.clear();
    operators.clear();
    std::string::const_iterator i = s.begin();

    while(i!=s.end()){
        //i = std::find_if(i, s.end(), notspace);
        std::string::const_iterator j= std::find_if(i, s.end(), space);
        if(i!=s.end()){
            //std::cout << *j << std::string(i, j) << std::endl;
            elems.push_back(std::string(i, j));
            if(j!=s.end())
            {
                operators.push_back(charToOperator(*j));
                ++j;
            }
            i = j;


        }
    }
}

