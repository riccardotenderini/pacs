I converted the makefile in the CMakeLists and then I added some tests to verify all the code in file integer-list.hpp

The tests are described in the CMakeLists and in the corresponding cpp file.

NOTE: to manage to use lcov I had to do:
module load gcc+system/4.9 
export CXX=$mkCxxCompiler

To procede with compilation and to controll the code:
go in the directory BUILD and from command line:
cmake ..
make
make test 
./main
lcov --capture --directory ./CMakeFiles --output-file cov.info
genhtml cov.info --output-directory out
cd out
firefox index.html

In out you can look index.html and notice that each part of integer-list.h is covered now.


