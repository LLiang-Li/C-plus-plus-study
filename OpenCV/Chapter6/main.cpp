#include<iostream>
#include<opencv2/opencv.hpp>
#include<Log.h>
#include"get_img_data.h"
/*
cv::cicle()画圆
cv::clipLine()判断给定曲线是否在矩形内
cv::elipse()画一个椭圆
cv::elipse2Ploy()计算近似椭圆的多边形
cv::fillConvexPoly()画一个简单填充的多边形
cv::fillPoly()画一个填充的任意多边形
cv::line()画一条简单的直线
cv::rectangle()画一条简单的直线
cv::PolyLines()画多重折线
*/
namespace my
{
  cv::Mat* get_black(bool flag)
  {
    //static bool flag = true;
    static cv::Mat img(960,786, CV_8SC3);
    if(flag)
    {
      img.setTo(cv::Vec3b(0, 0, 0));
      //flag = false;
    }
    return &img;
  }
}//namespace
int main(int argc, char** argv)
{

  // my::circle(argv);

  // my::clipLine(argv);

  // my::ellipse(argv);

  // my::ellipse2Ploy_fillConvecPoly(argv);

  //my::line(argv);

  //my::ployLines(argv);
  
  my::putText(argv);
  
  cv::waitKey(0);

  return 0;
}



