//
//  simpletablecreator.cpp
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#include "simpletablecomputer.h"
#include "simpleformulacomputer.h"

SimpleTableComputer::SimpleTableComputer ()
{
    
}

SimpleTableComputer::~SimpleTableComputer ()
{
    
}
void SimpleTableComputer::ComputeTable (ICellStorage& table)
{
    std::shared_ptr<IFormulaComputer> f_comp = std::shared_ptr<SimpleFormulaComputer>(new SimpleFormulaComputer(table));
    ICell::SetFormulaComputer(f_comp);
    for(int x = 0; x<table.GetWidth(); ++x)
        for(int y = 0; y<table.GetHeight(); ++y)
        {
            table.SetCell(x,y,table.GetCell(x,y)->ComputeResult(0));
        }
}
