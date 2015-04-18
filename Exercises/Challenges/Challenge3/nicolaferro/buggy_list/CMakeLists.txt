cmake_minimum_required (VERSION 2.6)
project (integer-list)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "--coverage")

# add the executable
add_executable(integer-list integer-list.cpp)
add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp)
add_executable(test3 test3.cpp)
add_executable(test4 test4.cpp)
add_executable(test5 test5.cpp)
add_executable(test6 test6.cpp)

# enable testing
enable_testing ()

#add tests
add_test (DefaultConstructor test1)
add_test (Size test2)
add_test (SetData test3)
add_test (Append test4)
add_test (ReplaceWith test5)
add_test (isFirst test6)

