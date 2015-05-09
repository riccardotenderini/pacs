// [form and print a list of integers]
#include <iostream>
#include "integer-list.h"
#include <stdlib.h>

int main (int argc, char** argv)
{
  using namespace std;
  if(argc != 2){
	cout << "Non è stato inserito il numero di input necessari. Chiamare ./integer-list [c] " << endl;
	return 0;
  }

  int c = atoi(argv[1]);

  // create a new list
  Node start (c);
  Node newnode;
  newnode.setData(11);
  newnode.setNext(NULL);
  
  // add 10 nodes to the list
  while (c < 10)
    {
      c++;
      start.appendNew (c);
    }

  // print the list
  std::cout << "Lista iniziale: " << std::endl;
  start.print ();

  //appendo il nuovo nodo
  Node *t = &start;
 
  // start.append(&newnode);

  // print the list
  // start.print();

  // find the node with value 5
  t = start.find (5);
  Node * t2 = start.find(7);

  start.swap(t,t2);
  // print the list
  std::cout << "Scambio il 5 con il 7: " << std::endl;
  start.print();
  
  // erase this node
  t = start.find (7);
  t -> erase ();

  // print the list again
  std::cout << "Cancello il 7: " << std::endl;
  start.print ();
  
  // Stampa le dimensioni
  int size = start.size();
  cout << "Dimensioni della lista: " << size+1 << endl;
  
  return 0;
}
