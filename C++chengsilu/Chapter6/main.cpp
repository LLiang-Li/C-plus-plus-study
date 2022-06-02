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

class UPoint
{
    friend class Hanlde;
    int n;
    Point p;
    UPoint():p(0,0), n(1){};
    UPoint(int x, int y):p(x,y),n(1){};
    UPoint(const Point &rhs):p(rhs),n(1){};
};

class Hanlde{
    public:
        Hanlde():up(new UPoint){};
        Hanlde(int x, int y):up(new UPoint(x,y)){};
        Hanlde(const Point rhs):up(new UPoint(rhs)){};
        Hanlde(const Hanlde &rhs):up(rhs.up){++up->n;};
        Hanlde & operator=(const Hanlde &rhs)
        {
            rhs.up->n++;
            if (--up->n == 0)
                delete this->up;
            this->up = rhs.up;
            return *this;
        }
        int x() const
        {
            return up->p.x();
        }

        int y() const
        {
            return up->p.y();
        }

        Hanlde& x(int value)
        {
            if(this->up->n != 1)
            {
                this->up->n--;
                this->up = new UPoint(up->p);
            }
            this->up->p.x(value);
            return *this;
        }

        Hanlde& y(int value)
        {
            if(this->up->n != 1)
            {
                this->up->n--;
                this->up = new UPoint(up->p);
            }
            this->up->p.y(value);
            return *this;
        }
        int n()
        {
            return up->n;
        }

        ~Hanlde()
        {
            if (--up->n == 0)
            {
                delete up;
            }

        }
    private:
        UPoint *up;
};

class Tes
{
    public:
        Tes():x(0),y(0){
            std::cout << "Tes()\n";
        };
        Tes(int xv, int yv):x(xv),y(yv){
            std::cout << "Tes(int, int)\n";
            };
        Tes(const Tes &rhs){
            this->x = rhs.x; 
            this->y = rhs.y;
            std::cout << "Tes(const TEs &)\n";
            }
        Tes & set_x(int xv)
        {
            this->x = xv;
            return *this;
        }

    private:
        int x,y;
};

int main(int, char**) {
   
    // Hanlde h(3,4);
    // Hanlde h1 = h;
    // std::cout << h.x()<<":"<<h.n()<<std::endl;
    
    // {
    //     Hanlde h2 = h1;
    //     std::cout << h.x()<<":"<<h.n()<<std::endl;
    // }
    // std::cout << h.x()<<":"<<h.n()<<std::endl;
    // h1.x(5);
    // std::cout << h.x()<<":"<<h.n()<<std::endl;
    // std::cout << h1.x()<<":"<<h1.n()<<std::endl;


    Tes t;
    t.set_x(2).set_x(3);
    return 0;
}
