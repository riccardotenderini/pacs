#include <iostream>
#include "integer-list.h"

int main (int argc, char** argv)
{
  using namespace std;

  Node trial;
  trial.setData(1);

  if(trial.getData() == 1)
	return 0;
  else
	return 1;
}
