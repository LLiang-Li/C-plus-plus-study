#include"pic_vid_data.h"

int main(int argc, char** argv)
{
  //lige::imread(argv);

  //lige::imwrite(argv);

  //lige::videowrite(argv);

  lige::filestorage(argv);

  cv::waitKey(0);
  return 0;
}