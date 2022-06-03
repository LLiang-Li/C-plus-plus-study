#ifndef _TEMPALTE_CLASS_
#define _TEMPALTE_CLASS_

template<class X, class Y>
class Comp_base
{
    public:
        virtual Y operator()(X) const = 0;
        virtual Comp_base* clone() const = 0;
        virtual ~Comp_base() {};
};

template<class F, class G, class X, class Y>
class Compe: public Comp_base<X, Y>
{
    public:
        Compe(F f0, G g0): f(f0), g(g0) {}
        Y operator()(X x)const {return f(g(x));}
        Comp_base<X,Y>* clone() const
        {
            return new Compe(*this);
        }
        ~Compe(){}
    private:
        F f;
        G g;
};

template<class X, class Y>
class Composition
{
    public:
        template<class F, class G> Composition(F, G);
        Composition(const Composition &);
        Composition& operator=(const Composition &);
        ~Composition();
        Y operator()(X) const;
    private:
        Comp_base<X, Y> *p;
};

template<class X, class Y>
template<class F, class G> Composition<X,Y>::Composition(F f, G g): p(new Compe<F,G,X,Y>(f, g)) {}

template<class X, class Y>
Composition<X,Y>::~Composition()
{
    delete p;
}

template<class X, class Y>
Composition<X,Y>::Composition(const Composition<X, Y> & rhs):p(rhs.p->clone()) {}

template<class X, class Y>
Composition<X,Y>& Composition<X,Y>::operator=(const Composition<X ,Y> &rhs)
{
    if (this != &rhs)
    {
        delete p;
        p = rhs.p->clone();
    }
    return *this;
}

template<class X, class Y>
Y Composition<X,Y>::operator()(X x) const
{
    return this->p->operator()(x);
}


#endif