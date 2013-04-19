#include "icellstorage.h"

ICellStorage::ICellStorage()
{
}

ICellStorage::~ICellStorage()
{
}


const char *MaxMemoryException::what()
{
    return "Memory exception";
}
