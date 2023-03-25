#include<opencv2/opencv.hpp>
#include<iostream>

void TrackBar(char** argv);
void WriteAVI(char** argv);

int main(int argc, char** argv)
{
//shouw image
#if 0
  cv::Mat img = cv::imread(argv[1], -1);
  if(img.empty())
  {
    std::cout << "failture\n";
    return -1;
  }
  cv::imshow("example", img);
  //filter
  cv::Mat out;
  cv::GaussianBlur(img, out, cv::Size(5,5),3,3);
  cv::GaussianBlur(out, out, cv::Size(5,5),3,3);

  cv::imshow("fliter",out);

  cv::Mat img1;
  cv::pyrDown(img, img1);
  cv::imshow("pyrDown",img1);
  std::cout << img.cols << ";"<< img.rows << ";" << img1.cols << ";" << img1.rows << std::endl;

  std::cout << cv::waitKey();
#endif

//image an video
#if 0
  cv::VideoCapture cap;
  cv::Mat frame;
  cap.open(argv[1]);
  if(!cap.isOpened())
  {
    std::cout << "failture\n";
    return -1;
  }
  for(;;)
  {
    cap >> frame;
    if(frame.empty())
      break;
    cv::imshow("", frame);
    if(cv::waitKey(33) >= 0)
      break;
  }
#endif

#if 0
  TrackBar(argv);
#endif

#if 1
  WriteAVI(argv);
#endif
  return 0;
}
