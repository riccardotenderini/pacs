#ifndef EDGE_CPP
#define EDGE_CPP

#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include "triangle.hpp"
#include "edge.hpp"


bool EdgenoOrient::operator()(Edge const &a , Edge const &b)const{
		auto amax = std::max(a.first,a.second);
		auto bmax = std::max(b.first,b.second);
		if(amax != bmax)
			return amax < bmax;
		auto amin = std::min(a.first,a.second);
		auto bmin = std::min(b.first,b.second);
		return amin < bmin;
	
	}



std::set<Edge,EdgenoOrient> edges_with_no_repetition(std::vector<Triangle> const &vt){	
	std::set<Edge,EdgenoOrient> noEdges;
	for(auto i:vt){
		noEdges.emplace(i.point1,i.point2);
		noEdges.emplace(i.point2,i.point3);
		noEdges.emplace(i.point3,i.point1);
		}
	return noEdges;
}		
	 
std::set<Edge,EdgenoOrient> edeges_boundary(std::vector<Triangle> const &vt){
	std::set<Edge,EdgenoOrient> boundary;
	std::pair<std::set<Edge,EdgenoOrient>::iterator,bool> ret;
	for(auto i:vt){
		ret = boundary.emplace(i.point1,i.point2);
		if(!ret.second)
			boundary.erase(ret.first);
		else
			boundary.emplace(i.point1,i.point2);
		
		ret = boundary.emplace(i.point2,i.point3);
		if(!ret.second)
			boundary.erase(ret.first);
		else 
			boundary.emplace(i.point2,i.point3);

		ret = boundary.emplace(i.point3,i.point1);
		if(!ret.second)
			boundary.erase(ret.first);
		else 
			boundary.emplace(i.point3,i.point1);

	}
	return boundary;
}


#endif

				
