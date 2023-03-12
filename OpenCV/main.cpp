#include <iostream>
extern void EdgeCheck(int,  char ** );
extern void StudyMat();
extern void LightSpatialFilter();

#define MyInt(a) (static_cast<unsigned int>(a))
 
int main(int argc, char** argv)
{
    // cv::Mat img;
    // img = cv::imread("C:\\Users\\lenovo\\Pictures\\20210603_121742.jpg");
    // img.resize(100,200);
    // cv::imshow("show", img);
    // cv::waitKey(0);
    // std::cout << "success\n!";

    //EdgeCheck(argc, argv);
#if 0
    unsigned char data[] = {1,2,3,4,5,6,7};
    for(int i = 0; i < 7; i++)
    std::cout << *((unsigned int*)(data + i)) << ',';
    std::cout << '\n' << 0x4030201 << ',' << 0x5040302 << ',' << 0x6050403 <<',';
    std::cout << 0x7060504 << ',' << 0x706050 << ',' <<0x70605 << '\n'; 
    for(int i = 0; i < 7; i++)
    {
        printf("%x,", data + i);
    }
#endif
    StudyMat();
    LightSpatialFilter();

    return 0;
}