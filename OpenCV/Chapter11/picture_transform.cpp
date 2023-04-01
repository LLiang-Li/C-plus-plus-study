#include"picture_transform.h"

namespace lige
{
  //IMREAD_GRAYSCALE是灰度
  cv::Mat* getImage(char** argv, int i = 1)
  {
    static cv::Mat image;
    image = cv::imread(argv[1], i);
    return &image;
  }

  //make; .\lige.exe C:\Users\jetson\Pictures\a.PNG 500 500 0.3 0.2 4
  void resize(char ** argv)
  {
    cv::Mat dst;
    cv::resize(*getImage(argv, cv::IMREAD_GRAYSCALE), dst, cv::Size(atoi(argv[2]), atoi(argv[3])), atof(argv[4]), atof(argv[5]), atoi(argv[6]));
    LOG("%d, %d", getImage(argv)->size().height, getImage(argv)->size().width);
    cv::imshow("resize", dst);
    cv::waitKey(0);
  }

  void PyrDown(char** argv)
  {
    cv::imshow("ori", *getImage(argv, cv::IMREAD_GRAYSCALE));
    cv::Mat dst;
    cv::pyrDown(*getImage(argv, cv::IMREAD_GRAYSCALE), dst);
    cv::imshow("pyr", dst);
    cv::waitKey(0);
  }
  
  void CartToPolar(char**argv)
  { 
    
    cv::Mat mag, ang;
    std::vector<double> s{1,2,3,4,5,6,7,8}, s1{1,2,3,4,5,6,7,8};
    std::vector<double> ss({1,2,3,4,5,6,7,89});
    cv::cartToPolar(s, s1, mag, ang, true);
    LOG("%d, %d\n", getImage(argv)->size().height, getImage(argv)->size().width);
    LOG("%d, %d\n", mag.size().height, mag.size().width);
    cv::imshow("original", *getImage(argv));
    cv::waitKey(0);
    for(int i = 0; i < mag.size().width; i++)
      LOG("%f, ", mag.at<double>(0, i));
    LOG("\n");
    for(int i = 0; i < ang.size().width; i++)
      LOG("%f, ", ang.at<double>(0, i));
  }
} // namespace lige
