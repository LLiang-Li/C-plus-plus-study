#ifndef _CONST_ITER_
#define _CONST_ITER_

class Constant_iterator
{
    public:
        Constant_iterator(int);
        int operator*()const;
        Constant_iterator& operator++();
        Constant_iterator operator++(int);
    private:
        int n;
        int counter;
        friend int operator==(const Constant_iterator&, const Constant_iterator&);
        friend int operator!=(const Constant_iterator&, const Constant_iterator&);
        friend Constant_iterator operator+(const Constant_iterator&, int);
        friend Constant_iterator operator+(int, const Constant_iterator&);
};

Constant_iterator::Constant_iterator(int k):n(k), counter(0) {}

int Constant_iterator::operator*() const{ return n;}

Constant_iterator& Constant_iterator::operator++()
{
    ++(this->counter);
    return *this;
}

Constant_iterator Constant_iterator::operator++(int)
{
    Constant_iterator r = *this;
    ++(this->counter);
    return r;
}

Constant_iterator operator+(const Constant_iterator& rhs, int n)
{
    Constant_iterator r = rhs;
    r.counter += n;
    return r;
}

Constant_iterator operator+(int n, const Constant_iterator& rhs)
{
    return rhs + n;
}

int operator==(const Constant_iterator& p, const Constant_iterator& q)
{
    return ((p.n == q.n)&&(p.counter == q.counter));
}

int operator!=(const Constant_iterator& q, const Constant_iterator& p)
{
    return !(p == q);
}

#endif