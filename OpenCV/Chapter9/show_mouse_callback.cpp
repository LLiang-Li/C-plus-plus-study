#include"show_mouse_callback.h"

namespace lige
{
  void StartWindowsThread(char** argv)
  {
    cv::namedWindow("lige");
    cv::startWindowThread();//没用，可能是系统不支持吧
    cv::VideoCapture vc(0);
    if(!vc.isOpened())
    {
      LOG("Open failure\n");
    }
    cv::Mat mat;
    while (1)
    {
      vc >> mat;
      if(mat.empty())
        break;
      cv::imshow("lige",mat);
      if(cv::waitKey(30) >= 0)
        break;
    }
  }

  void my_mouse_callback(int event, int x, int y, int flag, void *);

  cv::Rect box;

  bool drawing_box = false;

  void draw_box(cv::Mat& img, cv::Rect box)
  {
    cv::rectangle(img, box.tl(), box.br(), cv::Scalar(0, 0, 255));
  }

  void help()
  {
    LOG("shows how to use a mouse to draw regions in an image\n");
  }

  void SetMouseCallback(char ** argv)
  {
    help();
    box = cv::Rect(-1, -1, 0, 0);
    cv::Mat image(400, 400, CV_8UC3), temp;
    image.copyTo(temp);

    // box = cv::Rect(-1, -1, 0, 0);
    image = cv::Scalar::all(0);
    cv::namedWindow("lige");

    cv::setMouseCallback("lige", my_mouse_callback, (void* )&image);

    for(;;)
    {
      image.copyTo(temp);
      if(drawing_box)
        draw_box(temp, box);
      cv::imshow("lige", temp);
      if(cv::waitKey(15) >= 0)
        break;
    }
  }

  void my_mouse_callback(int event, int x, int y, int flag, void * param)
  {
    cv::Mat image = *(cv::Mat*)param;

    switch (event)
    {
    case cv::EVENT_MOUSEMOVE:
      LOG("EVENT_MOUSEMOVE\n");
      if(drawing_box)
      {
        box.width = x - box.x;
        box.height = x - box.y;
      }
      LOG("x = %d, y = %d, w = %d. h = %d\n", box.x, box.y, box.width, box.height);
      break;
    case cv::EVENT_LBUTTONDOWN:
      LOG("EVENT_LBUTTONDOWN\n");
      drawing_box = true;
      box = cv::Rect(x, y, 0, 0);
      break;
    case cv::EVENT_LBUTTONUP:
      LOG("EVENT_LBUTTONUP\n");
      drawing_box = false;
      if(box.width < 0)
      {
        box.x += box.width;
        box.width *= -1;
      }
      if(box.height < 0)
      {
        box.y += box.height;
        box.height *= -1;
      }
      draw_box(image, box);
      LOG("-------------------\n");
      break;
    default:
      break;
    }
  }

} // namespace lige