#ifndef _OUTPUT_
#define _OUTPUT_
#include<iostream>

template<class T>
class ostream_iter
{
    public:
        ostream_iter(std::ostream &os, const char *s): strm(&os), str(s) {};
        ostream_iter& operator++() {return *this;}
        ostream_iter& operator++(int) {return *this;}
        ostream_iter& operator*() {return *this;}
        ostream_iter& operator=(const T & t )
        {
            *strm << t << str;
            return *this;
        }
    private:
        std::ostream * strm;
        const char *str;
};

#endif