Cpplint.py可以检查代码风格

## C++特性
# 参数引用
尽量使用const

# 右值引用
右值引用是一种只能绑定到临时对象的引用的一种, 其语法与传统的引用语法相似. 例如, void f(string&& s); 声明了一个其参数是一个字符串的右值引用的函数.
右值可实现指移动不拷贝的优点，例如， v1 是一个 vector<string>, 则 auto v2(std::move(v1)) 将很可能不再进行大量的数据复制而只是简单地进行指针操作, 在某些情况下这将带来大幅度的性能提升.
移动构造函数与移动赋值操作时使用右值引用, 不要使用 std::forward 功能函数. 你可能会使用 std::move 来表示将值从一个对象移动而不是复制到另一个对象.

# 函数重载
一般构造函数会有很多重载，构造函数重载使用同一个名字。
其它，打算重载一个函数, 可以试试改在函数名里加上参数信息。例如，用 AppendString() 和 AppendInt() 等， 而不是一口气重载多个 Append().

# 缺省参数
不建议使用缺省参数，尽量使用函数重载，主要原因是缺省参数会影响函数指针
一下几种情况可以使用：
其一，位于 .cc 文件里的静态函数或匿名空间函数，毕竟都只能在局部文件里调用该函数了。
其二，可以在构造函数里用缺省参数，毕竟不可能取得它们的地址。
其三，可以用来模拟变长数组。如下 ：
string StrCat(const AlphaNum &a,
              const AlphaNum &b = gEmptyAlphaNum,
              const AlphaNum &c = gEmptyAlphaNum,
              const AlphaNum &d = gEmptyAlphaNum);

# 变长数组和 alloca()
不允许使用，原因：
变长数组和 alloca() 不是标准 C++ 的组成部分. 更重要的是, 它们根据数据大小动态分配堆栈内存, 会引起难以发现的内存越界 bugs: “在我的机器上运行的好好的, 发布后却莫名其妙的挂掉了”.
建议使用分配器，std::vector或者std::unique<T>

# 友元
允许合理的使用友元，友元扩大了类的封装边界（但没有打破），相比如将类的成员声明成public，使用友元将是更好的选择

# RTTI和异常
不建议异常使用：异常的处理需要严格的处理，google现有的项目大多数没有异常处理
RTTI容易被乱用：
基于类型的判断树是一个很强的暗示, 它说明你的代码已经偏离正轨了. 不要像下面这样:
if (typeid(*data) == typeid(D1)) {
  ...
} else if (typeid(*data) == typeid(D2)) {
  ...
} else if (typeid(*data) == typeid(D3)) {
...
一旦在类层级中加入新的子类, 像这样的代码往往会崩溃. 而且, 一旦某个子类的属性改变了, 你很难找到并修改所有受影响的代码块.

# 类型转换
不要使用C的强制转换类型，建议使用C++的数据类型转黄
用 static_cast 替代 C 风格的值转换, 或某个类指针需要明确的向上转换为父类指针时.
用 const_cast 去掉 const 限定符.
用 reinterpret_cast 指针类型和整型或其它指针之间进行不安全的相互转换. 仅在你对所做一切了然于心时使用.

# 流
多使用流。
只有在如下情况使用printf：日志接口需要. 使用 printf 之类的代替.

# 前置自增和自减
尽量使用前置，后自加还需要考虑拷贝带来的效率损失

# const用法
能使用const的地方建议使用const，建议将const放在类型前面，即const T *，不建议T const *

# 整型
通常假定 short 是 16 位, int 是 32 位, long 是 32 位, long long 是 64 位.
不要使用 uint32_t 等无符号整型, 除非你是在表示一个位组而不是一个数值, 或是你需要定义二进制补码溢出. 尤其是不要为了指出数值永不会为负, 而使用无符号类型. 相反, 你应该使用断言来保护数据.
小心整型类型转换和整型提升（acgtyrant 注：integer promotions, 比如 int 与 unsigned int 运算时，前者被提升为 unsigned int 而有可能溢出），总有意想不到的后果。

# 预处理宏
宏时要非常谨慎, 尽量以内联函数, 枚举和常量代替之.
主要有以下建议：
不要在 .h 文件中定义宏.
在马上要使用时才进行 #define, 使用后要立即 #undef.
不要只是对已经存在的宏使用#undef，选择一个不会冲突的名称；
不要试图使用展开后会导致 C++ 构造不稳定的宏, 不然也至少要附上文档说明其行为.
不要用 ## 处理函数，类和变量的名字。

# sizeof
尽可能用 sizeof(varname) 代替 sizeof(type).

# auto
用 auto 绕过烦琐的类型名，只要可读性好就继续用，别用在局部变量之外的地方。
auto x(3);  // 圆括号。
auto y{3};  // 大括号。
它们不是同一回事——x 是 int, y 则是 std::initializer_list<int>. 
永远别列表初始化 auto 变量

# 列表初始化
千万别直接列表初始化 auto 变量，看下一句，估计没人看得懂：
auto d = {1.23};        // d 即是 std::initializer_list<double>
auto d = double{1.23};  // 善哉 -- d 即为 double, 并非 std::initializer_list.

# Lambda
使用 lambda 表达式。别用默认 lambda 捕获，所有捕获都要显式写出来。
[=](int x) {return x + n;}, 您该写成 [n](int x) {return x + n;} 才对

# 模板
模板编程所使用的技巧对于使用c++不是很熟练的人是比较晦涩, 难懂的. 在复杂的地方使用模板的代码让人更不容易读懂, 并且debug 和 维护起来都很麻烦

## 命名约定
# 通用命名规则
函数命名, 变量命名, 文件命名要有描述性; 少用缩写.

# 文件命名
文件名要全部小写, 可以包含下划线(_)或连字符(-)，依据项目的约定。如果没有约定，那么"-"更好

# 类型命名
类型名称的每个单词首字母均大写, 不包含下划线: MyExcitingClass, MyExcitingEnum.
所有类型命名 —— 类, 结构体, 类型定义 (typedef), 枚举, 类型模板参数 —— 均使用相同约定, 即以大写字母开始, 每个单词首字母均大写, 不包含下划线

# 变量命名
总述：变量 (包括函数参数) 和数据成员名一律小写, 单词之间用下划线连接. 类的成员变量以下划线结尾, 但结构体的就不用,
普通变量命名：
string table_name;  // 好 - 用下划线.
string tablename;   // 好 - 全小写.
string tableName;  // 差 - 混合大小写
类数据成员：
class TableInfo {
  ...
 private:
  string table_name_;  // 好 - 后加下划线.
  string tablename_;   // 好.
  static Pool<TableInfo>* pool_;  // 好.
};

# 结构体变量
不管是静态的还是非静态的, 结构体数据成员都可以和普通变量一样, 不用像类那样接下划线:
struct UrlTableProperties {
  string name;
  int num_entries;
  static Pool<UrlTableProperties>* pool;
};

# 常量命名
声明为 constexpr 或 const 的变量, 或在程序运行期间其值始终保持不变的, 命名时以 “k” 开头, 大小写混合. 例如:
const int kDaysInAWeek = 7;

# 函数命名
常规函数使用大小写混合, 取值和设值函数则要求与变量名匹配: MyExcitingFunction(), MyExcitingMethod(), my_exciting_member_variable(), set_my_exciting_member_variable().

# 命名空间
命名空间以小写字母命名. 最高级命名空间的名字取决于项目名称. 要注意避免嵌套命名空间的名字之间和常见的顶级命名空间的名字之间发生冲突.

# 宏命名
枚举的命名应当和 常量 或 宏 一致: kEnumName 或是 ENUM_NAME.
