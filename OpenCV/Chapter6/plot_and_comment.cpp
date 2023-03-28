#include"get_img_data.h"

namespace my
{
  void circle(char** argv)
  {
    cv::Mat img = *get_black();
    cv::circle(img, cv::Point(768/2, 960/2), 100, cv::Scalar(255 ,255, 255));
    LOG("rows = %d, cols = %d", get_black()->rows, get_black()->cols);
    cv::imshow("ori", img);
    
  }

  void clipLine(char** argv)
  {
    cv::Rect R(0, 0, 10, 10);
    cv::Point P1(1,1);
    cv::Point P2(3,3);
    LOG("res = %d", cv::clipLine(R, P1, P2));
    P1 = cv::Point(11, 12);
    P2 = cv::Point(12, 13);
    LOG("res = %d", cv::clipLine(R, P1, P2));
  }

  void ellipse(char** argv)
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

  }

  void ellipse2Ploy_fillConvecPoly(char** argv)
  {
    std::vector<cv::Point> pts;
    cv::ellipse2Poly(cv::Point(768/2, 960/2), cv::Size(300, 200), 0, 0, 360, 2, pts);
    
    cv::fillConvexPoly(*get_black(true), &pts[0], atoi(argv[1]), cv::Scalar(255, 0, 0));

    cv::imshow("fill", *get_black());

  }

  void line(char** argv)
  {
    cv::line(*get_black(true), cv::Point(100, 100), cv::Point(400, 400), cv::Scalar(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
    cv::imshow("Line", *get_black());
  }
#define _MY_NEW_
  void ployLines(char** argv)
  {
    // std::vector<cv::Point> pts;
    // pts.emplace_back(100,200);
    // pts.emplace_back(100,300);
    // pts.emplace_back(200,300);
    // pts.emplace_back(100,300);
    // cv::Point pts[4] = {{100,200}, {100,300}, {200,300},{100,300}};
#ifdef _MY_NEW_
    cv::Point **pts = new cv::Point*[1];
    pts[0] = new cv::Point[4];

    pts[0][0] = {100,200};
    pts[0][1] = {200,300};
    pts[0][2] = {300,400};
    pts[0][3] = {500,500};
#else
    std::vector<std::vector<cv::Point>> pts{std::vector<cv::Point>{{100,200}, {100,300}, {200,300},{100,300}}};

#endif
    int s[2] = {4};
    cv::polylines(*get_black(), &pts[0],s ,1 ,1 ,cv::Scalar(255,255,255));
    cv::imshow("ploy", *get_black());
#ifdef _MY_NEW_
    delete [] pts[0];
    delete pts;
#endif
  }

  void putText(char** argv)
  {
    cv::putText(*get_black(true), std::string(argv[1]), 
                cv::Point(200, 200), cv::FONT_HERSHEY_SIMPLEX,
                atoi(argv[2]), cv::Scalar(255, 255, 0));
    cv::imshow("text", *get_black());
  }
} // namespace my



