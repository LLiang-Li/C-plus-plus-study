#include"image_analysis.h"
int main(int argc, char ** argv)
{
  // cv::Mat img = cv::imread(argv[1], atoi(argv[2]));
  // LOG("%d, %d;\n", img.type(), img.depth());
  // cv::imshow("ori", img);
  // LOG("CV_DEPTH_MAX = %d, CV_MAT_DEPTH_MASK= %d\n", CV_DEPTH_MAX, CV_MAT_DEPTH_MASK);
  // LOG("CV_8UC1 = %d; CV_8UC2 = %d\n", CV_8UC1, CV_8UC2);
  
  //lige::Fft(argv);

  // lige::Canny(argv); 

  lige::Hough(argv);

  return 0;
}