#include"get_img_data.h"

void my_circle(char** argv)
{
  cv::Mat img = *get_black();
  cv::circle(img, cv::Point(768/2, 960/2), 100, cv::Scalar(255 ,255, 255));
  LOG("rows = %d, cols = %d", get_black()->rows, get_black()->cols);
  cv::imshow("ori", img);
  cv::waitKey(0);
}

void my_clipLine(char** argv)
{
  cv::Rect R(0, 0, 10, 10);
  cv::Point P1(1,1);
  cv::Point P2(3,3);
  LOG("res = %d", cv::clipLine(R, P1, P2));
  P1 = cv::Point(11, 12);
  P2 = cv::Point(12, 13);
  LOG("res = %d", cv::clipLine(R, P1, P2));
}

void my_ellipse(char** argv)
{
  //cv::Mat img = get_black(true)->clone();
  cv::ellipse(*get_black(true), 
              cv::Point(768/2, 960/2),
              cv::Size(300,200),
              atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), 
              cv::Scalar(0,255,0));
  cv::imshow("tuoyuan", *get_black());

  cv::RotatedRect s(cv::Point2f(768/2, 960/2), cv::Size2f(600, 400), 30);
  cv::ellipse(*get_black(true), s, cv::Scalar(255,255, 0));
  cv::imshow("tuoyuan1", *get_black());
  cv::waitKey(0);
}

void ellipse2Ploy_fillConvecPoly(char** argv)
{
  std::vector<cv::Point> pts;
  cv::ellipse2Poly(cv::Point(768/2, 960/2), cv::Size(300, 200), 0, 0, 360, 2, pts);
  
  cv::fillConvexPoly(*get_black(true), &pts[0], atoi(argv[1]), cv::Scalar(255, 0, 0));

  cv::imshow("fill", *get_black());

  cv::waitKey(0);
}