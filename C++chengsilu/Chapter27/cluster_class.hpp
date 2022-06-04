#ifndef _CLUSTER_CLASS_
#define _CLUSTER_CLASS_
#include <iostream>

class Clusteritem;

class Cluster
{
    friend class Clusteritem;
    public:
        Cluster():head(0){};
        ~Cluster();
    private:
        Clusteritem* head;
        Cluster(const Cluster&);
        Cluster& operator=(const Cluster&);
};

static Cluster *cp;

class Clusteritem
{
    friend class Cluster;
    public:
        void* operator new(size_t n, Cluster& c)    
        {
            std::cout <<n <<'\n';
            cp = &c;
            return ::operator new(n);
        };
        Clusteritem()
        {
            next = cp->head;
            cp->head = this;
        };
    protected:
        virtual ~Clusteritem(){};
    private:
        Clusteritem* next;
        void* operator new(size_t)
        {
            std::abort();
            return 0;
        };
        Clusteritem(const Clusteritem&);
        Clusteritem& operator=(const Clusteritem&);
};

Cluster::~Cluster()
        {
            while(head)
            {
                Clusteritem* next = head->next;
                delete head;
                head = next;
            }
        };
#endif