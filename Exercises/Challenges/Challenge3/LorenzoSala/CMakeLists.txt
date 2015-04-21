cmake_minimum_required (VERSION 2.6)
project (integer-list)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

#include some cxxflags
#option(coverage "build for coverage test" OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
#set(CMAKE_BUILD_TYPE Debug)

# add the executable
add_executable (integer-list integer-list.cpp)

# enable testing
enable_testing ()

# does the application run
add_test (Integer-listRuns1 integer-list 1)
add_test (Integer-listRuns2 integer-list 7)
add_test (Integer-listRuns3 integer-list 12)

add_test (Integer-listUsage1 integer-list 5 "Lista iniziale: 
5, 6, 7, 8, 9, 10
Scambio il 5 con il 7: 
7, 6, 5, 8, 9, 10
Cancello il 7: 
6, 5, 8, 9, 10
Dimensioni della lista: 5")

add_test (Integer-listUsage2 integer-list 11 "Lista iniziale: 
11
Scambio il 5 con il 7: 
11
Cancello il 7: 
11
Dimensioni della lista: 1")

add_test (Integer-listUsage3 integer-list 7 "Lista iniziale: 
7, 8, 9, 10
Scambio il 5 con il 7: 
7, 8, 9, 10
Cancello il 7: 
8, 9, 10
Dimensioni della lista: 3")

add_test (Integer-listUsage4 integer-list 1 "Lista iniziale: 
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
Scambio il 5 con il 7: 
1, 2, 3, 4, 7, 6, 5, 8, 9, 10
Cancello il 7: 
1, 2, 3, 4, 6, 5, 8, 9, 10
Dimensioni della lista: 9"
)

add_test (Integer-listErrorMessage integer-list "Non è stato inserito il numero di input necessari. Chiamare ./integer-list [c] ")



