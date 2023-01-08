#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "Input Counter: " << argc << std::endl;
  std::cout << "File Name with Full Path: " <<argv[0] << std::endl;
  return 0;
}