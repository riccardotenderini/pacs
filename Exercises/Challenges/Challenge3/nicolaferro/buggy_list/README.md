This directory contains my solution for the third challenge.
Six tests are provided in order to check all the methods of the class Node.
A BUILD directory (empty) is provided in order to contain the executable running
$ cmake ..
Make sure that the compiler used is gcc 4.9 to avoid problems with the version of gcov.

After:
$ make
$ make test

Check the coverage with the following commands:
$ lcov --capture --directory ./CMakeFiles/ --output-file coverage.info
$ genhtml coverage.info --output-directory out
