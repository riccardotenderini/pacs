#include <iostream>
#include "integer-list.h"

int main (int argc, char** argv)
{
  using namespace std;
  int c = 1;

  Node trial(c);
  for(unsigned i=c+1; i<=5; i++)
	trial.appendNew(i);

  Node* first = trial.find(c);

  if((*first).isFirst() == 1)
	return 0;
  else
	return 1;
}
