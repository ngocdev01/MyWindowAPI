cmake_minimum_required(VERSION 3.29)
project(MyWindowApi)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test WIN32 src/main.cpp)

add_library(MyWindowApi  src/logging.cpp
        src/main.cpp
        src/mTime.cpp
        src/mwindow.cpp)

target_include_directories(MyWindowApi PUBLIC include)
target_link_libraries(Test PUBLIC MyWindowApi)