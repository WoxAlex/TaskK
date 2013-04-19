//
//  optimizedtablecomputer.cpp
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#include "optimizedtablecomputer.h"
#include "simpleformulacomputer.h"

OptimizedTableComputer::OptimizedTableComputer(float max_recursive_level)
    :max_recursive_level(max_recursive_level)
{
    
}
OptimizedTableComputer::~OptimizedTableComputer()
{
    
}
void OptimizedTableComputer::ComputeTable (ICellStorage& table)
{
    std::shared_ptr<IFormulaComputer> f_comp = std::shared_ptr<SimpleFormulaComputer>(new SimpleFormulaComputer(table));
    ICell::SetFormulaComputer(f_comp);
    std::vector<std::pair<int, int>> last_saved_recursive_cells;

    for(int x = 0; x<table.GetWidth(); ++x)
        for(int y = 0; y<table.GetHeight(); ++y)
        {
            try
            {
                table.SetCell(x,y,table.GetCell(x,y)->ComputeResult(0));
            }
            catch (MaxRecurciveDepthException& exc)
            {
                std::pair<int, int> last_succ_coords = exc.GetLastPos();
                
                
            }
        }


    
}
