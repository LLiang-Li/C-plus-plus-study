# 注释
尽量减少注释；由于注释大多数不会坚持维护，有可能造成误导性；  

## 合适的注释
法律信息：著作权和版权声明  
提供信息的注释  
对意图的解释  
警示  
TODO是程序员认为应该做，但由于某种原因目前还没有做
放大某种不合理的部分  

## 坏注释
喃喃自语  
多余的注释  
误导性注释  
循环式注释（这个不一定）  
日志式注释  
废话注释  


## 代码重构例子
```c++
class GeneratePrinmes{
 public:
  int* generatePrimes(int MaxValue){
    if(MaxValue >= 2)
    {
      int s = MaxValue + 1;
      bool* f = new bool[s];
      int i;
      for(i = 0; i < s; i++)
        f[i] = true;
      f[0] = f[1] = false;
      for(i = 2; i < std::sqrt(s) + 1; i++)
      {
        if(f[i])
        {
          for(j = 2 * i; j < s; j += i)
            f[j] = false;
        }
      }
      int count = 0;
      for(i = 0; i < s; i++)
      {
        if(f[i])
          count++;
      }
      int* primes = new int[count];
      for(i = 0, j = 0; i < s; i++)
      {
        if(f[i])
          primes[j++] = i;
      }
      return primes;
    }
    else
      return NULL;
  }
};
```  
重构之后
```c++
class PrimeGenerator
{
 private:
  bool* cross_out_;
  int* result_;
  int size_;
 public:
  int* primeGenerator(int max_value){
    if(max_value < 2)
      return NULL;
    UncrossIntegersUpTo(max_value);
    CrossOutMultiples();
    PutUncrossedIntegersIntoReslut();
    return result_;
  }
  void UncrossIntegerUpTo(int max_value)
  {
    size_ = max_value_ + 1;
    cross_out_ =new bool[size_];
    for(int i = 2; i < size_; i++)
      cross_out_[i] = false;
  }
  void CrossOutMultiples()
  {
    int limit = DetermineIterationLimit();
    for(int i = 2; i <= limit; i++)
    {
      if(NotCross(i))
        CrossOutMultiplesOf(i);
    }
  }
  int DetermineIterationLimit()
  {
    double iterator_limit = std::sqrt(size_);
    return static_cast<int>(iterator_limit);
  }
  void CrossOutMultiplesOf(int i)
  {
    for(int multiple = 2 * i; multiple < size_; 
        multiple += i)
      cross_out_[multiple] = true;
  }
  bool NotCrossed(int i)
  {
    return cross_out_[i] = false;
  }
  void PutUncrossedIntergersIntoResult()
  {
    result = new int [NumberOfUncroessedIntergers()];
    for(int j = 0; i = 2; j < size_; i++)
      if(NotCross(i))
        result[j++] = i;
  }
  int NumberOfUncrossedIntegers()
  {
    int count = 0;
    for(int i = 2; i < size_; i++)
      count;
    return count;
  }
}
```