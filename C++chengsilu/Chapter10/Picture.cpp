#include "Picture.h"
//function
static void pad(std::ostream &os, int x, int y)
{
    for (int i = x; i < y; i++)
        os <<" ";
}


/***************************/
//Picuture
/***************************/
Picture::Picture(const Picture &orig):p(orig.p)
{
    orig.p->use++;
}

Picture::Picture(const char* const *p, int n):p(new String_Pic(p,n))
{

}

Picture::Picture(P_Node *node):p(node){}

Picture::~Picture()
{
    if (--p->use == 0)
        delete p;
}

Picture& Picture::operator=(const Picture & orig)
{
    orig.p->use++;
    if (--(this->p->use) == 0)
        delete this->p;
    this->p = orig.p;
    return *this;
}

int Picture::height() const
{
    return p->height();
}

int Picture::width() const
{
    return p->width();
}

void Picture::display(std::ostream& o, int x, int y)const
{
     p->display(o, x, y);
}

/***************************/
//P_Node
/***************************/
int P_Node::max(int x, int y)
{
    return x > y ? x : y;
}

int P_Node::max(int x, int y)const
{
    return x > y ? x : y;
}

P_Node::~P_Node(){}

/***************************/
//String_Pic
/***************************/
String_Pic::String_Pic(const char* const * p, int n):data(new char *[n]) , size(n)
{
    for (int i = 0; i < n; i++)
    {
        data[i] = new char(strlen(p[i])+1);
        strcpy(data[i], p[i]);
    }
}

String_Pic::~String_Pic()
{
    for (int i = 0; i < this->size; i++)
    {
        delete [] data[i];
    }
    delete []data;
}

int String_Pic::height() const
{
    return this->size;
}

int String_Pic::width() const
{
    int n = 0;
    for (int i = 0; i < this->size; i++)
        
        n = this->max(n,(int)strlen(data[i]));
    return n;   
}

void String_Pic::display(std::ostream& os, int row, int width) const
{
    int start = 0;
    if (row >= 0 && row < this->height())
    {
        os << data[row];
        start = strlen(data[row]);
    }
    pad(os, start, width);
}

/***************************/
//Frame_Pic
/***************************/
Frame_Pic::Frame_Pic(const Picture& pic):p(pic){}

int Frame_Pic::height() const
{
    return p.height() + 2;
}

int Frame_Pic::width() const
{
    return p.width() + 2;
}

void Frame_Pic::display(std::ostream& os, int row, int wd) const
{
    if (row < 0 || row >= height())
    {
        pad(os, 0, wd);
    }else{
        if (row == 0 || row == height() -1 )
        {
            os << "+";
            int i = p.width();
            while (--i >=0)
                os << "-";
            os << "+";
        }else{
            os << "|";
            p.display(os, row -1, p.width());
            os << "|";
        }
        pad(os,width(),wd);
    }
}

/***************************/
//Vcat_Pic
/***************************/
Vcat_Pic::Vcat_Pic(const Picture& t, const Picture&b):top(t), bottom(b) {}

int Vcat_Pic::height() const
{
    return top.height() + bottom.height();
}

int Vcat_Pic::width() const
{
    return max(top.width(), bottom.width());
}

void Vcat_Pic::display(std::ostream& os, int row, int wd) const
{
    if (row >= 0 && row < top.height())
        top.display(os, row, wd);
    else if (row < top.height() + bottom.height())
        bottom.display(os, row - top.height(), wd);
    else
        pad(os, 0, wd);
}

/***************************/
//Hcat_Pic
/***************************/
Hcat_Pic::Hcat_Pic(const Picture& l, const Picture&r):left(l), right(r) {}

int Hcat_Pic::height() const
{
    return max(left.height(), right.height());
}

int Hcat_Pic::width() const
{
    return right.width() + left.width();
}

void Hcat_Pic::display(std::ostream& os, int row, int wd) const
{
    left.display(os, row, left.width());
    right.display(os, row, right.width());
    pad(os, width(),wd);
}

/***************************/
//firend function
/***************************/
Picture frame(const Picture& pic)
{
    return new Frame_Pic(pic);
}

Picture operator&(const Picture& t, const Picture & b)
{
    return new Vcat_Pic(t,b);
}

Picture operator|(const Picture&l, const Picture &r)
{
    return new Hcat_Pic(l,r);
}

std::ostream& operator<<(std::ostream & os, const Picture & picture)
{
    int ht = picture.height();
    for (int i = 0; i < ht; i++)
    {
        picture.display(os, i, 0);
        //picture.height()
        os <<std::endl;
    }
    return os;
}