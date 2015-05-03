#include <iostream>
#include "integer-list.h"

int main (int argc, char** argv)
{
  using namespace std;

  Node trial;

  if(trial.getNext() == NULL && trial.getPrevious() == NULL)
	return 0;
  else
	return 1;

}
