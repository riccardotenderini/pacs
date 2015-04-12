#ifndef TETRAHEDON_HPP
#define TETRAHEDON_HPP
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include "triangle.hpp"



struct Tetrahedon{
	unsigned pnt1;
	unsigned pnt2;
	unsigned pnt3;
	unsigned pnt4;
        Tetrahedon(const unsigned &a, const unsigned &b, const unsigned &c, const unsigned &d){
		pnt1 = a;
		pnt2 = b;
		pnt3 = c;
		pnt4 = d;
}
};

struct TrianglenoOrient{
	bool operator()(Triangle const &a , Triangle const &b)const;
};

std::set<Triangle,TrianglenoOrient> triangles_with_no_repetition(std::vector<Tetrahedon> const &vt);

std::set<Triangle,TrianglenoOrient> faces_boundary(std::vector<Tetrahedon> const &vt);


#endif
