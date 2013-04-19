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

/**
	Interface for methods for computing tables datas
 */
class ITableComputer
{
public:
    /**
    	Compute all tables cells
    	@param table table to fix
     */
    virtual void ComputeTable (ICellStorage& table) = 0;
    virtual ~ITableComputer(){}
};

#endif
