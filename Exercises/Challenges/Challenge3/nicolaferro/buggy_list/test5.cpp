#include <iostream>
#include "integer-list.h"

int main (int argc, char** argv)
{
  using namespace std;
  int c = 1;

  Node trial(c);
  for(unsigned i=c+1; i<5; i++)
	trial.appendNew(i);

  Node* pointer = new Node(6);
  Node* second = trial.find(2);
  (*second).replaceWith(pointer);

  if(trial.size() == 4 && trial.find(6) != NULL && trial.find(2) == NULL)
	return 0;
  else
	return 1;
}
