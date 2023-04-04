#include"contours.h"

namespace lige
{
  cv::Mat g_gray, g_binary;
  int g_thresh = 100;

  void on_trachbar(int, void*)
  {
    cv::threshold(g_gray, g_binary, g_thresh, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> coutours;

    cv::findContours(g_binary, coutours, cv::noArray(), cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
    //LOG("%d\n", g_thresh);
    g_binary = cv::Scalar::all(0);
    
    cv::drawContours(g_binary, coutours, -1, cv::Scalar::all(255));
    cv::imshow("Contours", g_binary);
  }
  //查找轮廓
  void Contours(char** argv)
  {
    g_gray = cv::imread(argv[1], 0);
    if(g_gray.empty())
      return;

    cv::namedWindow("Contours", 1);

    cv::createTrackbar("Threshhold", "Contours", &g_thresh, 255, on_trachbar);

    on_trachbar(0, nullptr);
    cv::waitKey(0);
  }

  //快速连通区域分析
  void ConnectedComponents(char** argv)
  {
    cv::Mat img, img_edge, labels, img_color, stats, temp;
    img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::threshold(img, img_edge, 128, 255, cv::THRESH_BINARY);
    cv::imshow("Image after threshild", img_edge);
    int i;
    int nccopms = cv::connectedComponentsWithStats(img_edge, labels, stats, temp);

    std::vector<cv::Vec3b> colors(nccopms + 1);

    colors[0] = cv::Vec3b(0,0,0);

    for(i = 1; i <= nccopms; i++)
    {
      colors[i] = cv::Vec3b(rand()%256, rand()%256, rand()%256);
      if(stats.at<int>(i - 1, cv::CC_STAT_AREA) < 100)
        colors[i] = cv::Vec3b(0,0,0);
    }
    img_color = cv::Mat::zeros(img.size(), CV_8UC3);

    for(int y = 0; y < img_color.rows; y++)
    {
      for(int x = 0; x < img_color.cols; x++)
      {
        int label = labels.at<int>(y, x);
        CV_Assert(0 <= label && label <= nccopms);
        img_color.at<cv::Vec3b>(y, x) = colors[label];
      }
    }
    cv::imshow("label", img_color);
    cv::waitKey(0);
  }

  /*
  多边形逼近，cv::approxPolyDP()
  主要使用Douglas-Peucker算法.主要步骤如下：
  首先，在边缘图像中寻找距离最大的两个点，
  其次，寻找点里线段最远的点，
  再次，将已有的点连成多边形。
  循环其次，再此。
  */

} // namespace lige
