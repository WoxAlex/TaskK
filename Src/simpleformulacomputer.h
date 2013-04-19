#ifndef SIMPLEFORMULACOMPUTER_H
#define SIMPLEFORMULACOMPUTER_H

#include "iformulacomputer.h"
#include "icellstorage.h"

class SimpleFormulaComputer:
        public IFormulaComputer
{
public:
    SimpleFormulaComputer(ICellStorage& table, int max_depth = 1000);
    std::shared_ptr<ICell> CompMe(FormulaCell& formula, int recurdive_depth);
private:
    ICellStorage& table;
    int depth;
};

#endif // SIMPLECOMPUTER_H
