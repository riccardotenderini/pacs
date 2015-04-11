#include "tetrahedron.hpp"


Tetrahedron::Tetrahedron() : pointID{} {}
	

Tetrahedron::Tetrahedron(unsigned const & a, unsigned const & b, unsigned const & c, unsigned const & d) : pointID{a,b,c,d} {}
	

Tetrahedron::Tetrahedron(std::array<unsigned,4> const & v) : pointID(v) {}
	

Tetrahedron::~Tetrahedron() {}
	

void Tetrahedron::print(std::ostream & os) const {
	for (std::array<unsigned,4>::size_type i=0; i<3; i++)
		os << pointID[i] << "--";
	os << pointID[4] << std::endl;
}
	

void Tetrahedron::print() const {
	print(std::cout);
}
	

void Tetrahedron::ExtractFaces(std::array<Triangle,4> & v) const {
	v[0] = Triangle(pointID[1],pointID[2],pointID[3]);
	v[1] = Triangle(pointID[0],pointID[2],pointID[3]);
	v[2] = Triangle(pointID[0],pointID[1],pointID[3]);
	v[3] = Triangle(pointID[0],pointID[1],pointID[2]);
}








