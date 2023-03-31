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

  void BlurBoxfilterMedianblurGuassianBilateral(char** argv)
  {
    cv::imshow("origianl", *getImage(argv));
    cv::Mat blur_, boxfilter_, medium_, gauss_, biltereral_;
    cv::blur(*getImage(argv), blur_, cv::Size(atoi(argv[2]),atoi(argv[2])));
    cv::imshow("blur", blur_);
    cv::boxFilter(*getImage(argv), boxfilter_, getImage(argv)->depth(), cv::Size(atoi(argv[2]),atoi(argv[2])));
    cv::imshow("box", boxfilter_);
    cv::medianBlur(*getImage(argv), medium_, atoi(argv[2]));
    cv::imshow("medium", medium_);
    cv::GaussianBlur(*getImage(argv), gauss_, cv::Size(atoi(argv[2]),atoi(argv[2])), 0, 0);
    cv::imshow("guass", gauss_);
    cv::bilateralFilter(*getImage(argv), biltereral_, atoi(argv[2]), atof(argv[3]), atof(argv[4]));
    cv::imshow("bilateral", biltereral_);
    cv::waitKey(0);
  }

  void derivative_and_gradient(char** argv)
  {
    cv::Mat sobel_, laplacian_;
    cv::imshow("original", *getImage(argv));
    LOG("%d", getImage(argv)->depth());
    cv::Sobel(*getImage(argv), sobel_, getImage(argv)->depth(), atoi(argv[2]), atoi(argv[3]));
    cv::imshow("sobel", sobel_);
    cv::Laplacian(*getImage(argv), laplacian_, getImage(argv)->depth(), atoi(argv[2]), atoi(argv[3]));
    cv::imshow("laplacian", laplacian_);

    cv::waitKey(0);
  }


  void ErodeDilate(char** argv)
  {
    cv:: Mat img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    LOG("%d\n", img.dims);
    cv::Mat temp;
    cv::threshold(img, temp, 50, 100, img.depth());
    cv::Mat erode_, dilate_;
    cv::imshow("ori", *getImage(argv)/* temp*/);
    cv::erode(*getImage(argv)/* temp*/, erode_, cv::Mat::ones(4, 4, getImage(argv)->depth()), cv::Point(-1,-1), 3);
    cv::imshow("erode", erode_);
    cv::dilate(*getImage(argv)/* temp*/, dilate_, cv::Mat::ones(4, 4, getImage(argv)->depth()), cv::Point(-1,-1), 3);
    cv::imshow("dilate", dilate_);
    cv::waitKey(0);
  }

  void MorphologyEx(char** argv)
  {
    cv::Mat temp = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat img;
    cv::threshold(temp, img, 50, 100, img.depth());
    cv::Mat open, close;
    cv::morphologyEx(img, open, cv::MORPH_OPEN, cv::Mat::ones(4, 4, img.depth()));
    cv::morphologyEx(img, close, cv::MORPH_CLOSE, cv::Mat::ones(4, 4, img.depth()));
    cv::imshow("original", img);
    cv::imshow("open", open);
    cv::imshow("close", close);
    cv::waitKey(0);
  }

  void Kernal(char** argv)
  {
    // make; .\lige.exe C:\Users\jetson\Pictures\a.PNG  0 3 3 2 3 7 5 0.4
    cv::MorphShapes te;
    cv::Mat kernal_ = cv::getStructuringElement(atoi(argv[2]), cv::Size(atoi(argv[3]), atoi(argv[4])));
    LOG("%d\n", kernal_.depth());
    //kernal_.at<unsigned char>(0, 0) = 255;
    for(int i = 0; i < atoi(argv[3]); i++)
    {
      for(int j = 0; j < atoi(argv[4]); j++)
        LOG("%d;", kernal_.at< char>(i, j));
      LOG("\n");
    }
    LOG("----------------------------\n");

    cv::Mat kx, ky;
    cv::getDerivKernels(kx, ky, atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
    for(int i = 0; i < kx.rows; i++)
    {
      for(int j = 0; j < kx.cols; j++)
        LOG("%f;", kx.at<float>(i, j));
      LOG("\n");
    }
    LOG("----------------------------\n");
    for(int i = 0; i < ky.rows; i++)
    {
      for(int j = 0; j < ky.cols; j++)
        LOG("%f;", ky.at<float>(i, j));
      LOG("\n");
    }

    LOG("----------------------------\n");
    cv::Mat Gk = cv::getGaussianKernel(atoi(argv[8]), atof(argv[9]));
    LOG("%d, %d\n", Gk.cols, Gk.rows);
    for(int i = 0; i < Gk.rows; i++)
    {
      for(int j = 0; j < Gk.cols; j++)
        LOG("%f;", Gk.at<float>(i, j));
      LOG("\n");
    }
    
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
