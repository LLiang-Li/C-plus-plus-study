#include<opencv2/opencv.hpp>

void WriteAVI(char** argv)
{
  cv::namedWindow("ori");
  cv::namedWindow("now");

  cv::VideoCapture cap(argv[1]);
  double fps = cap.get(cv::CAP_PROP_FPS);
  cv::Size size(static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)),
   static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT)));
  cv::VideoWriter writer;
  writer.open(argv[2], 0, fps, size);

  cv::Mat logpolar_frame, rbg_frame;
  for(;;)
  {
    cap >> rbg_frame;
    if(rbg_frame.empty())
      break;
    cv::imshow("ori", rbg_frame);
    cv::logPolar(rbg_frame, logpolar_frame, cv::Point2f(rbg_frame.cols/2, rbg_frame.rows/2),40, cv::WARP_FILL_OUTLIERS);
    cv::imshow("now", logpolar_frame);
    writer << logpolar_frame;
    char c = cv::waitKey(10);
    if(27 == c)
      break;
  }
  cap.release();
}