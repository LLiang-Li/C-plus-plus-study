#include <iostream>

class Point 
{
    public:
        //Point():x(0),y(0){};
        Point(int x_v = 0, int y_v = 0):xval(x_v),yval(y_v){};
        int x()const {return this->xval;}
        int y()const {return this->yval;}
        Point& x(int xv) {this->xval = xv; return *this;}
        Point& y(int yv) {this->yval = yv; return *this;}
    private:
        int xval,yval;
};

class UseCount
{
    public:
        UseCount():p(new int(1)){}
        UseCount(const UseCount &rhs):p(rhs.p){++*p;}
        bool only() const {return *p==1;}

        bool reattach(const UseCount& u)
        {
            ++*u.p;
            if(--*p==0)
            {
                delete p;
                p = u.p;
                return true;
            }
            p = u.p;
            return false;
        }
        bool makeonly()
        {
            if (*p ==1)
                return false;
            --*p;
            p = new int(1);
            return true;
        }
        ~UseCount(){
            if (--*p==0)
                delete p;
        }
        int ge() const
        {
            return *p;
        }
    private:
        UseCount& operator=(const UseCount& rhs);
        int *p;
};

class Handle
{
    public:
        Handle():p(new Point){};
        Handle(int x, int y):p(new Point(x,y)){}
        Handle(const Point &p0):p(new Point(p0)){}
        Handle(const Handle & h):p(h.p),u(h.u){}
        Handle& operator=(const Handle &rhs){
            if (u.reattach(rhs.u))
                delete p;
            p = rhs.p;
            return *this;
        }
        int x()
        {
            return p->x();
        }
        Handle& x(int val)
        {
            if (u.makeonly())
                p = new Point(*p);
            p->x(val);
            return *this;
        }
        int n()
        {
            return u.ge();
        }
        ~Handle(){
            if(u.only())
                delete p;
            }
    private:
        Point *p;
        UseCount u;
};

int main(int, char**) {
    Handle h(3,4);
    Handle h1 = h;
    std::cout << h.x()<<":"<<h.n()<<std::endl;
    
    {
        Handle h2 = h1;
        std::cout << h.x()<<":"<<h.n()<<std::endl;
    }
    std::cout << h.x()<<":"<<h.n()<<std::endl;
    h1.x(5);
    std::cout << h.x()<<":"<<h.n()<<std::endl;
    std::cout << h1.x()<<":"<<h1.n()<<std::endl;
}
