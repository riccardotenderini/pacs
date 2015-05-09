# CMake generated Testfile for 
# Source directory: /home/pacs_student/Desktop/pacs/Exercises/Challenges/Challenge3/LorenzoSala
# Build directory: /home/pacs_student/Desktop/pacs/Exercises/Challenges/Challenge3/LorenzoSala
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Integer-listRuns1 "integer-list" "1")
add_test(Integer-listRuns2 "integer-list" "7")
add_test(Integer-listRuns3 "integer-list" "12")
add_test(Integer-listUsage1 "integer-list" "5" "Lista iniziale: 
5, 6, 7, 8, 9, 10
Scambio il 5 con il 7: 
7, 6, 5, 8, 9, 10
Cancello il 7: 
6, 5, 8, 9, 10
Dimensioni della lista: 5")
add_test(Integer-listUsage2 "integer-list" "11" "Lista iniziale: 
11
Scambio il 5 con il 7: 
11
Cancello il 7: 
11
Dimensioni della lista: 1")
add_test(Integer-listUsage3 "integer-list" "7" "Lista iniziale: 
7, 8, 9, 10
Scambio il 5 con il 7: 
7, 8, 9, 10
Cancello il 7: 
8, 9, 10
Dimensioni della lista: 3")
add_test(Integer-listUsage4 "integer-list" "1" "Lista iniziale: 
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
Scambio il 5 con il 7: 
1, 2, 3, 4, 7, 6, 5, 8, 9, 10
Cancello il 7: 
1, 2, 3, 4, 6, 5, 8, 9, 10
Dimensioni della lista: 9")
add_test(Integer-listErrorMessage "integer-list" "Non è stato inserito il numero di input necessari. Chiamare ./integer-list [c] ")
