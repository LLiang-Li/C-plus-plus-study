#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <iostream>
class Picture
{
    public:
        Picture():height(0),width(0),data(NULL){};
        Picture(const char* const *,int);
        Picture(const Picture &);
        ~Picture(){delete data;};
        Picture & operator=(const Picture&);
        static int max(int m, int n);
    private:
        int height, width;
        char *data;
        char & position(int row, int col);
        char position(int row,int col)const;
        void init(int h, int w);
        void clear(int, int, int, int);
        void copyblock(int, int, const Picture &);
        friend std::ostream& operator<<(std::ostream &, const Picture &);
        friend Picture frame(const Picture&);
        friend Picture operator&(const Picture&, const Picture &);
        friend Picture operator|(const Picture&, const Picture &);
};   

std::ostream& operator<<(std::ostream &, const Picture &);

Picture frame(const Picture&);

Picture operator&(const Picture&, const Picture &);

Picture operator|(const Picture&, const Picture &);
#endif