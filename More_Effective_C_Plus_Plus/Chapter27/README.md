要求（或禁止）对象产生于heap之中
主要有三部分：
1、要求对象产生于heap中
    主要的方式将析构声明成private，由于无法调用析构无法分配到stack，如果改成构造则需要将很多函数声明成private

2、判断对象位于heap
    建议的方式封装基类，保存在一个静态成员之中

3、禁止对象位于heap中
    需要将operator new和operator delete声明成静态private