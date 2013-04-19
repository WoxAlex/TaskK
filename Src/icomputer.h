#ifndef ICOMPUTER_H
#define ICOMPUTER_H

#include <exception>
#include <memory>

class MaxRecurciveDepthException: public std::exception
{
public:
    MaxRecurciveDepthException();
    const char* what();
};


class FormulaCell;
class ICell;
class IComputer
{
public:
    IComputer();
    virtual std::shared_ptr<ICell> CompMe(FormulaCell& formula, int recurdive_depth) = 0;
};

#endif // ICOMPUTER_H
