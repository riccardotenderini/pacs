#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;

  int a=3; 
  Node start(a);

  //I build the list
  int b=4;
  start.appendNew(b);

  // start.print();
 
  // the list data are 3, 4 

  //I want that the element to find is the first in the list
  Node* t = start.find (3);

  //I want that the element to find isn't in the list
  Node* tt = start.find (70);

  
 bool firstvalue;
 bool valuenolist;


 if( tt==NULL) valuenolist=1; 
//If the function find works properly it should be tt==NULL because 70 isn't in the list

 if(t->isFirst()) firstvalue=1;
//I check that I've executed the part of find that I wanted to test, so I check that t points to the first element
 
  fprintf(stdout,"%d and %d", firstvalue,valuenolist);



return 0;}
