#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

struct Triangle{
	unsigned point1;
	unsigned point2;
	unsigned point3;
	Triangle(const unsigned &a,const unsigned &b,const unsigned &c){ 
		point1 = a;
		point2 = b;
		point3 = c;
}
};

#endif
