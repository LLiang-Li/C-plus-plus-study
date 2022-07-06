#include <iostream>

class BST
{
    public:
        virtual void disp()const {std::cout << "base()\n";};
        virtual ~BST(){}
     private:
          int b;
          int c;
          int d;
};

class BalancedBST: public BST
{
    public:
        void disp()const
        {
            std::cout << "disp()\n";
        }
    private:
         int a;
         int b;
        // int c;
        //int A{20};
};

void printBAST(const BST arry[], int num)
{
    for (int i = 0; i < num; i++)
        arry[i].disp();
}
int main(int, char**) {
    BST arr[10];
    //printBAST(arr,10);
    BalancedBST arrB[10];
    //printBAST(arrB, 10);
    std::cout << sizeof(BST) << "    "<< sizeof(BalancedBST) << "   " << sizeof(double) <<"   " << sizeof(int) << " " <<sizeof(int *)<<sizeof(float *);
}
