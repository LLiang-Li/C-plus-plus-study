#ifndef _Header_H_
#define _Header_H_

#include <iostream>

template<class T> class Seq_item;

template<class T>
class Seq
{
    public:
        Seq();
        Seq(const T&, const Seq<T>&);
        Seq(const Seq&);
        ~Seq();
        Seq<T>& operator=(const Seq<T>&);
        T hd() const;
        operator bool() const;
        Seq<T> tl()const;
    private:
        void destory(Seq_item<T> *);
        Seq(Seq_item<T>*);
        Seq_item<T>* item;
};

template<class T>
class Seq_item
{
    friend class Seq<T>;
    
    int use;
    const T data;
    Seq_item<T> *next;

    Seq_item(const T& t, Seq_item<T>* s);
    Seq_item(const T& t):use(1),data(t),next(0){};

    ~Seq_item();

};

/*             */
//Seq_iteam
/*             */
template<class T>
Seq_item<T>::Seq_item(const T& t, Seq_item<T> *s):
        use(1),next(s),data(t)
{
    if (s)
        s->use++;
}

template<class T>
Seq_item<T>::~Seq_item()
{
    //delete this->data;
}

/*             */
//Seq
/*             */

template<class T>
Seq<T>::Seq():item(0){}

template<class T>
Seq<T>::Seq(const T &t, const Seq<T>& s):item(new Seq_item<T>(t,s.item) ){}

template<class T>
Seq<T>::operator bool()const
{
    return this->item != 0;
}

template<class T>
Seq<T>::Seq(const Seq<T> &rhs):item(rhs.item)
{
    if(item)
        this->item->use++;
}

template<class T>
T Seq<T>::hd()const
{
    if(this->item)
        return this->item->data;
    else
        throw "hd of an empty Seq";
}

template<class T>
Seq<T>::Seq(Seq_item<T>* s):item(s)
{   
    if (item)
        this->item->use++;
}

template<class T>
Seq<T> Seq<T>::tl()const
{
    if (item)
        return Seq<T>(this->item->next);
    else
        throw "t1 is empty";
}

template<class T>
Seq<T>& Seq<T>::operator=(const Seq<T> &rhs)
{
    if(rhs.item)
        rhs.item->use++;
    destory(this->item);
    this->item = rhs.item;
    return *this;
}

template<class T>
void Seq<T>::destory(Seq_item<T>* item)
{
    while (item && --(item->use)==0)
    {
        Seq_item<T> *next = item->next;
        delete item;
        item = next;
    }
}

template<class T>
Seq<T>::~Seq()
{
    destory(item);
}

#endif