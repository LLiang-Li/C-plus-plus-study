#include"conv_filter.h"
int main(int argc, char** argv)
{
  //lige::CopyMakeBorder(argv);

  //lige::test(argv);
  
  //lige::ThresHold(argv);
  lige::adaptiveThreshold(argv);
  return 0;
}