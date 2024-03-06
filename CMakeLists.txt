# 指定cmake的最低版本
cmake_minimum_required(VERSION 3.10) 
# 定义你的项目名
project(MyProject) 

# 通过set整合要编译的执行文件，utils.c是你编写的util库的主要源文件，utils.h在start中引入
set(SOURCE_FILES index.c utils/utils.c) 

# 添加一个可执行文件的目标，名字是 MyProject，源代码文件是 SOURCE_FILES 变量存储的文件。
add_executable(MyProject ${SOURCE_FILES})

# 寻找并链接 CURL 库。如果没有找到，由于设置了 REQUIRED，CMake 会报告错误库
find_package(CURL REQUIRED)

# 将要使用的库文件和头文件目录链接到你的项目
if(CURL_FOUND)
  #将 CURL 的头文件目录加到编译器的头文件搜索路径中。  
  include_directories(${CURL_INCLUDE_DIR})
  #将 CURL 库链接到 MyProject 可执行文件。
  target_link_libraries(MyProject ${CURL_LIBRARY})

else(CURL_FOUND)
  # 输出错误信息
  message(FATAL_ERROR "CURL library not found")
  
endif(CURL_FOUND)