#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;
   
  int c = 1;

  // create a new list
  Node start (c); 
   
  //I build the list 1,2
  int b=2;
  Node *second=new Node(b);//new node to add
  start.append(second);
    
  
  //test on isFirst

  //I ask him if start is the first, if it is correct it should return 1!
  bool f=start.isFirst();
  //I ask him if second is the first, if it is correct it should return 0!
  bool g=second->isFirst();

  fprintf(stdout,"start is first %d and second is first %d",f,g);

return 0;
}
