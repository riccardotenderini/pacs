#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;

  int a=3; 
  Node start(1);
  //verify setdata: I change data
  start.setData(a); 
 
  //I expect to obtain 3
  fprintf(stdout,"%d", start.getData());

return 0;
}
