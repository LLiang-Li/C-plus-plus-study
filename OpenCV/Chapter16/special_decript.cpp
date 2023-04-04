#include"special_decript.h"

namespace lige
{
  //make; .\lige.exe C:\Users\jetson\Pictures\a.PNG 10 0.01 0.01
  void GoodFeaturestoTrack(char** argv)
  {
    cv::Mat img = cv::imread(argv[1],cv::IMREAD_GRAYSCALE);
    cv::Mat color = cv::imread(argv[1]);
    cv::Mat corners;
    cv::goodFeaturesToTrack(img, corners, atoi(argv[2]), atof(argv[3]), atof(argv[4]));
    cv::imshow("ori", img);
    for(int i = 0; i < corners.rows; i++)
    {
      //for(int j = 0; j < corners.cols; j++)
      {
        LOG("%f, %f\n", corners.at<float>(i, 1), corners.at<float>(i, 2));
      }
      cv::circle(color, cv::Point(corners.at<float>(i, 1), corners.at<float>(i, 2)), 6, cv::Scalar(255, 0, 0));
    }
    cv::imshow("add circle", color);
    cv::waitKey(0);
  }

  //
  void CornerSubPix(char** argv)
  {
    cv::Mat img = cv::imread(argv[1],cv::IMREAD_GRAYSCALE);
    if(img.empty())
      LOG("failure!\n");
    cv::Mat color = cv::imread(argv[1]);
    cv::Mat corners;
    cv::cornerSubPix(img, corners, cv::Size(5, 5/*atoi(argv[2]), atoi(argv[2])*/), cv::Size(-1, -1), cv::TermCriteria());
    cv::imshow("ori", img);
    // for(int i = 0; i < corners.rows; i++)
    // {
    //   //for(int j = 0; j < corners.cols; j++)
    //   {
    //     LOG("%f, %f\n", corners.at<float>(i, 1), corners.at<float>(i, 2));
    //   }
    //   cv::circle(color, cv::Point(corners.at<float>(i, 1), corners.at<float>(i, 2)), 6, cv::Scalar(255, 0, 0));
    // }
    cv::imshow("add circle", color);
    cv::waitKey(0);
  }
} // namespace lige
