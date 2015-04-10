#ifndef EDGE_HPP
#define EDGE_HPP
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include "triangle.hpp"

struct Edge{
	unsigned first;
	unsigned second;
	Edge(const unsigned &a,const unsigned &b){
		first = a;
		second = b;
}
};


struct EdgenoOrient{
	bool operator()(Edge const &a , Edge const &b)const;
};

std::set<Edge,EdgenoOrient> edges_with_no_repetition(std::vector<Triangle> const &vt);

std::set<Edge,EdgenoOrient> edeges_boundary(std::vector<Triangle> const &vt);


#endif
