//
//  optimizedtablecomputer.h
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#ifndef __TaskKMac__optimizedtablecomputer__
#define __TaskKMac__optimizedtablecomputer__

#include <iostream>
#include "itablecomputer.h"

/**
     Potimized computer that perform computation for all cells. Perform max recursive level control.
 */
class OptimizedTableComputer: public virtual ITableComputer
{
public:
    /**
    	Constructor
    	@param max_recursive_level maximum possible level of recurtion in formula computation
    	@param max_stack_size maximum size of stack to store indexes of previous non-finished computation of cell (because of too deep recursion level)
     */
    OptimizedTableComputer(float max_recursive_level, size_t max_stack_size);
    virtual ~OptimizedTableComputer();
    
    /**
         Compute result of given table
         @param table table to compute result from
     */
    virtual void ComputeTable (ICellStorage& table);
protected:
    int max_recursive_level;
    size_t max_stack_size;
};

#endif /* defined(__TaskKMac__optimizedtablecomputer__) */
