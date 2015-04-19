#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;
   
  int c = 1;

  // create a new list
  Node start (c); 
 start.appendNew(2);
  start.appendNew(3);
    
  //start.print ();
  
  //test on size
 
  int s=0;
  s=start.size(); //It should count 3 
  

  fprintf(stdout,"size %d", s);

return 0;
}
