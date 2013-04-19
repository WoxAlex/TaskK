#ifndef BINARYDATA_H
#define BINARYDATA_H

#include <vector>
#include <string>

struct BinaryData
{
public:
    BinaryData(int length);
    BinaryData();
    ~BinaryData();
    char* data;
    char* start_ptr;
    int length;

    BinaryData & operator =(const BinaryData & data);

    friend BinaryData & operator >>(BinaryData & data,BinaryData & val);
    friend BinaryData & operator >>(BinaryData & data,int & val);
    friend BinaryData & operator >>(BinaryData & data,std::string & val);

    friend BinaryData & operator <<(BinaryData & data,const BinaryData & val);
    friend BinaryData & operator <<(BinaryData & data,const int & val);
    friend BinaryData & operator <<(BinaryData & data,const std::string & val);
};

#endif // BINARYDATA_H
