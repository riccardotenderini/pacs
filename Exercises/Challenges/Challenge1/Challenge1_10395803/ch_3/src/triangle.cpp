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


bool operator<(Triangle const & a, Triangle const & b) {
	unsigned amax = *std::max_element(a.pointID.begin(),a.pointID.end());
	unsigned bmax = *std::max_element(b.pointID.begin(),b.pointID.end());
	if (amax != bmax)
		return (amax < bmax);
	unsigned amin = *std::min_element(a.pointID.begin(),a.pointID.end());
	unsigned bmin = *std::min_element(b.pointID.begin(),b.pointID.end());
	unsigned amid = std::accumulate(a.pointID.begin(),a.pointID.end(),0)-amax-amin;
	unsigned bmid = std::accumulate(b.pointID.begin(),b.pointID.end(),0)-bmax-bmin;
	if (amid != bmid)
		return (amid < bmid);
	return (amin < bmin);
}


