#include "edge.hpp"


Edge::Edge() : pointID{} {}
	

Edge::Edge(unsigned const & a, unsigned const & b) : pointID{a,b} {}

	
Edge::Edge(std::array<unsigned,2> const & a) : pointID(a) {}


Edge::Edge(Edge const & ed) : pointID(ed.pointID) {}


Edge::~Edge() {}
	

void Edge::print(std::ostream & os) const {
	os << pointID[0] << "--" << pointID[1] << std::endl;	
}


void Edge::print() const {
	print(std::cout);
}


	
void Edge::operator=(Edge const & ed){
	for (std::array<unsigned,2>::size_type i=0; i<2; i++)
		this->pointID[i] = ed.pointID[i];
}


bool operator<(Edge const & e1, Edge const & e2) {
	unsigned e1max = *std::max_element(e1.pointID.begin(), e1.pointID.end());
	unsigned e2max = *std::max_element(e2.pointID.begin(), e2.pointID.end());
	if (e1max != e2max)
		return e1max < e2max;
	unsigned e1min = *std::min_element(e1.pointID.begin(), e1.pointID.end());
	unsigned e2min = *std::min_element(e2.pointID.begin(), e2.pointID.end());
	return e1min < e2min;
}


