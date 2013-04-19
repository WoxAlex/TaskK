#ifndef SIMPLEFORMULACOMPUTER_H
#define SIMPLEFORMULACOMPUTER_H

#include "iformulacomputer.h"
#include "icellstorage.h"

/**
	Algorith for single formula computation. Recurvely compute all arguments in formula and perform operation between them.
 */
class SimpleFormulaComputer:
        public IFormulaComputer
{
public:
    /**
    	Constructor for formula computer for given table
    	@param table give table
    	@param max_depth maximum recursive level
     */
    SimpleFormulaComputer(ICellStorage& table, int max_depth = 1000);
    virtual ~SimpleFormulaComputer();
    
    /**
     Compute result of given formula cell
     @param formula formula cell to compute result from
     @param recurdive_depth current recursive level of computations
     @returns result cell
     */
    std::shared_ptr<ICell> CompMe(FormulaCell& formula, int recurdive_depth);
private:
    ICellStorage& table;
    int depth;
};

#endif // SIMPLECOMPUTER_H
