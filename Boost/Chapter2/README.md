# 几种时间的类
## 计时器
timer、progress_timer和progress_diaplay
其中timer需要调用elapsed显示时间
process_timer的析构函数会显示时间
progress_display使用operator+会显示进度，但有个缺点，其它打印会影响显示

## 日期
侧重于年月日
date用于显示日期，不包含时间
date_duration和date_period主要用于显示时间段

## 时间
侧重于时分秒
time_duration用于时间度量可使用hours、minutes、seconds和millisec构造
ptime用于时间点

# 重载
## 可以重载 operator ""来减缓
days opeartor"" _D (unsigned long long n)
{
    return days(n);
}

int main()
{
    auto d = 100_D;
}

