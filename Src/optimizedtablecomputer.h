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

class OptimizedTableComputer: public virtual ITableComputer
{
public:
    OptimizedTableComputer(float max_recursive_level);
    virtual ~OptimizedTableComputer();
    virtual void ComputeTable (ICellStorage& table);
protected:
    int max_recursive_level;
};

#endif /* defined(__TaskKMac__optimizedtablecomputer__) */
