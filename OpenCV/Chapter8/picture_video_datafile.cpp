#include "pic_vid_data.h"

namespace lige
{
  void imread(char** argv)
  {
    cv::namedWindow("fill", 0);
    cv::imshow("fill", cv::imread(argv[1]));
  }

  void imwrite(char** argv)
  {
    cv::Mat ori_img = cv::imread(argv[1]);
    cv::imwrite(argv[2], ori_img);
    for(int i = 0; i < 10000; i++);
    cv::imshow("write", cv::imread(argv[2]));
  }

  void videowrite(char** argv)
  {
    cv::VideoCapture vc;
    cv::VideoWriter  vm;
#if 0
    if(!vc.open(0))
#else
    if(!vc.open(argv[1]))
#endif
    {
      LOG("Open Failure!");
      return ;
    }  
    int fps = vc.get(cv::CAP_PROP_FPS); // 获取原视频的帧率
    if (fps <= 0) fps = 25;
    vm.open("qq1120.avi", cv::VideoWriter::fourcc('X', '2', '6', '4'),
           fps, cv::Size(vc.get(cv::CAP_PROP_FRAME_WIDTH), 
            vc.get(cv::CAP_PROP_FRAME_HEIGHT)));
    cv::Mat video;
    if (!vm.isOpened()){ // 判断VideoWriter是否正常打开
      LOG("write file failure!\n");
      return ;
    }

    while (1)
    {
      vc >> video;
      vm << video;
      if(video.empty())
      {
        LOG("Read Complete!");
        return ;
      }
      cv::imshow("s", video);
      if(cv::waitKey(30) >= 0)
        break;
    }
  }

  void filestorage(char** argv)
  {
    cv::FileStorage fs("lige.xml", cv::FileStorage::WRITE);
    fs <<"frameCount"<< 5;
    time_t rawtime; time(&rawtime);
    fs <<"calibrationDate"<< asctime(localtime(&rawtime));
    cv::Mat cameraMatrix = (cv::Mat_<double>(3,3)<< 1000,0,320, 0,1000,240,0,0,1);
    cv::Mat distCoeffs = (cv::Mat_<double>(5,1)<< 0.1,0.01,-0.001,0,0);
    fs <<"cameraMatrix"<< cameraMatrix << "distCoeffs"<< distCoeffs;
    fs <<"features"<<"[";
    for(int i=0;i<3;i++ ){
      int x = rand()%640;
      int y = rand()%480;
      uchar lbp=rand()%256;
      fs <<"[:"<<"x"<<x <<"y"<< y <<"bp"<<"[:";
      for( int j=0;j<8;j++) 
       fs << ((lbp >> j)& 1);
      fs <<"]"<<"}";      
    }
    fs <<"]";
    fs.release();
  }
} // namespace lige