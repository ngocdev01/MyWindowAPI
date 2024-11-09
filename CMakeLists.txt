cmake_minimum_required(VERSION 3.29)
project(MyWindowApi)

set(CMAKE_CXX_STANDARD 20)

option(USE_LOGGER "Log the event of window" ON)


set(source_file
        src/logger.cpp
        Testing/main.cpp
        src/mTime.cpp
        src/mwindow.cpp)
set(include_file
        include/mwindow/logger.h
        include/mwindow/mTime.h
        include/mwindow/mwindow.h)

add_executable(Test WIN32 Testing/main.cpp)
add_library(MyWindowApi ${include_file} ${source_file})

if (USE_LOGGER)
    target_compile_definitions(MyWindowApi PUBLIC "USE_LOGGER")
    target_compile_definitions(Test PUBLIC "USE_LOGGER")
endif()

target_include_directories(MyWindowApi PUBLIC include)
target_link_libraries(Test PUBLIC MyWindowApi)