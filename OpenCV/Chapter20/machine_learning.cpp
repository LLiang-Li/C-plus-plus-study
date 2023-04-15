#include"machine_learning.h"

namespace lige
{
  void kmean(char** argv)
  {
    const int MAX_CLUSTERS = 5;
    cv::Scalar colorTab[] = {
      cv::Scalar(0, 0, 255),
      cv::Scalar(0, 255, 0),
      cv::Scalar(255, 100, 100),
      cv::Scalar(255, 0, 255),
      cv::Scalar(0, 255, 255)
    };
    cv::Mat img(500, 500, CV_8SC3);
    cv::RNG rng(12345);

    cv::namedWindow("cluster", 1);

    while (1)
    {
      int k, clusterCount = rng.uniform(2, MAX_CLUSTERS + 1);
      int i, sampleCount = rng.uniform(1, 1001);
      cv::Mat points(sampleCount, 1, CV_32FC2), labels;

      clusterCount = MIN(sampleCount, clusterCount);
      cv::Mat centers(clusterCount, 1, CV_32FC2);

      LOG("clusterCount = %d, sampleCount = %d\n", clusterCount, sampleCount);

      for(k = 0; k < clusterCount; k++)
      {
        cv::Point center;
        center.x = rng.uniform(0, img.cols);
        center.y = rng.uniform(0, img.rows);
        cv::Mat pointChunk = points.rowRange(
                k*sampleCount/clusterCount,
                k == clusterCount - 1? sampleCount : (k+1)*sampleCount/clusterCount
        );
        rng.fill(pointChunk, cv::RNG::NORMAL, cv::Scalar(center.x, center.y), cv::Scalar(img.cols*0.05, img.rows*0.05));
      }
      cv::randShuffle(points, 1, &rng);

      cv::kmeans(points, clusterCount, labels, cv::TermCriteria(cv::TermCriteria::EPS | cv::TermCriteria::COUNT, 10, 1), 1, cv::KMEANS_PP_CENTERS, centers);
      img = cv::Scalar::all(0);
      for(i = 0; i < sampleCount; i++)
      {
        int clusterIdx = labels.at<int>(i);
        cv::Point2f ipt = points.at<cv::Point2f>(i);
        cv::circle(img, ipt, 2, colorTab[clusterIdx], cv::FILLED, cv::LINE_AA);
      }
      cv::imshow("cluster", img);
      if(cv::waitKey(100) >= 0)
      {
        LOG("Over\n");
        break;
      }
    }
    LOG("Please press any key to quit!\n");
    cv::waitKey();
  }
} // namespace lige
