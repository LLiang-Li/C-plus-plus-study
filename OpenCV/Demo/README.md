## OpencV
# Install
下载源码，从官网下载https://opencv.org/
window中的exe是用vs编译过的，需要重新使用gcc编译。
首先，使用cmake客户端加载源码和输出路径
其次，使用cmake生成makefile，注意取消CMAKE中一下选项
 `OPENCV_GENERATE_SETUPVARS`
 `OPENCV_ENABLE_ATOMIC_LONG_LONG`
最后使用make install进行编译安装，最后产出文件在输出文件的install文件夹下

Cmake构建过程中会下载ffmpeg的动态库，如果下载失败会导致无法打开视频文件。
最终会在编译目录中3rdpar/ffmpeg中生成opencv_videoio_ffmpeg.dll和opencv_videoio_ffmpeg_64.dll
需要将opencv_videoio_ffmpeg_64.dll改成opencv_videoio_ffmpeg版本号_64.dll
4.7.0的以使用gcc8.1.0编译完成，放在当前目录下
opencv_videoio_ffmpeg470_64.dll

写视频文件会出现如下错误：
`Failed to load OpenH264 library: openh264-1.8.0-win64.dll
Please check environment and/or download library: https://github.com/cisco/openh264/releases`
去git上下载对象的版本即可


编译成功后需要使用以下Cmake：
```makefile
cmake_minimum_required(VERSION 3.0.0)

project(lige VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

set(OpenCV_DIR D:/mingwopencv/install/x64/mingw/lib) #路径lib

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

aux_source_directory(. SRC)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

target_link_libraries(${CMAKE_PROJECT_NAME}  ${OpenCV_LIBS})
```