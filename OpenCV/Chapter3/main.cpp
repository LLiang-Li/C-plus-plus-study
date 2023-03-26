#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
#include<stdio.h>

//#define LOG_TAG(TAG, FORMAT, ...) ::fprintf(stdout, "[%s][" TAG "](%s:%d): " FORMAT "\r\n", ((char*)::frp::GetCurrentTimeText<std::string>().data()), __FILE__, __LINE__, __VA_ARGS__)
#define LOG_TAG(TAG, FORMAT, ...) ::fprintf(stdout, "[" TAG "](%s:%s:%d): \n" FORMAT "\r\n", __TIME__, __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_INFO(FORMAT, ...) LOG_TAG("INFO", FORMAT, ##__VA_ARGS__)


class Myenum
{
 public:
  enum{
    A = 0,
    B = 1,
    C = 1
  };
  void print()
  {
    std::cout << 123;
  }
};

int main(int argc, char** argv)
{
  cv::Point s(1,2);
  std::cout << s.x << ", " << s.y <<std::endl;

  cv::Scalar scal(1.1,2.2,3.2,4.4);
  auto ss = static_cast<cv::Scalar_<int>>(scal);
  std::cout << scal[0] << ", " << ss[1] <<std::endl;
  auto res = scal.mul(ss);
  LOG_INFO("%d,%f",res[0],res[1]);
  
  cv::Size size(1,1);
  LOG_TAG("INFO", "%d",1);
  LOG_INFO("%d, %d",size.height,size.width);

  cv::Rect r(1,2,3,4);
  LOG_INFO("x = %d", r.tl().x);

  LOG_INFO("--------------------------------");
  cv::RotatedRect RR(cv::Point2f(0,0),cv::Size(1,1), 45);
  cv::Point2f pr[4];
  RR.points(pr);
  LOG_INFO("x = %f, y = %f", pr->x, pr->y);
  LOG_INFO("x = %f, y = %f", (pr+1)->x, (pr+1)->y);
  LOG_INFO("x = %f, y = %f", (pr+2)->x, (pr+2)->y);
  LOG_INFO("x = %f, y = %f", (pr+3)->x, (pr+3)->y);

  //用与固定矩阵  
  cv::Matx22f M22f;

  //终止条件判断，可选择最大迭代次数和误差
  cv::TermCriteria TC;

  //连续的序列，设置最大和最小值
  cv::Range range;

  //OpenCV的智能指针
  cv::Ptr<int> Int(new int(10));
  LOG_INFO("value = %d", *Int);  

  //数据类型的模板
  cv::DataType<int> DT;

  std::cout << std::endl;

  std::cout << Myenum::A << Myenum::B << Myenum::C << std::endl;
  Myenum{}.print();
  std::cout << '\n' << sizeof(Myenum);
  return 0;
}
