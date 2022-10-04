禁止异常的流出destructors之外
调用destructors的两种情况：
1、对象在正常情况下销毁，离开了作用域或被明确删除
2、当对象被exception处理机制————也就是exception传播过程中的stack-unwinding（栈被展开）机制————销毁

不要再析构函数中抛出异常，异常不会被类的destructor捕捉，会destructor的调用端，但这destructor可能会被别的exception调用，则terminate会被调用，程序会崩溃。