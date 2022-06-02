#include <iostream>
#include <string>

class Expr_node;
class Int_node;
class Unary_node;
class Binary_node;

class Expr{
    friend std::ostream& operator<<(std::ostream&, const Expr &);
    
    public:
        Expr_node *p;
        Expr(int n){ p = new Int_node(n);}
        // Expr(const std::string &op,Expr t){ p = new Unary_node(op, t);}
        // Expr(const std::string &op, Expr l, Expr r){ p = new Binary_node(op, l, r);}
        Expr(const Expr&t){ p = t.p; ++p->use;}
        Expr& operator=(const Expr &rhs)
        {
            std::cout <<"-----------\n";
            rhs.p->use++;
            if (--p->use == 0)
                delete p;
            p = rhs.p;
            return *this;
        }
        ~Expr(){delete p;}
};

class Expr_node
{
        friend std::ostream& operator<<(std::ostream &os, const Expr &);
        friend class Expr;
        int use;
    protected:
        Expr_node():use(1){}
        
        virtual ~Expr_node(){};
   
        virtual void print(std::ostream &) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Expr &t){
    t.p->print(os);
    return os;
};


class Int_node:public Expr_node
{
    friend class Expr;
    int n;
    Int_node(int k) : n(k){};
    void print(std::ostream &os) const {os<< n;}
};

class Unary_node:public Expr_node
{
    friend class Expr;
    std::string op;
    Expr opnd;
    Unary_node(const std::string &a):op(a) {};
    void print(std::ostream &os) const {os<< '(' << op  <<')';}
};

// class Binary_node: public Expr_node
// {
//     friend class Expr;
//     std::string op;
//     Expr left;
//     Expr right;
//     Binary_node(const std::string a, Expr l, Expr r):op(a),left(l),right(r){}
//     void print(std::ostream &os)const{os <<'('<<left << op<< left<<')';}
// };



int main(int, char**) {
    // Expr t = Expr("*",6,Expr("+",5,3));
    // std::cout << t<<std::endl;
}
