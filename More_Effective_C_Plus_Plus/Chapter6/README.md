区别自加自减前置（prefix）和后置（postfix）形式

后置操作不要连续操作，解决此问题的方式是返回一个const的对象。
具体
...
T& operator++()
{
    ...
    return ...;
}

const T operator++(int)
{
    ...
    return ...;
}

另外，后置操作符会创建对象，可能会影响效率。