#include "simplecellstorage.h"
#include <algorithm>
#include <iostream>
SimpleCellStorage::SimpleCellStorage()
    :width(0),
      height(0)
{
}

void SimpleCellStorage::CreateTable(int w, int h)
{
    //h >0 w > 0
    if(w < 0 || h < 0)
        throw std::logic_error("Error in table size");

    this->width = w;
    this->height = h;

    this->data.resize(h);
    for(int i = 0; i < h; ++i)
    {
        std::vector < std::shared_ptr<ICell> > row (w,NULL);
        this->data[i] = row;
    }

}

int SimpleCellStorage::GetHeight() const 
{
    return this->height;
}

int SimpleCellStorage::GetWidth() const
{
    return this->width;
}

std::shared_ptr<ICell> SimpleCellStorage::GetCell(int x, int y) const
{
    //std::cout << x << y << width << height << std::endl;
    if(x < 0 || y < 0 || x >= this->width || y >= this->height)
        throw std::logic_error("Error in cell address");
    return this->data[y][x];
}

std::shared_ptr<ICell> SimpleCellStorage::GetCell(const std::string& Name, int& x, int& y) const
{

    x = 0;
    y = 0;
    //A01 -- ?
    std::string tmp = Name;
    std::transform(tmp.begin(), tmp.end(),tmp.begin(), ::toupper);

    //0 - start
    //1 - sybol
    //2 - digit
    int state = 0;

    //std::cout << "\"" << Name << "\"" << std::endl;
    for(size_t i = 0; i<tmp.length(); ++i)
    {
        if((tmp[i]>= '0') && (tmp[i]<='9') && (state==2))
        {
            y = y * 10 + (tmp[i] - '0');
            state = 2;
            continue;
        }
        if((tmp[i]>= '1') && (tmp[i]<='9') && (state==1))
        {
            y = y * 10 + (tmp[i] - '0');
            state = 2;
            continue;
        }
        if((tmp[i]>= 'A') && (tmp[i]<='Z') && (state<2))
        {
            x = x * 26 + (tmp[i] - 'A' + 1);
            state = 1;
            continue;
        }
        throw std::logic_error("Error in cell name");
    }

    if (state != 2)
        throw std::logic_error("Error in cell name");

    --y;
    --x;

    if(x >= 26 || y >= 9)
        throw std::logic_error("Error in cell address");

    //a == A : y
    //1 : x
    //std::cout << Name << " " <<tmp << " " << x << " " << y << std::endl;

    return GetCell(x, y);
}

void SimpleCellStorage::SetCell(int x, int y, std::shared_ptr<ICell> cell)
{
    if(x < 0 || y < 0 || x >= this->width || y >= this->height)
        throw std::logic_error("Error in cell address");
    this->data[y][x] = cell;
}
