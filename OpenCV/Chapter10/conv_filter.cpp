#include"conv_filter.h"

namespace lige
{
  //灰度图
  cv::Mat* getImage(char ** argv)
  {
    cv::Mat img = cv::imread(argv[1]);
    std::vector<cv::Mat> planes;
    cv::split(img, planes);

    cv::Mat r = planes[0], g = planes[1], b = planes[2];
    static cv::Mat s;
    cv::addWeighted(r, 1./3., g, 1./3., 0.0, s);
    cv::addWeighted(s, 1., b, 1./3., 0.0, s);
    return &s;
  }

  void CopyMakeBorder(char** argv)
  {
    cv::Mat src = cv::imread(argv[1]);
    cv::Mat dst;

    cv::copyMakeBorder(src, dst, 5,5,5,5, cv::BORDER_CONSTANT, cv::Scalar(255, 0, 0));
    cv::imshow("original", src);
    cv::imshow("BORDER", dst);

    cv::waitKey(0);
  }

  void ThresHold(char** argv)
  {
    cv::Mat img = cv::imread(argv[1]), dst;
    std::vector<cv::Mat> planes;
    cv::split(img, planes);

    cv::Mat r = planes[0], g = planes[1], b = planes[2], s;

    cv::addWeighted(r, 1./3., g, 1./3., 0.0, s);
    cv::addWeighted(s, 1., b, 1./3., 0.0, s);

    cv::threshold(s, dst, 100, 100, cv::THRESH_BINARY);
    cv::imshow("ori",img);
    cv::imshow(argv[1], dst);

    LOG("%d\n", s.type());
    s = cv::Mat::zeros(s.rows, s.cols, CV_32F);
    cv::accumulate(r, s);
    cv::accumulate(g, s);
    cv::accumulate(b, s);
    cv::threshold(s, s, 100, 100, cv::THRESH_BINARY);

    cv::imshow("acc", s);

    cv::waitKey(0);
  }

  

  void adaptiveThreshold(char** argv)
  {
    cv::Mat dst1, dst2;
    cv::imshow("ori", *getImage(argv));
    cv::adaptiveThreshold(*getImage(argv), dst1, 100, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, atoi(argv[2]), atoi(argv[3]));
    cv::imshow("ADAPTIVE_THRESH_GAUSSIAN_C", dst1);
    cv::adaptiveThreshold(*getImage(argv), dst2, 100, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, atoi(argv[2]), atoi(argv[3]));
    cv::imshow("ADAPTIVE_THRESH_MEAN_C", dst2);
    cv::waitKey(0);
  }

  void test(char** argv)
  {
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr[2][10] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
    int **pt;
    pt = (int**)arr;
    LOG("%x, %x, %x; %x; \n", arr, *arr, **arr, pt);
    LOG("%x;\n", *pt);

    int a = 1;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;
    LOG("%x, %x, %x, %x", ppp, pp, p, a);

    int** pp1 = new int*[5];

    delete [] pp;
  }

} // namespace lige
