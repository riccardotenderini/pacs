cmake_minimum_required (VERSION 2.6)
project (integer-list)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(integer-list integer-list.cpp integer-list.h)	



# TESTS
# enable testing
enable_testing ()

# se funziona
add_test (integerRuns integer-list)
add_test (integer2 integer-list 6)
add_test (integerExact integer-list 10)

 
