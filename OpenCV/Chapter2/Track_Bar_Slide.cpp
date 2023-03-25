#include<opencv2/opencv.hpp>

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
cv::VideoCapture g_cap;

void OnTrackBarSlide(int pos, void*)
{
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
  if(!g_dontset)
    g_run = 1;
  g_dontset = 0;
  std::cout << g_run << ", " << g_dontset << std::endl;
}

void OnTrackBarSlide1(int pos, void*)
{
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);

  cv::Mat img;
  g_cap >> img;
  if(img.empty())
    return;
  cv::imshow("example",img);
}

void TrackBar(char** argv)
{
  cv::Mat frame;
  cv::namedWindow("example");
  g_cap.open(argv[1]);
  int frames = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_COUNT));
  int tmpw   = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_HEIGHT));
  int tmph   = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_HEIGHT));
#if 0
  cv::createTrackbar("Position", "example", &g_slider_position, frames, OnTrackBarSlide);

  while(1)
  {
    if(g_run != 0)
    {
      g_cap >> frame;
      if(frame.empty())
        break;
      int current_pos = static_cast<int>(g_cap.get(cv::CAP_PROP_POS_FRAMES));
      g_dontset = 1;
      cv::setTrackbarPos("Position", "example", current_pos);
      cv::imshow("example",frame);
      g_run = -1;
    }
    char c = static_cast<char>(cv::waitKey(10));
    if('s' == c)
    {
      g_run = 1;
      std::cout << "Single step, run =" << g_run << std::endl;
    }
    if('r' == c)
    {
      g_run = -1;
      std::cout << "Run mode, run =" << g_run << std::endl;
    }
    if(27 == c)
    {
      break;
    }
  }
#else
  cv::createTrackbar("Position", "example", &g_slider_position, frames, OnTrackBarSlide1);
  g_cap >> frame;
  if(frame.empty())
    return;
  cv::imshow("example", frame);
  for(;;)
    if(27 == cv::waitKey(10)) break;;
#endif

}