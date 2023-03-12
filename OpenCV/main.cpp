#include <iostream>
extern void EdgeCheck(int,  char ** );
extern void StudyMat();

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
    unsigned char data[] = {1,2,3,4,5,6,7};
    for(int i = 0; i < 7; i++)
    std::cout << *((unsigned int*)(data + i)) << ',';
    std::cout << '\n' <<  0x01020304 << ',' << 0x4030201;
    //StudyMat();

    return 0;
}