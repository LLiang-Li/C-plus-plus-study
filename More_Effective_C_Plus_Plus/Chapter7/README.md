不要重载&&、||和,操作符

针对&&和||重载操作
一般情况如下：
char *p;
...
if (p != 0)&&(strlen(p) > 10)
以上如果p = 0，那么后面的strlen不会执行

当你重载operator&&s时
if(expression1 && expression2) ...
会被编译器识别成：
if(expression1.operator&&(expression2))    //其中operator&&是类成员函数
if(operator&&(expression1， expression2))    //其中operator&&是全局函数
此时会有两个问题，执行&&的重载函数时expression已经被执行过，不会像一般情况那样可能只会执行部分，
另外，也无法确定expression的执行先后顺序。这两个问题会留下隐患，导致不确定的结果。


针对，的重载操作：
重在，操作符可能带来意想不到的结果，例子：
void recerse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; 
        i < j;
        ++i, --j)
    {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
其中for循环中++i,--j极有可能出现operator,(...)的重载，应该避免此情况