#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

void ReadVideo(char** argv)
{
  cv::VideoCapture cap;
  bool flag = cap.open(argv[1]);
  if(!flag)
  {
    std::cout << "Open Failure!";
    return ;
  }
  cv::Mat frame;
  while(1)
  {
    cap >> frame;
    if(frame.empty())
      break;
    cv::imshow("", frame);
    if(cv::waitKey(33) >= 0)
      break;
  }
}