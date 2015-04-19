#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;
   
  int c = 1;
  // create a new list made by 1,2,3
  Node start (c);

  Node *second=new Node(2);//new node to add
  start.append(second);

  Node *third=new Node(3);//new node to add
  start.append(third);
   
    
  //start.print ();
  
   
  //test on getPrevious 
  //returns a pointer to the second node that stores value 2
  Node *prec;
  prec=third->getPrevious() ;

   //test on getNext
  //returns a pointer to the second node that stores value 2
  Node *succ;
  succ=start.getNext() ;
  
  //I check the value stored in the Node pointers to verify that getNext and getPrevious points to the correct node
  fprintf(stdout,"%d and %d",prec->getData(),succ->getData());

return 0;


}
