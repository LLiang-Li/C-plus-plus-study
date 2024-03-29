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

  //make; .\lige.exe C:\Users\lenovo\Pictures\dasdasdsadsa.jpg 10 0.01 0.01 8
  void CornerSubPix(char** argv)
  {
    cv::Mat img = cv::imread(argv[1],cv::IMREAD_GRAYSCALE);
    if(img.empty())
      LOG("failure!\n");
    cv::Mat color = cv::imread(argv[1]);
    cv::Mat corners;
    cv::goodFeaturesToTrack(img, corners, atoi(argv[2]), atof(argv[3]), atof(argv[4]));
    for(int i = 0; i < corners.rows; i++)
    {
      //for(int j = 0; j < corners.cols; j++)
      {
        LOG("%f, %f\n", corners.at<float>(i, 1), corners.at<float>(i, 2));
      }
      cv::circle(color, cv::Point(corners.at<float>(i, 1), corners.at<float>(i, 2)), 6, cv::Scalar(255, 0, 0));
    }
    LOG("-----------------\n");
    cv::imshow("add circle", color);

    cv::cornerSubPix(img, corners, cv::Size(/*1, 1*/atoi(argv[5]), atoi(argv[5])), cv::Size(-1, -1), cv::TermCriteria());
    cv::imshow("ori", img);
    for(int i = 0; i < corners.rows; i++)
    {
      //for(int j = 0; j < corners.cols; j++)
      {
        LOG("%f, %f\n", corners.at<float>(i, 1), corners.at<float>(i, 2));
      }
      cv::circle(color, cv::Point(corners.at<float>(i, 1), corners.at<float>(i, 2)), 6, cv::Scalar(0, 255, 0));
    }
    cv::imshow("add circle1", color);
    cv::waitKey(0);
  }
  
  //
  void CalcOpticalFlowPyrlK(char** argv)
  {
#if 1
    cv::VideoCapture camera;
    camera.open(0);
    cv::Mat img_show, img_pri, img_now;
    camera >> img_show;
    cv::cvtColor(img_show, img_pri, cv::COLOR_RGB2GRAY);
    camera >> img_show;
    cv::cvtColor(img_show, img_now, cv::COLOR_RGB2GRAY);
    while (1)
    {
      camera >> img_show;
      cv::cvtColor(img_show, img_now, cv::COLOR_RGB2GRAY);
      
      int win_size = 10;

      std::vector<cv::Point2f> corners_pri, corners_now;
      const int MAX_CORNERS = 500;
      cv::goodFeaturesToTrack(img_pri, 
                              corners_pri,
                              MAX_CORNERS,
                              0.01,
                              5,
                              cv::noArray(),
                              3,
                              false,
                              0.04);

      cv::cornerSubPix(img_pri, 
                        corners_pri,
                        cv::Size(win_size, win_size),
                        cv::Size(-1, -1),
                        cv::TermCriteria(3, 20, 0.03));
      std::vector<uchar> feature_found;
      cv::calcOpticalFlowPyrLK(img_pri, img_now, corners_pri, corners_now,
                              feature_found, cv::noArray(),
                              cv::Size(win_size*2 + 1, win_size*2 + 1),
                              5, cv::TermCriteria(3, 20, 0.3));
      for(int i = 0; i < feature_found.size(); i++)
      {
        if(!feature_found[i])
          continue;
        cv::line(img_show, corners_pri[i], corners_now[i], cv::Scalar(0, 255, 0), 2);
      }

      LOG("dx = %f, dy = %f\n", corners_pri[0].x - corners_now[0].x, corners_pri[0].y - corners_now[0].y);
      cv::imshow("image pri", img_pri);
      cv::imshow("image now", img_now);
      cv::imshow("image LK ", img_show);
      img_pri = img_now;
      if(cv::waitKey(20)>=0)
        break;
    }
    
#else
    cv::Mat img_pri = cv::imread(argv[1], 0);
    cv::Mat img_now = cv::imread(argv[2], 0);
    cv::Size img_sz = img_pri.size();

    cv::Mat img_show = cv::imread(argv[2]);

    int win_size = 10;

    std::vector<cv::Point2f> corners_pri, corners_now;
    const int MAX_CORNERS = 500;
    cv::goodFeaturesToTrack(img_pri, 
                            corners_pri,
                            MAX_CORNERS,
                            0.01,
                            5,
                            cv::noArray(),
                            3,
                            false,
                            0.04);

    cv::cornerSubPix(img_pri, 
                      corners_pri,
                      cv::Size(win_size, win_size),
                      cv::Size(-1, -1),
                      cv::TermCriteria(3, 20, 0.03));
    std::vector<uchar> feature_found;
    cv::calcOpticalFlowPyrLK(img_pri, img_now, corners_pri, corners_now,
                             feature_found, cv::noArray(),
                             cv::Size(win_size*2 + 1, win_size*2 + 1),
                             5, cv::TermCriteria(3, 20, 0.3));
    for(int i = 0; i < feature_found.size(); i++)
    {
      if(!feature_found[i])
        continue;
      cv::line(img_show, corners_pri[i], corners_now[i], cv::Scalar(0, 255, 0), 2);
    }
    cv::imshow("image pri", img_pri);
    cv::imshow("image now", img_now);
    cv::imshow("image LK ", img_show);
    cv::waitKey(0);
#endif
  }
  /*
  如果在两个不同方向附近观察到强微分，可以认为这一点就更有可能是独一无二的
  哈尔角点提供了最普遍的定义。两个不同的坐标轴上变化强烈的点
  */
  //广义关键点和描述符
  /*
  关键点是图像的一小部分，由于某种原因，由于独特的原因，可以让我们在另一个相关的图像中定位它们
  关键点主要的三个任务：跟踪、目标识别和立体视觉；
  关键点的类：Ke
  */
  /*
  特征提取函数：
  blob检测器：SimpleBlobDetector
  FASR检测器：FastFeatureDetector
  SIFT检测器：SIFT
  SURF检测器：SURF
  */

 void ReadFunction()
 {
  // cv::SimpleBlobDetector temp; 
  //cv::FastFeatureDetector
  // cv::SIFT
  cv::SIFT::create();
  cv::SURF::create();
 }

} // namespace lige
