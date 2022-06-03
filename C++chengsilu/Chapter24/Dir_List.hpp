#ifndef _DIR_LIST_
#define _DIR_LIST_
#include <dirent.h>

class Dir_offset
{
    friend class Dir;
    long l;
    Dir_offset(long n): l(n){}
    operator long(){return this->l;}
};

class Dir
{
    public:
        Dir(const char*);
        int read(dirent &);
        void seek(Dir_offset);
        Dir_offset tell()const;
        ~Dir();
    private:
        DIR* dp;
        Dir(const Dir &);
        Dir& operator=(const Dir&);
};

Dir::Dir(const char* file):dp(opendir(file)){}

Dir::~Dir()
{
    if(this->dp)
        closedir(this->dp);
}   

void Dir::seek(Dir_offset pos)
{
    if (dp)
        seekdir(dp, pos);
}

Dir_offset Dir::tell()const{
    if(dp)
        return telldir(this->dp);
    return -1;
}

int Dir::read(dirent &d)
{
    if (this->dp)
    {
        dirent* r = readdir(this->dp);
        if(r)
        {
            d = *r;
            return 1;
        }
    }
    return 0;
}

#endif