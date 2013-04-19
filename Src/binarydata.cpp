#include "binarydata.h"
#include "stdlib.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

BinaryData::BinaryData(int length)
    :length(length)
{
    this->data = new char[length];
    this->start_ptr = this->data;
}

BinaryData::BinaryData()
    :length(0)
{
    this->data = NULL;
    this->start_ptr = this->data;
}

BinaryData::~BinaryData()
{
    delete data;
}

BinaryData &BinaryData::operator =(const BinaryData &data)
{
    if(data.length != 0)
    {
        this->data = (char*)realloc(this->data,data.length);
        memcpy(this->data,data.data,data.length);
        this->start_ptr = this->data;
        this->length = data.length;

    }else
    {
        this->data = NULL;
        this->start_ptr = this->data;
        this->data = 0;
    }
    return *this;
}

BinaryData &operator >>(BinaryData &data, BinaryData &val)
{
    if(data.start_ptr == NULL)
        throw std::logic_error("Empty data in BinaryData");
    int* ptr_l = (int*)(data.start_ptr);
    data.start_ptr += sizeof(int);
    char* ptr_d = (char*)(data.start_ptr);
    data.start_ptr += *ptr_l;

    val = BinaryData(*ptr_l);
    memcpy(val.data,ptr_d,val.length);
    return data;
}

BinaryData &operator >>(BinaryData &data, int &val)
{
    if(data.start_ptr == NULL)
        throw std::logic_error("Empty data in BinaryData");
    int* ptr = (int*)(data.start_ptr);
    val = *ptr;
    data.start_ptr += sizeof(int);
    return data;
}

BinaryData &operator <<(BinaryData &data, const BinaryData &val)
{
    data.length += sizeof(int) + val.length;
    if(data.data == NULL )
    {
        data.data = new char[data.length];
        data.start_ptr = data.data;
    }else
    {
        long long int delta = data.start_ptr - data.data;
        data.data = (char*)realloc(data.data,data.length);
        data.start_ptr =data.data + delta;
    }
    int* ptr_l = (int*)(data.data + data.length -sizeof(int) - val.length);
    char* ptr_d = (char*)(data.data + data.length  - val.length);
    *ptr_l = val.length;
    memcpy(ptr_d,val.data,val.length);
    return data;
}


BinaryData &operator <<(BinaryData &data, const int &val)
{
    data.length += sizeof(int);
    if(data.data == NULL )
    {
        data.data = new char[data.length];
        data.start_ptr = data.data;
    }else
    {
        long long int delta = data.start_ptr - data.data;
        data.data = (char*)realloc(data.data,data.length);
        data.start_ptr =data.data + delta;
    }
    int* ptr = (int*)(data.data + data.length -sizeof(int));
    *ptr = val;
    return data;
}





BinaryData &operator >>(BinaryData &data, std::string &val)
{
    if(data.start_ptr == NULL)
        throw std::logic_error("Empty data in BinaryData");
    int* ptr_l = (int*)(data.start_ptr);
    data.start_ptr += sizeof(int);
    char* ptr_d = (char*)(data.start_ptr);
    data.start_ptr += *ptr_l;
    val = std::string(*ptr_l,' ');

    for(size_t i = 0; i<val.length(); ++i)
    {
        val[i] = ptr_d[i];
    }

    return data;
}


BinaryData &operator <<(BinaryData &data, const std::string &val)
{
    data.length += sizeof(int) + val.length();
    if(data.data == NULL )
    {
        data.data = new char[data.length];
        data.start_ptr = data.data;
    }else
    {
        long long int delta = data.start_ptr - data.data;
        data.data = (char*)realloc(data.data,data.length);
        data.start_ptr =data.data + delta;
    }
    int* ptr_l = (int*)(data.data + data.length -sizeof(int) - val.length());
    char* ptr_d = (char*)(data.data + data.length  - val.length());
    *ptr_l = (int)val.length();
    memcpy(ptr_d,val.data(),val.length());
    return data;
}
