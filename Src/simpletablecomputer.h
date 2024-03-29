//
//  simpletablecreator.h
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#ifndef __TaskKMac__simpletablecreator__
#define __TaskKMac__simpletablecreator__

#include <iostream>
#include "itablecomputer.h"

/**
 Simple computer that perform computation for all cells one-by-one. Doesn't perform max recursive level control.
 */
class SimpleTableComputer : public virtual ITableComputer
{
public:
    SimpleTableComputer ();
    virtual ~SimpleTableComputer ();
    
    /**
    	Compute result of given table
    	@param table table to compute
     */
    virtual void ComputeTable (ICellStorage& table);
};

#endif /* defined(__TaskKMac__simpletablecreator__) */
