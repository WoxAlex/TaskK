#ifndef IFORMULACOMPUTER_H
#define IFORMULACOMPUTER_H

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
class IFormulaComputer
{
public:
    IFormulaComputer();
    virtual std::shared_ptr<ICell> CompMe(FormulaCell& formula, int recurdive_depth) = 0;
    virtual ~IFormulaComputer();

};

#endif // IFORMULACOMPUTER_H
