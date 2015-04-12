#ifndef TETRAHEDON_CPP
#define TETRAHEDON_CPP
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include "tetrahedon.hpp"

bool TrianglenoOrient::operator()(Triangle const &a , Triangle const &b)const{
		auto amax1 = std::max(a.point1,a.point2);
		auto amax = std::max(amax1,a.point3);
		auto bmax1 = std::max(b.point1,b.point2);
		auto bmax = std::max(bmax1,b.point3);
		if(amax != bmax)
			return amax < bmax;
		else{
			auto amin1 = std::min(a.point1,a.point2);
			auto amin = std::min(amin1,a.point3);
			auto bmin1 = std::min(b.point1,b.point2);
			auto bmin = std ::min(bmin1,b.point3);
			if(amin != bmin)
				return amin < bmin;
			auto amiddle = a.point1 + a.point2 + a.point3 - amax - amin;
			auto bmiddle = b.point1 + b.point2 + b.point3 - bmax - bmin;
			return amiddle < bmiddle;
		}
	
	}


std::set<Triangle,TrianglenoOrient> triangles_with_no_repetition(std::vector<Tetrahedon> const &vt){	
	std::set<Triangle,TrianglenoOrient> noTriangle;
	for(auto i:vt){
		noTriangle.emplace(i.pnt1,i.pnt2,i.pnt3);
		noTriangle.emplace(i.pnt2,i.pnt3,i.pnt4);
		noTriangle.emplace(i.pnt3,i.pnt1,i.pnt4);
		noTriangle.emplace(i.pnt1,i.pnt2,i.pnt4);
		}
	return noTriangle;
}		

std::set<Triangle,TrianglenoOrient> faces_boundary(std::vector<Tetrahedon> const &vt){
	std::set<Triangle,TrianglenoOrient> boundary;
	std::pair<std::set<Triangle,TrianglenoOrient>::iterator,bool> ret;
	for(auto i:vt){
		ret = boundary.emplace(i.pnt1,i.pnt2,i.pnt3);
		if(!ret.second)
			boundary.erase(ret.first);
		else
			boundary.emplace(i.pnt1,i.pnt2,i.pnt3);
		
		ret = boundary.emplace(i.pnt2,i.pnt3,i.pnt4);
		if(!ret.second)
			boundary.erase(ret.first);
		else 
			boundary.emplace(i.pnt2,i.pnt3,i.pnt4);

		ret = boundary.emplace(i.pnt3,i.pnt1,i.pnt4);
		if(!ret.second)
			boundary.erase(ret.first);
		else 
			boundary.emplace(i.pnt3,i.pnt1,i.pnt4);
		
		ret = boundary.emplace(i.pnt1,i.pnt2,i.pnt4);
		if(!ret.second)
			boundary.erase(ret.first);
		else 
			boundary.emplace(i.pnt1,i.pnt2,i.pnt4);

	}
	return boundary;
}


#endif

