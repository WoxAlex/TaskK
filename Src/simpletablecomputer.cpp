//
//  simpletablecreator.cpp
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#include "simpletablecomputer.h"

SimpleTableComputer::SimpleTableComputer ()
{
    
}
void SimpleTableComputer::ComputeTable (ICellStorage& table)
{
    for(int x = 0; x<table.GetWidth(); ++x)
        for(int y = 0; y<table.GetHeight(); ++y)
        {
            table.SetCell(x,y,table.GetCell(x,y)->ComputeResult(0));
        }
}
