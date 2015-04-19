#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;

  int a=3; 
  Node start(a);
 
  //verify append
  int b=4;
  Node *second=new Node(b);//new node to add
  start.append(second);

   int c=5;
  Node *third=new Node(c);//new node to add
  start.append(third);

  //to verify that the second and third node are now in the list I traverse the list and controll

 //other idea could be find the presence of the value in the list and check the size of the list
 //but I prefer to traverse the list: I think it is a stronger test!
 

 Node* tt = & start;
 while(tt!=NULL) 
      {
        fprintf(stdout,"%d ", tt->getData ());
        fseek(stdout,0,SEEK_CUR);  //to avoid overwriting of the file
        tt = tt->getNext ();
      }
 
 
return 0;
}
