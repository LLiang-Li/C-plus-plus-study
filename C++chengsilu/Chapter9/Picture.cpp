#include "Picture.h"
#include <cstring>

Picture::Picture(const char* const* array, int n)
{
    int w = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        w = Picture::max(w,strlen(array[i]));
    }
    this->init(n,w);
    for(i = 0; i < n; i++)
    {
        const char* str = array[i];
        int len = strlen(str);
        int j = 0;
        while (j < len)
        {
            this->position(i,j) = str[j];
            j++;
        }
        while(j < this->width)
        {
            this->position(i,j) = ' ';
            j++;
        }
    }
}

Picture::Picture(const Picture &p):height(p.height),width(p.width),
                                    data(new char[p.height * p.width])
{
    this->copyblock(0,0,p);
}

Picture& Picture::operator=(const Picture& p){
    if (this == &p)
        return *this;
    delete[] data;
    this->init(p.height, p.width);
    this->copyblock(0, 0, p);
    return *this;
}

int Picture::max(int m, int n)
{
    return m > n ? m : n;
}

void Picture::init(int h, int w)
{
    this->height = h;
    this->width = w;
    this->data = new char[this->height * this->width];
}

char& Picture::position(int row, int col)
{
    return data[row*this->width+col];
}

char Picture::position(int row, int col)const
{
    return data[row*this->width+col];
}

void Picture::copyblock(int row, int col, const Picture & p)
{
    for(int i = 0; i < p.height;i++)
        for (int j = 0; j < p.width; j++)
            this->position(i+row, j+col) = p.position(i,j);
}

void Picture::clear(int r1, int  c1, int r2, int c2){
    for (int i =  r1; i < r2; i++)
        for (int j = c1; j < c2; j++)
            this->position(i,j) = ' ';
}

std::ostream& operator<<(std::ostream &os, const Picture &val){
    for(int i = 0; i < val.height; i++)        {
        for(int j = 0; j < val.width; j++)
            std::cout << val.position(i,j);
        os << '\n';
    }
    return os;
}

Picture frame(const Picture& p)
{
    Picture r;
    r.init(p.height+2, p.width + 2);
    for (int i = 0; i < r.width; i++)
    {
        r.position(0,i) = '-';
        r.position(r.height - 1,i) = '-';
    }

    for (int i = 0; i < r.height; i++)
    {
        r.position(i,0) = '|';
        r.position(i,r.width -1) = '|';
    }
    r.position(0,0) = '+';
    r.position(0,  r.width-1) = '+';
    r.position(r.height -1, 0) = '+';
    r.position(r.height -1, r.width -1) = '+';
    r.copyblock(1,1,p);
    return r;
}

Picture operator&(const Picture& p, const Picture &q)
{
    Picture r;
    r.init(p.height + q.height, Picture::max(q.width, p.width));
    r.clear(0, p.width, p.height, r.width);
    r.clear(p.height, q.width, r.height, r.width);
    r.copyblock(0,0,p);
    r.copyblock(p.height,0,q);
    return r;
}

Picture operator|(const Picture& p, const Picture &q)
{
    Picture r;
    r.init(Picture::max(p.height,q.height), q.width + p.width);
    r.clear(p.height, 0, r.height, p.width);
    r.clear(q.height, p.width, r.height, r.width);
    r.copyblock(0,0,p);
    r.copyblock(0,p.width,q);
    return r;
}