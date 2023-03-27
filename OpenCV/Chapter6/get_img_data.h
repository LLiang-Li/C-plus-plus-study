#ifndef _GET_IMG_DATA_
#define _GET_IMG_DATA_
  #include<iostream>
  #include<opencv2/opencv.hpp>
  #include<Log.h>
  #include<vector>
  cv::Mat* get_black(bool flag = false);
  void my_circle(char** argv);
  void my_clipLine(char** argv);
  void my_ellipse(char** argv);
  void ellipse2Ploy_fillConvecPoly(char** argv);
#endif