了解不同意义上new和delete
operator new(data type)相当于C中malloc
operator delete(ptr) 相当于C中free


对于new的使用：
1、当需要分配内存并且初始化对象是需要使用：
    new operator
2、当只需要分配内存时，不需要初始化时需要使用：
    operator new
3、当需要按照自己的方式分配内存是需要重载类中的：
    new operator(size_t,...)