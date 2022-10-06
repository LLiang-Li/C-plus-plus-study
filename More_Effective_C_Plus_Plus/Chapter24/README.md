virtual function、multiple inheritance、virtual base classes、runtime type idnetification的成本
其中虚函数由于会构造虚函数的原因比较占用空间
拥有虚函数的对象可能布局如下：
|-------------------|
|    Data Members   |
|       for         |
|    the object     |
|-------------------|
|   Object's vptr   |
|-------------------|

多重继承导致虚拟继承
例如：
class A {...}
class B: virtual public A{...}
class C: virtual public A{...}
class D: public B, public C {...}

布局将会是菱形图如下
        A
      ↗  ↖
    B       C
      ↖  ↗
        D
而对象D的布局可能如下：
|-------------------------------|
|          B Data Members       |
|-------------------------------|
|Pointer to virtual base class  |
|-------------------------------|
|         C Data Members        |
|-------------------------------|
|Pointer to virtual base class  |
|-------------------------------|
|         D Data Members        |
|-------------------------------|
|             vptr              |
|-------------------------------|
|         A Data Members        |
|-------------------------------|