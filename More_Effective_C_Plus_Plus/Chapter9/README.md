利用Destructors避免资源泄露
使用在堆上开辟空间是，需要new和delete成对出现，有时候出现异常时导致new后delete没有执行，因此，建议使用类的析构函数来调用delete来释放堆上空间。使用以下类去封装

tempate<class T>
class auto_ptr
{
    public:
        auto_ptr(T *p=0):ptr(p){}
        ~auto_ptr(){delete ptr;}
    private:
        T *ptr;
}