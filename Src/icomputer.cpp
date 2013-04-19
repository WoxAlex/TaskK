#include "icomputer.h"

IComputer::IComputer()
{
}


MaxRecurciveDepthException::MaxRecurciveDepthException()
    :x(0),y(0),setted(false)
{
}

MaxRecurciveDepthException::MaxRecurciveDepthException(int x, int y)
    :x(x),y(y),setted(true)
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

bool MaxRecurciveDepthException::isSetted()
{
    return this->setted;
}
