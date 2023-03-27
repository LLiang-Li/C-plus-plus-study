#include<iostream>
#include<opencv2/opencv.hpp>
#include<Log.h>

int main(int argc, char** argv)
{
  cv::Mat m;
  m.create(3,10, CV_32FC3);
  m.setTo(cv::Scalar(1.0f, 1.0f, 1.0f));

  cv::Vec<int, 3> vec{1,2,3};
  // vec[0] = 1;
  LOG_INFO("%d", vec[0]);
  vec[0] = 2;
  LOG_INFO("%d", vec[0]);

  cv::Mat mat = cv::Mat::eye(10, 20, CV_32FC1);
  LOG_INFO("ELement (3, 3) id %f", mat.at<float>(3,3));

  mat = cv::Mat::eye(10, 10, CV_32FC2);
  std::cout << mat.isContinuous() <<std::endl;
  LOG_INFO("ELement (3, 3) id %f", mat.at<cv::Vec2f>(3,3)[0], mat.at<cv::Vec2f>(3,3)[1]);
  LOG("rows = %d, cols = %d\n", mat.rows, mat.cols);
  for(int i = 0; i < mat.cols; i++)
  {
    for(int j = 0; j < mat.rows; j++)
    {
      //错误使用一个去访问所有的；
      //mat.ptr<cv::Vec2f>(i*mat.cols + j);
      cv::Vec2f* con = mat.ptr<cv::Vec2f>(i,j);
      //LOG_INFO("x1 = %f, X2 = %f", (*con)[0], (*con)[1]);
      //std::cout << i<< j << " : " << (*con)[0] << (*con)[1] << " | ";
      LOG("%d%d: %.0f%.0f|", i, j ,(*con)[0], (*con)[1]);
    }
    std::cout << std::endl;
  }
  LOG("-------------------------------------------\n");
  //迭代器
  int sz[] = {5, 5, 5};
  cv::Mat MM1(3, sz, CV_32FC1);
  cv::Mat MM2(3, sz, CV_32FC1);
  cv::RNG rgn;
  rgn.fill(MM1, cv::RNG::UNIFORM, 0.f, 1.f);
  rgn.fill(MM2, cv::RNG::UNIFORM, 0.f, 1.f);
  const cv::Mat *array[] = {&MM1, &MM2, 0};
  cv::Mat my_plants[2];
  cv::NAryMatIterator it(array, my_plants);
  int n = 0;
  float s = 0.f;
  for(int p = 0; p < it.nplanes; ++p, ++it)
  {
    s += cv::sum(it.planes[0])[0];
    s += cv::sum(it.planes[1])[0];
  }
  LOG("nplanes = %d, size = %d, res = %f", it.nplanes, it.size, s);

  //可通过Mat的row和col如复制单行，使用RowRanged多行复制
  cv::Mat mymat(3,3,CV_32FC1);
  
  return 0;
}