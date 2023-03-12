#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<exception>


struct RGB
{
    uint first:8;
    uint second:8;
    uint third:8;
    uint fouth:8;
};

struct FLOAT
{
    int first:32;
    int second:32;
};

union image
{
    uint data;
    struct RGB rbg;
};

union complex
{
    uint64 data;
    struct FLOAT com; 
};

//#define _GETELEMETNS_
#ifdef _GETELEMETNS_
void getElements();
#endif

//#define _CUTPIC_
#ifdef _CUTPIC_
void CutPic();
#endif

#define _SETRGB_
#ifdef _SETRGB_
void setRgb();
#endif

void StudyMat()
{
#ifdef _GETELEMETNS_
    getElements();
#endif

#ifdef _CUTPIC_
    CutPic();
#endif

#ifdef _SETRGB_
    setRgb();
#endif

}

#ifdef _SETRGB_
void setRgb()
{
    cv::Mat image = cv::imread("C:\\Users\\lenovo\\Pictures\\dasdasdsadsa.jpg");
    cv::Mat image1 = image.clone();
    cv::Mat image2 = image.clone();
    cv::Mat image3 = image.clone();
    cv::Mat binary(image.rows, image.cols, CV_8UC1, 255);
    std::cout << image.elemSize() << " " << image.elemSize1() << std::endl;
    std::cout << "sum: " << image.rows*image.cols <<std::endl;
    std::cout << image.rows << ' ' << image.cols <<std::endl;
    for(int i = 0; i < image.rows; i++)
    {   std::cout << i <<std::endl;
        for(int j = 0; j < image.cols; j++)
        {
            image1.at<cv::Vec3b>(i, j)[0] = 255;
            // image1.at<cv::Vec3b>(i, j)[1] = 0;
            // image1.at<cv::Vec3b>(i, j)[2] = 0;
            image2.at<cv::Vec3b>(i, j)[1] = 255;
            image3.at<cv::Vec3b>(i, j)[2] = 255;
            auto xs = image.at<cv::Vec3b>(i, j);
            try{
                if(i > 550)
                    std::cout << static_cast<int>(binary.at<unsigned char>(i,j)) <<',';
                // binary.at<int>(i,j) = -3;
            }
            catch(std::exception &e)
            {
                std::cout << i << j << '\n';
                std::cout << e.what();
            }
        }
        std::cout << std::endl;
    }  
    cv::imshow("Orirgnal", image);
    cv::imshow("1", image1);
    cv::imshow("2", image2);
    cv::imshow("3", image3);
    cv::imshow("Binary", binary);
    cv::waitKey(0);
}
#endif

#ifdef _GETELEMETNS_
void getElements()
{
cv::Mat M(7,7,CV_32FC2,cv::Scalar(1,3));
    for(int i = 0;i < 7; i++ )
    {
        for(int j = 0; j < 7*2; j++)
            std::cout << M.at<float>(i,j) << ',';
        std::cout << std::endl;
    }
    std::cout << "----------------------\n";

    for(int i = 0;i < 7; i++ )
    {
        for(int j = 0; j < 7; j++)
        {
            std::cout << M.at<cv::Vec2f>(i,j)[0] <<',' <<M.at<cv::Vec2f>(i,j)[1] <<',';
        }
        std::cout << std::endl;
    }

    std::cout << "----------------------\n";
        
        std::cout << std::endl;
    for(int i = 0;i < 49*2; i++ )
        std::cout << M.at<float>(0,i) << ','; std::cout << std::endl;
        std::cout << std::endl;
}
#endif

#ifdef _CUTPIC_
void CutPic()
{
    cv::Mat mat;
    mat = cv::imread("C:\\Users\\lenovo\\Pictures\\20210603_121742.jpg");
    cv::Point p(1,1);
    auto re = mat.at<cv::Point>(p);
    std::cout << typeid(re).name() << std::endl;
    std::cout << re.x  << "  " << re.y <<std::endl;
    
    std::cout << std::endl;
    re = mat.at<cv::Point>(p);
    
    std::cout << typeid(re).name();
    std::cout << mat.dims << std::endl;
    cv::imshow("show", mat);
    std::cout << "rows:" << mat.rows << ", cols::" << mat.cols << std::endl;
  

    cv::Mat roi(mat, cv::Rect(1000,400,2000,1200));

    cv::imshow("bufen", roi);
    cv::waitKey(0);
}
#endif