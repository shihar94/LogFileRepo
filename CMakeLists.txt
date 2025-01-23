cmake_minimum_required(VERSION 3.5.0)
project(logFile VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED off)
set(CMAKE_CXX_EXTENSIONS off)


find_package(Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)

add_executable(logFile main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
