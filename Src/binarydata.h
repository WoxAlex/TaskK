#ifndef BINARYDATA_H
#define BINARYDATA_H

#include <vector>
#include <string>

/**
	class for swapping cells (for extra-large tables). Not used yet.
 */
struct BinaryData
{
public:
    /**
    	create binary data with given leght of binary data (reserve storage with given legth)
    	@param length give length of binary data
     */
    BinaryData(int length);
    /**
     create empty binary data
     */
    BinaryData();
    ~BinaryData();
    BinaryData & operator =(const BinaryData & data);

    friend BinaryData & operator >>(BinaryData & data,BinaryData & val);
    friend BinaryData & operator >>(BinaryData & data,int & val);
    friend BinaryData & operator >>(BinaryData & data,std::string & val);

    friend BinaryData & operator <<(BinaryData & data,const BinaryData & val);
    friend BinaryData & operator <<(BinaryData & data,const int & val);
    friend BinaryData & operator <<(BinaryData & data,const std::string & val);
    
    
    char* data;
    char* start_ptr;
    int length;
};

#endif // BINARYDATA_H
