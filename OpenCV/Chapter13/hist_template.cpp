#include"hist_template.h"

namespace lige
{
  //make; .\lige.exe C:\Users\jetson\Pictures\a.PNG  30 1 1 > my.txt
  void Hist(char ** argv)
  {
    cv::Mat src = cv::imread(argv[1], 1);
    if(src.empty())
    {
      LOG("failure!");
      return;
    }

    cv::Mat hsv;
    cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);

    float h_range[] = {0, 180};
    float s_range[] = {0, 256};

    const float* ranges[] = {h_range, s_range};

    //int histSize[] = {30, 32}
    int histSize[] = {atoi(argv[2]),atoi(argv[3])}, ch[] = {0 ,1};
    cv::Mat hist;

    cv::calcHist(&hsv, 1, ch, cv::noArray(), hist, atoi(argv[4]), histSize, ranges, true);

    LOG("cols = %d, rows = %d\n", hist.cols, hist.rows);
    for(int i = 0; i < hist.rows; i++)
    {
      for(int j = 0; j < hist.cols; j++)
        LOG("%f, ", hist.at<float>(i,j));
      LOG("\n");
    }
    LOG("-------------------\n");
    cv::normalize(hist, hist, 0, 255, cv::NORM_MINMAX);

    int scale = 10;
    cv::Mat hist_img(histSize[0] * scale, histSize[1] * scale, CV_8UC3);

    for(int h = 0; h < histSize[0]; h++)
    {
      for(int s = 0; s < histSize[1]; s++)
        {
          float hval = hist.at<float>(h, s);
          LOG("%f\n", hval);
          cv::rectangle(hist_img, 
                        cv::Rect(h*scale, s* scale, scale, scale),
                        cv::Scalar::all(hval), -1);
        }
    }

    cv::imshow("image", src);
    cv::imshow("H - S histogram", hist_img);
    cv::waitKey(0);
  }
  //EDM距离。当光照的变化会是颜色值产生大量的偏移，虽然这种偏移倾向于并不改变颜色直方图的形状，，只是相对的平移两个直方图。
  //EMD就是一种距离度量，它的基本思路是，通过将一部分直方图搬到新位置，度量花多大时间才能把直方图搬运刀另外一个直方图里
  /*
  函数语言如下：
  float EMD( InputArray signature1, InputArray signature2,
                      int distType, InputArray cost=noArray(),
                      float* lowerBound = 0, OutputArray flow = noArray() );
  其中signature1，2是两个直方图的签名， dispType是是配置方法，枚举类型
  */


  //反向投影
  /*
  反向投影是计算像素和直方图模型中像素吻合度的一种方法，如果我们有肤色的直方图，我们可以使用反向投影来在图像中寻找肤色区域。中这个来做寻找操作的函数有两种形式，
  一个是稠密数组，另一个是稀疏数组
  void calcBackProject( const Mat* images, int nimages,
                                 const int* channels, InputArray hist,
                                 OutputArray backProject, const float** ranges,
                                 double scale = 1, bool uniform = true );
  其中，*image，nimages分别是图片数组和图片数量。channels是通道数，，hist是直方图， backProject是输出结果
  */

  //模板匹配
  void MatchTemplate(char** argv)
  {
    cv::Mat src, templ, ftmp[6];
    src = cv::imread(argv[1], 1);
    if(src.empty())
    {
      LOG("no picture\n!");
      return ;
    }
    templ = cv::imread(argv[2], 1);
    if(templ.empty())
    {
      LOG("no picture!\n");
    }

    for(int i = 0; i < 6; i++)
    {
      cv::matchTemplate(src, templ, ftmp[i], i);
      cv::normalize(ftmp[i], ftmp[i], 1, 0, cv::NORM_MINMAX);
    }
    cv::imshow("template", templ);
    cv::imshow("Image", src);
    cv::imshow("SQDIFF", ftmp[0]);
    cv::imshow("SQDIFF_NORMED", ftmp[2]);
    cv::imshow("CCORR", ftmp[3]);
    cv::imshow("CCORR_NORMED", ftmp[4]);
    cv::imshow("CCOEFF", ftmp[5]);
    cv::imshow("CCOEFF_NORAML", ftmp[6]);
    cv::waitKey(0);
  } 
} // namespace lige
