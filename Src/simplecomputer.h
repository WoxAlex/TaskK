#ifndef SIMPLECOMPUTER_H
#define SIMPLECOMPUTER_H

#include "icomputer.h"
#include "icellstorage.h"

class SimpleComputer:
        public IComputer
{
public:
    SimpleComputer(std::shared_ptr<ICellStorage> storage, int max_depth = 1000);
    std::shared_ptr<ICell> CompMe(FormulaCell& formula, int recurdive_depth);
private:
    std::shared_ptr<ICellStorage> storage;
    int depth;
};

#endif // SIMPLECOMPUTER_H
