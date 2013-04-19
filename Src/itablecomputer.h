//
//  itablecomputer.h
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#ifndef TaskKMac_itablecomputer_h
#define TaskKMac_itablecomputer_h

#include "icellstorage.h"

class ITableComputer
{
public:
    virtual void ComputeTable (ICellStorage& table) = 0;
    virtual ~ITableComputer(){}
};

#endif
