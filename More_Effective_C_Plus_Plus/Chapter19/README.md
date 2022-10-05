了解临时对象的来源
以下不是临时变量是局部变量：
template<class T>
void swap(T& o1, T& o2)
{
    T temp = o1;
    o1 = o2;
    o2 = temp;
}

真正的临时对象不会出现在代码中。

当对象以by value方式传递时，或已对象传递给reference-to-const参数时会产生临时对象
void uppercasify(const std::string &str);
char str[] = "more effective c++";
uppercasify(str);
此时会产生临时对象

当时，当函数被定义为：
void uppercasify(std::string &str);
会出现错误，由于str形参可能和实参不一致，可能导致错误，不会复制临时对象