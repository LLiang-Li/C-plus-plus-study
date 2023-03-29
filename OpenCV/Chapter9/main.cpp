#include"show_mouse_callback.h"
int main(int argc, char** argv)
{
  //lige::StartWindowsThread(argv);

  lige::SetMouseCallback(argv);
  return 0;
}