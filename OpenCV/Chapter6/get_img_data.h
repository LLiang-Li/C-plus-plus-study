#ifndef _GET_IMG_DATA_
#define _GET_IMG_DATA_
  #include<iostream>
  #include<opencv2/opencv.hpp>
  #include<Log.h>
  #include<vector>
  #include<string>
namespace my
{
  cv::Mat* get_black(bool flag = false);

  void circle(char** argv);
  void clipLine(char** argv);
  void ellipse(char** argv);
  void ellipse2Ploy_fillConvecPoly(char** argv);
  void line(char** argv);
  void ployLines(char** argv);
  void putText(char** argv);
} // namespace my
  
#endif