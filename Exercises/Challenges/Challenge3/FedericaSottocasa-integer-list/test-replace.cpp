#include <iostream>
#include "integer-list.h"
#include <cstdio>

int main (int argc, char** argv)
{
  using namespace std;

  int a=3; 
  Node *start=new Node(a);//new node to add

  //I build the list
  int b=4;
  Node *second=new Node(b);//new node to add
  start->append(second);

  int c=5;
  Node *third=new Node(c);//new node to add
  start->append(third);

  int d=6;
  Node *fourth=new Node(d);//new node to add
  start->append(fourth);

  //start.print();
 
  // the list data are 3, 4 , 5 ,6

  //I change the second node with one containing data=10
  int e=10;
  Node *newsecond=new Node(e);//new node that replace the second
  second->replaceWith(newsecond);

    //I change the third node with one containing data=12
   int f=12;
  Node *newthird=new Node(f);//new node that replace the third
  third->replaceWith(newthird);

    //I change the fourth node with one containing data=15
   int g=15;
  Node *newfourth=new Node(g);//new node that replace the fourth
  fourth->replaceWith(newfourth);

   //I change also the first node with one containing data=70
  int h=70;
  Node *newfirst=new Node(h);//new node that replace the second
  start->replaceWith(newfirst);

  //newfirst->print();

 //newlist:70 10 12 15

 // I traverse the list to verify the correct use of Replace


 Node* tt = newfirst;

  while( tt!=NULL) {
               
        fprintf(stdout,"%d ", tt->getData ());
        fseek(stdout,0,SEEK_CUR); //to avoid overwriting of the file
        tt = tt->getNext ();
      } 

return 0;
}
