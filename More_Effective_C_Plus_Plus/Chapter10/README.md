在constructors内阻资源泄露
当类中存在指针时，且需要开辟空间时，类的构造函数：
    可能由于异常导致构造失败，但指针开辟在堆的空间可能无法释放导致内存泄漏
如下类
class demo
{
    public:
        demo(int intsize, int doublesize):myInt(new int[insize]),myDouble(new double[doublesize]){}
    private:
        int * myInt;
        double* myDouble
}
上类中myDouble抛出异常时，demo类创建失败，而myInt创造的空间无法释放，导致内存泄漏
可以做如下初始化：
demo(int intsize, int doublesize):myInt(0),myDouble(0])
{
    try
    {
        this->myInt = new int[insize];
        this->myDouble = new double[doublesize];
    }
    catch(...)
    {
        delete [] myInt;
        delete [] myDouble;
    }
}

另外一种就是使使用智能指针