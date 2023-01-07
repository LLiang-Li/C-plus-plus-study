# C++ proto

C++使用proto的步骤：

1、下载proto的源码

2、使用CMake编译源码，不要选择动态库（那个test也可以不要）；产出物主要包含protoc.exe和*.a的动态库；

3、在CMake需要增加源码中的google文件夹：

include_directories(C:/Users/lenovo/Documents/protobuf_3_21_12/src)

需要链接上一步的静态库

link_directories(C:/Users/lenovo/Documents/PROTOBUF)


此外，为了让proto可以自动编译成.c和.h。可以将proto放在一个单独的文件夹，使用CMake来自动生成
