#include <iostream>
#include "integer-list.h"

int main (int argc, char** argv)
{
  using namespace std;
  int c = 1;

  Node trial(c);
  for(unsigned i=c+1; i<5; i++)
	trial.appendNew(i);

  Node new_node(6);
  Node* pointer = new Node(6);
  trial.append(pointer);

  if(trial.size() == 5 && trial.find(6) != NULL)
	return 0;
  else
	return 1;
}
