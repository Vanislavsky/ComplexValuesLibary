cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-release-1.10.0)
include_directories(lib/googletest-release-1.10.0/googletest/include)
include_directories(lib/googletest-release-1.10.0/googlemock/include)

set(SOURCE_FILE main.cpp Tests/ClassName.h  rational.h complex.h test.h rational.cpp complex.cpp)
add_executable(untitled1 ${SOURCE_FILE} Tests/ClassName.h )
target_link_libraries(untitled1 gtest gtest_main)
