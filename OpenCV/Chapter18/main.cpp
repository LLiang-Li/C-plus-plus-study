#include"camera_calibration.h"
#include<list>

int main(int argc, char** argv)
{
  // cv::VideoCapture camera;
  // if(!camera.open(0))
  // {
  //   LOG("failure!\n");
  //   return -1;
  // }
  // cv::Mat img;
  
  // while (1)
  // {
  //   camera >> img;
  //   cv::imshow("camrera", img);

  //   if(cv::waitKey(20) > 0)
  //     break;
  // }

  std::vector<int> s(10);
  LOG("now size = %d, caption = %d\n", s.size(), s.capacity());
  s.push_back(10);
  LOG("now size = %d, caption = %d\n", s.size(), s.capacity());
  s.clear();
  LOG("now size = %d, caption = %d\n", s.size(), s.capacity());

  LOG("----------------------------\n");
  std::list<int> li(10);
  LOG("now size = %d, caption = %ld\n", li.size(), li.max_size());
  li.push_back(10);
  LOG("now size = %d, caption = %lld\n", li.size(), li.max_size());
  std::cout << li.max_size();
  li.clear();
  LOG("now size = %d, caption = %ld\n", li.size(), li.max_size());


  return 0;
}