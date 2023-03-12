#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

void EdgeCheck(int argc,  char ** argv)
{
    int sizeh = 3;
    int sizel = 3;
    if(argc >= 3)
    {
        sizeh = atoi(argv[1]);
        sizel = atoi(argv[2]);
    }
        
    cv::VideoCapture cam(0);
    if (!cam.isOpened()){
        std::cout <<  "cam open failed!" << std::endl;
        getchar();
        return ;
    }
    std::cout <<  cam.get(cv::CAP_PROP_FPS);
    std::cout << "cam open success!" << std::endl;
    cv::namedWindow("bianyaun");

    cv::Mat img, edge, grayImage;
    for(;;)
    {
        cam.read(img); // 读帧
        if (img.empty()) break; 

        cv::cvtColor(img, grayImage, cv::COLOR_BGR2GRAY);
        cv::blur(grayImage, edge, cv::Size(sizeh, sizel));
        cv::Canny(edge, edge, 3, 9, 3);
        if((argc >= 2))
            cv::imshow("bianyaun", edge); // 显示每一帧
        else    
            cv::imshow("bianyaun", img); // 显示每一帧
        if (cv::waitKey(5) == 'q') break;
    }

}