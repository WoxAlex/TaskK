#ifndef ICELL_H
#define ICELL_H


#include "binarydata.h"
#include "iformulacomputer.h"
#include <string>
#include <memory>

class ErrorCell;
class StringCell;

enum CellAccess{NotComputed,
                Computing,
                Computed
               };

enum CellTypes{String,
                Empty,
                Int,
                Formula,
                NullCell,
                Error,
                CellIdx
               };

class ICell
{
public:
    ICell();
    virtual ~ICell();


    virtual BinaryData Serilize() = 0;
    virtual void DeSerilize(BinaryData& data) = 0;
    virtual void LoadFromString(const std::string& str) = 0;
    virtual std::string PrintToString() const = 0;
    //virtual void ComputeResult() = 0; ///Set return sharedPtr<ICell>
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth) = 0;

    CellTypes getCellType();

    CellAccess getAccessType();


    //std::shared_ptr<ICell> GetResultPtr();

    //void SetResultPtr(std::shared_ptr<ICell>);

    friend BinaryData & operator >>(BinaryData &data, std::shared_ptr<ICell>& cell);

    friend BinaryData & operator <<(BinaryData &data, ICell & cell);


    virtual std::shared_ptr<ICell> operator +(const std::shared_ptr<ICell>& ) const;

    virtual std::shared_ptr<ICell> operator -(const std::shared_ptr<ICell>& ) const;

    virtual std::shared_ptr<ICell> operator *(const std::shared_ptr<ICell>& ) const;

    virtual std::shared_ptr<ICell> operator /(const std::shared_ptr<ICell>& ) const;

    static void SetFormulaComputer(std::shared_ptr<IFormulaComputer>& comp);

    static CellTypes GetCellType(const std::string& str);
    static std::shared_ptr<ICell> CellFactureMethod(const std::string& str);
    static std::shared_ptr<ICell> CellFactureMethod(const CellTypes& id);
protected:
    void setCellType(const CellTypes& type);
    void setCellAccess(const CellAccess& type);

private:




    //std::shared_ptr<ICell> result;
    CellTypes celltype;
    CellAccess cellaccess;

    static std::shared_ptr<IFormulaComputer> formulacomputer;
};

#endif // ICELL_H
