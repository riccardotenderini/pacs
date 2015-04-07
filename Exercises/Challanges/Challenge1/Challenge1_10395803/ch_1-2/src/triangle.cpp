#include "triangle.hpp"

	
Triangle::Triangle() : pointID{} {}
	

Triangle::Triangle(unsigned const & a, unsigned const & b, unsigned const & c) : pointID{a,b,c} {}


Triangle::Triangle(std::array<unsigned,3> const & a) : pointID(a) {}


Triangle::Triangle(Triangle const & tr) : pointID(tr.pointID) {}


Triangle::~Triangle() {}
	
	
void Triangle::print(std::ostream & os) const {
	os << pointID[0] << "--" << pointID[1] << "--" << pointID[2] << std::endl;
}
	

void Triangle::print() const {
	print(std::cout);
}
	
	
void Triangle::ExtractEdges(std::array<Edge,3> & v) const {		
	for (std::size_t i=0; i<3; i++)
		v[i] = Edge(pointID[i%3],pointID[(i+1)%3]);
}



