#include <iostream>

class Wigth
{
    public:
        virtual void disp()
        {

        }
        virtual ~Wigth(){}
};

class SpecialWidget: public Wigth
{
    void disp()
    {
        std::cout << "disp()\n";
    }
};

void update(SpecialWidget *in)
{

}

void updateViaRef( SpecialWidget &in)
{

}

int func()
{
    std::cout<< "func\n";
    return 1;
}

using FuncPtr = void(*)();

int main(int, char**) {
/*****
 * 
 * static_cast
 * 
 * *****/
    int fristNumber{5}, secondNumber{2};
    //C language
    double result = ((double) fristNumber) / secondNumber;
    //C++
    double re = static_cast<double>(fristNumber) / secondNumber;
    std::cout << "result: " << result <<", re: "<<re<<'\n';


/*****
 * 
 * const_cast
 * 
 * *****/
    SpecialWidget sw;
    const SpecialWidget & csw = sw;

    //update(&csw); 
    //C++
    update(const_cast<SpecialWidget*>(&csw));
    //C
    update((SpecialWidget*)&csw);

/*****
 * 
 * dynamic_cast
 * 
 * *****/
    Wigth *pw  = new SpecialWidget;
    update(dynamic_cast<SpecialWidget*>(pw));
    updateViaRef(dynamic_cast<SpecialWidget&>(*pw));
    delete pw;

/*****
 * 
 * reinterpret_cast
 * 
 * *****/
    FuncPtr a;
    a = reinterpret_cast<FuncPtr>(&func);
    a();

}
