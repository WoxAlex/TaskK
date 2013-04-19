#include "tablereader.h"
#include "tablewriter.h"
#include "simpletablecomputer.h"
#include "simplecellstorage.h"
#include "optimizedtablecomputer.h"
#include <iostream>

int main(int , char **)
try
{
    SimpleCellStorage table;

    TableReader tableReader;
    tableReader.ReadTable(table);
    std::cout << std::endl;
    
    OptimizedTableComputer tableComputer(100, 1000);
    tableComputer.ComputeTable(table);
    
    TableWriter::PrintTable(table);

    std::cout << std::endl;

    //if( > 0)
    //    throw std::logic_error("Error table size");


//    //Create each cell

////    StringCell obj;
////    obj.LoadFromString("'data");

//    std::shared_ptr<SimpleCellStorage> storage = std::shared_ptr<SimpleCellStorage> (new SimpleCellStorage());
//    storage->CreateTable(3,2);

//    std::shared_ptr<IComputer> f_comp = std::shared_ptr<SimpleComputer>(new SimpleComputer(storage));

//    std::shared_ptr<IntCell> obj1 = std::shared_ptr<IntCell>(new IntCell());
//    obj1->LoadFromString("900");
//    storage->SetCell(0,0,obj1);
//    std::shared_ptr<IntCell> obj2 = std::shared_ptr<IntCell>(new IntCell());
//    obj2->LoadFromString("100");
//    storage->SetCell(1,0,obj2);

//    std::shared_ptr<IntCell> obj3 = std::shared_ptr<IntCell>(new IntCell());
//    obj3->LoadFromString("800");
//    storage->SetCell(0,1,obj3);

//    std::shared_ptr<IntCell> obj4 = std::shared_ptr<IntCell>(new IntCell());
//    obj4->LoadFromString("200");
//    storage->SetCell(1,1,obj4);

//    storage->SetCell(2,0,*storage->GetCell("a0") + storage->GetCell("B0"));
//    storage->SetCell(2,1,*storage->GetCell(0,1) - storage->GetCell(1,1));

//    ICell::SetFormulaComputer(f_comp);
//    std::shared_ptr<FormulaCell> obj = std::shared_ptr<FormulaCell>( new FormulaCell(f_comp));

//    obj->LoadFromString("=c0+C1/100");//16

//    //std::shared_ptr<ICell> obj = storage->GetCell(2,0);

//    //    StringCell obj;
//    //    obj.LoadFromString("'data");
//    //    StringCell obj;
//    //    obj.LoadFromString("'data");
//    //obj.ComputeResult();
//    //std::cout << obj.getCellType() << std::endl;

//    BinaryData tmp;
//    tmp << *obj;
//    ICell* out_stringCell;
//    tmp >> out_stringCell;

//    out_stringCell->ComputeResult();

//    std::cout << out_stringCell->GetResultPtr()->PrintToString() << std::endl;


//    std::shared_ptr<StringCell> stringCell1 = std::shared_ptr<StringCell>(new StringCell());
//    stringCell1->LoadFromString("'All ");
//    std::shared_ptr<StringCell> stringCell2 = std::shared_ptr<StringCell>(new StringCell());
//    stringCell2->LoadFromString("'ok");

//    std::shared_ptr<ICell> out = stringCell1->operator+(stringCell2);

//    std::cout << out->PrintToString() << std::endl;
//    //throw std::logic_error("test");
    return 0;
} catch (std::exception& e)
{
    std::cerr << "Exception what: " << e.what() << std::endl;
    return 1;
}

