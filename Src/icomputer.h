#ifndef ICOMPUTER_H
#define ICOMPUTER_H

#include <exception>
#include <memory>

class MaxRecurciveDepthException: public std::exception
{
public:
    MaxRecurciveDepthException();
    MaxRecurciveDepthException(int x, int y);
    const char* what();
    std::pair<int,int> GetLastPos();
    bool isSetted();
private:
    int x,y;
    bool setted;
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
