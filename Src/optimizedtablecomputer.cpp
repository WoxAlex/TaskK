//
//  optimizedtablecomputer.cpp
//  TaskKMac
//
//  Created by Tatiana Novikova on 19.04.13.
//  Copyright (c) 2013 Tatiana Novikova. All rights reserved.
//

#include "optimizedtablecomputer.h"
#include "simpleformulacomputer.h"
#include <list>

OptimizedTableComputer::OptimizedTableComputer(float max_recursive_level, size_t max_stack_size)
    :max_recursive_level(max_recursive_level),
    max_stack_size(max_stack_size)
{
    
}
OptimizedTableComputer::~OptimizedTableComputer()
{
    
}
void OptimizedTableComputer::ComputeTable (ICellStorage& table)
{
    std::shared_ptr<IFormulaComputer> f_comp = std::shared_ptr<SimpleFormulaComputer>(new SimpleFormulaComputer(table, this->max_recursive_level));
    ICell::SetFormulaComputer(f_comp);

    std::list < std::pair<int, int> > recursiveCellStack;
    
    for(int x = 0; x<table.GetWidth(); x++)
        for(int y = 0; y<table.GetHeight(); y++)
        {
            recursiveCellStack.push_back(std::pair<int, int> (x, y));
            bool originalCellSucced = true;
            while(!recursiveCellStack.empty())
            {
                bool currentCellSucessed = true;
                auto currentCellCoordinates = recursiveCellStack.back();
                auto currentCell = table.GetCell(currentCellCoordinates.first, currentCellCoordinates.second);
                if (currentCell->getAccessType() != Computed)
                {
                    try
                    {
                        currentCell = table.GetCell(currentCellCoordinates.first, currentCellCoordinates.second)->ComputeResult(0);
                    }
                    catch (MaxRecurciveDepthException& exc)
                    {
                        currentCellSucessed = false;
                        if (recursiveCellStack.size() >= this->max_stack_size)
                        {
                            originalCellSucced = false;
                            recursiveCellStack.pop_front();
                        };
                        auto last_start_coords = exc.GetLastPos();
                        recursiveCellStack.push_back(last_start_coords);
                    }
                    if (currentCellSucessed)
                    {
                        table.SetCell(currentCellCoordinates.first, currentCellCoordinates.second, currentCell);
                        recursiveCellStack.pop_back();
                    }
                }
                else
                {
                    recursiveCellStack.pop_back();
                }
            }
            if (!originalCellSucced)
            {
                y--;
            }
            
        }


    
}
