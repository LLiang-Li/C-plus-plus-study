#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<cmath>

cv::Mat* getOriginalImage()
{
    static cv::Mat ori_image = cv::imread("C:\\Users\\lenovo\\Pictures\\dasdasdsadsa.jpg");
    return &ori_image;
}

//#define _PICTUREINERSE_
#ifdef _PICTUREINERSE_
void PictureInverse();
#endif

#define _StretchTransform_
#ifdef  _StretchTransform_
void StretchTransform();
#endif

//亮度变换和空间滤波
void LightSpatialFilter()
{
#ifdef _PICTUREINERSE_
    PictureInverse();
#endif

#ifdef  _StretchTransform_
    StretchTransform();
#endif
}

//拉伸变换
#ifdef _StretchTransform_
void StretchTransform()
{
    cv::Mat binary(getOriginalImage()->rows, getOriginalImage()->cols, CV_8UC1, 255);
    cv::Mat strch_tans = binary.clone();
    for(int i = 0; i < binary.rows; i++)
    {  
        for(int j = 0; j < binary.cols; j++)
        {
            auto xs = getOriginalImage()->at<cv::Vec3b>(i, j);
            binary.at<unsigned char>(i,j) = (xs[0] + xs[1] + xs[2])/3;
            strch_tans.at<unsigned char>(i,j) = 255*log(1 + static_cast<double>(binary.at<unsigned char>(i,j)/255));
        }
    }
    std::cout << static_cast<int>(binary.at<unsigned char>(0,0));
    cv::imshow("Binary",binary);
    cv::imshow("inverse", strch_tans);
    cv::waitKey(0);
}
#endif

#ifdef _PICTUREINERSE_
//灰度图反色
void PictureInverse()
{
    cv::Mat ori_image = cv::imread("C:\\Users\\lenovo\\Pictures\\dasdasdsadsa.jpg");
    cv::Mat binary(ori_image.rows, ori_image.cols, CV_8UC1, 255);
    cv::Mat inverse = binary.clone();
    for(int i = 0; i < ori_image.rows; i++)
    {  
        for(int j = 0; j < ori_image.cols; j++)
        {
            auto xs = ori_image.at<cv::Vec3b>(i, j);
            binary.at<unsigned char>(i,j) = (xs[0] + xs[1] + xs[2])/3;
            inverse.at<unsigned char>(i,j) = 255 - (xs[0] + xs[1] + xs[2])/3;
        }
    }
    cv::imshow("Original", ori_image);
    cv::imshow("Binary",binary);
    cv::imshow("inverse", inverse);
    cv::waitKey(0);
}
#endif