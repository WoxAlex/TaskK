#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "icell.h"


/**
	class for text cell
 */
class StringCell:
        public ICell
{
public:
    StringCell();
    virtual ~StringCell();

    /**
         Save current class to binary data class
         @returns raw data of class in BinaryData format
     */
    virtual BinaryData Serilize();
    /**
         Load current class from binary data
         @param BinaryData& binary data to load from
     */
    virtual void DeSerilize(BinaryData& data);

<<<<<<< HEAD
    virtual void LoadFromString(const std::string& str, bool trow_ex);
=======
    /**
         Load current cell from string data
         @param str string to initialize current cell
     */
    virtual void LoadFromString(const std::string& str);
    /**
         print current cell to string format
         @returns string format of current cell printing
     */
>>>>>>> Comments
    virtual std::string PrintToString() const;
    /**
         compute current cell and return resulting cell that was computed from current cell
         @param recursive_depth current depth of recursion for given computation
         @returns pointer to computed cell
     */
    virtual std::shared_ptr<ICell> ComputeResult(int recursive_depth);

//    std::shared_ptr<ICell> operator +(const ICell& ) const;
//    std::shared_ptr<ICell> operator +(const StringCell& ) const;
protected:
    std::string data;
};

#endif // STRINGCELL_H
