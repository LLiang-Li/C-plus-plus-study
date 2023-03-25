#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
#include<stdio.h>

//#define LOG_TAG(TAG, FORMAT, ...) ::fprintf(stdout, "[%s][" TAG "](%s:%d): " FORMAT "\r\n", ((char*)::frp::GetCurrentTimeText<std::string>().data()), __FILE__, __LINE__, __VA_ARGS__)
#define LOG_TAG(TAG, FORMAT, ...) ::fprintf(stdout, "[" TAG "](%s:%d): " FORMAT "\r\n", __FILE__, __LINE__, __VA_ARGS__)

int main(int argc, char** argv)
{
  cv::Point s(1,2);
  std::cout << s.x << ", " << s.y <<std::endl;

  cv::Scalar scal(1.1,2.2,3.2,4.4);
  auto ss = static_cast<cv::Scalar_<int>>(scal);
  std::cout << scal[0] << ", " << ss[1] <<std::endl;

  cv::Size size(1,1);

  std::cout << std::endl;
  return 0;
}
