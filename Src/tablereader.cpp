#include "tablereader.h"

#include "simplecellstorage.h"
#include "simpleformulacomputer.h"

#include "intcell.h"
#include "formulacell.h"
#include <iostream>
#include <sstream>
#include <algorithm>

TableReader::TableReader()
{
}

void split(const std::string &s, std::vector<std::string>& elems) {
    elems.clear();
    std::string::const_iterator i = s.begin();

    if(i == s.end())
    {
        elems.push_back(std::string(""));
    }

    while(i!=s.end())
    {
        std::string::const_iterator j= std::find_if(i, s.end(), [](char c){return c == '\t';});
        elems.push_back(std::string(i, j));
        if(j!=s.end())
        {
            ++j;
            if(j == s.end())
            {
                elems.push_back(std::string(""));
                break;
            }
        }
        i = j;
    }
}

void TableReader::ReadTable(ICellStorage& table)
{
    int buffer_size = 1024*1024*10;
    char* buffer = new char[buffer_size];
    std::cin.getline(buffer, buffer_size);//>> this->width >> this->height;

    std::istringstream iss(buffer);
    int width, height;
    iss >> std::ws >> height >> std::ws;
    if(iss.eof())
    {
        throw std::logic_error("Error input table size");
    }
    iss >> width  >> std::ws;
    if(!iss.eof())
    {
        throw std::logic_error("Error input table size");
    }

    table.CreateTable(width,  height);
    for(int y = 0; y<height; ++y)
    {
        std::cin.getline(buffer, buffer_size);

        std::vector< std::string > elems;

        std::string line_val = std::string(buffer);

        if(line_val[line_val.length()-1]  == 13)
        {
            line_val = line_val.substr(0,line_val.length()-1);
        }


        split(line_val,elems);

        if(static_cast<int>(elems.size()) != width)
            throw std::logic_error("Error read table row");

        for(size_t x = 0; x<elems.size(); ++x)
        {
            table.SetCell((int)x,y,ICell::CellFactureMethod(elems[x]));
        }
    }
    delete[] buffer;
}

TableReader::~TableReader()
{
}
