#include "iformulacomputer.h"

IFormulaComputer::IFormulaComputer()
{
}
IFormulaComputer::~IFormulaComputer()
{
    
}


MaxRecurciveDepthException::MaxRecurciveDepthException()
    :x(0),y(0),set(false)
{
}

MaxRecurciveDepthException::MaxRecurciveDepthException(int x, int y)
    :x(x),y(y),set(true)
{
}

const char *MaxRecurciveDepthException::what()
{
    return "MaxRecurciveDepthException";
}

std::pair<int,int> MaxRecurciveDepthException::GetLastPos()
{
    return std::pair<int,int>(x,y);
}

bool MaxRecurciveDepthException::isSet()
{
    return this->set;
}
