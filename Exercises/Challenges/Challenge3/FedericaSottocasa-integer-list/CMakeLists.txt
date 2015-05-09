cmake_minimum_required (VERSION 2.6)
project (integer-list)

option(USE_COVERAGE "Use of coverage to allow lcov" ON)

if(USE_COVERAGE)
set(CMAKE_CXX_FLAGS "--coverage") 
endif(USE_COVERAGE)


# add the binary tree to the search path for include files
# so that we will find integer-list.h
include_directories("${PROJECT_SOURCE_DIR}")

# add the executable
# execute the basic code of the example
add_executable(main integer-list.cpp) 

#execute a lot of TESTS to verify all the code in file integer-list.h:
add_executable(test-size test-size.cpp)
add_executable(test-append test-append.cpp)
add_executable(test-replace test-replace.cpp)
add_executable(test-setdata test-setdata.cpp)
add_executable(test-prev-next test-prev-next.cpp)
add_executable(test-find test-find.cpp)
add_executable(test-first test-first.cpp)

# enable testing
enable_testing ()

#At first I verify the size because I'll use it in other tests
#It is a test that verify the correct size of the list, here there are 3 nodes and the size method returns 3 (I've corrected it because it forgets about last node)

ADD_TEST(test-size ${PROJECT_SOURCE_DIR}/BUILD/test-size)
set_tests_properties (test-size
  PROPERTIES PASS_REGULAR_EXPRESSION "size 3"
  )

#test to verify the usage of append: I add two element with append and I controll that the list is made by 3,4 and 5 data.
ADD_TEST(test-append ${PROJECT_SOURCE_DIR}/BUILD/test-append)
set_tests_properties (test-append 
  PROPERTIES PASS_REGULAR_EXPRESSION "3 4 5 "
  )

#Then I verify getNext and getPrevious
#I check the value stored in the Node pointers returned by getNext and getPrevious: they should give 2 and 2 because the list is 1,2,3 and I take the previous of the third and the next of the first
ADD_TEST(test-prev-next ${PROJECT_SOURCE_DIR}/BUILD/test-prev-next)
set_tests_properties (test-prev-next
  PROPERTIES PASS_REGULAR_EXPRESSION "2 and 2" 
  )

#this test verify that isFirst works correctly: I ask him if the start node is the first so the result should be true and I ask him if the second is the first so the result should be false.
ADD_TEST(test-first ${PROJECT_SOURCE_DIR}/BUILD/test-first)
set_tests_properties (test-first
  PROPERTIES PASS_REGULAR_EXPRESSION "start is first 1 and second is first 0"
  )

#test to verify the function replaceWith, I replace all the nodes and the list should change from 3,4,5,6 to 70,10,12,15
ADD_TEST(test-replace ${PROJECT_SOURCE_DIR}/BUILD/test-replace)
set_tests_properties (test-replace
PROPERTIES PASS_REGULAR_EXPRESSION "70 10 12 15 ")

#I test the use of setData to fix tha data of a node. Here I change tha data from 1 to 3.
ADD_TEST(test-setdata ${PROJECT_SOURCE_DIR}/BUILD/test-setdata)
set_tests_properties (test-setdata 
  PROPERTIES PASS_REGULAR_EXPRESSION "3"
  )


#I check the code in the function find in the case in which the value to find is in the first node (so I check that the pointer that find returns is to the first node) and in the case in which the value isn't in the list (so in the test I check that find returns NULL)
ADD_TEST(test-find ${PROJECT_SOURCE_DIR}/BUILD/test-find)
set_tests_properties (test-find
  PROPERTIES PASS_REGULAR_EXPRESSION "1 and 1"
  )





