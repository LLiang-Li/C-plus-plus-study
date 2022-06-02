#include <iostream>

class Window
{
    public:
        Window(std::string na) : name(na){};
        virtual void display() const{
            std::cout << this->name<<std::endl;
        }

    protected:
        int va;
    private:
        std::string name;
};

class Bars:public Window
{
    private:
        std::string br;
    public:
        Bars(std::string bar, std::string nam):br(bar),Window(nam){};
        virtual void display() const{
            std::cout << this->br<<std::endl;
        };

};

void print(Window &w)//pass by reference or value, 
{
    //std::cout <<w.name<<'\n';
    w.display();
}

class test{
    public:
        int a;
        int b;
        std::string name;
        void te(){};
};


int main(int, char**) {


    Bars ww("Bar","win");
    print(ww);

    std::cout <<'\n';
    test s;
    std::cout <<sizeof(int)<< ", "<< sizeof(std::string)<<", "<<sizeof(char*)<<", "<<sizeof(int*)<<'\n';
    std::cout <<sizeof(s)<<'\n';
    
    std::cout << "Hello, world!\n";
}
