#ifndef IFORMULACOMPUTER_H
#define IFORMULACOMPUTER_H

#include <exception>
#include <memory>

/**
	class for exception when maximum level of recurtion in formula computing is reached
 */
class MaxRecurciveDepthException: public std::exception
{
public:
    /**
    	default construction. ni additional info
     */
    MaxRecurciveDepthException();
    /**
    	Construction that add info with cell where maximum level was reached
    	@param x x coordinate of cell
    	@param y y coordinate of cell
     */
    MaxRecurciveDepthException(int x, int y);
    /**
    	Get exception description
    	@returns exception description
     */
    const char* what();
    /**
    	Get coordinates of cell where maximum recurcion level was reached
    	@returns coordinates of cell where maximum recurcion level was reached
     */
    std::pair<int,int> GetLastPos();
    /**
    	Get info where additional info about last cell coordinates was set
    	@returns true if info was set, false otherwise
     */
    bool isSet();
private:
    int x,y;
    bool set;
};


class FormulaCell;
class ICell;


/**
	Interface for formula computer algorithms
 */
class IFormulaComputer
{
public:
    IFormulaComputer();
    virtual ~IFormulaComputer();

    /**
    	Compute result of given formula cell
    	@param formula formula cell to compute result from
    	@param recurdive_depth current recursive level of computations
    	@returns result cell
     */
    virtual std::shared_ptr<ICell> CompMe(FormulaCell& formula, int recurdive_depth) = 0;

};

#endif // IFORMULACOMPUTER_H
