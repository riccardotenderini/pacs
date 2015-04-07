#include "triangle.hpp"


struct Tetrahedron {

	std::array<unsigned,4> pointID;
	
	Tetrahedron();
	
	Tetrahedron(unsigned const &, unsigned const &, unsigned const &, unsigned const &);
	
	Tetrahedron(std::array<unsigned,4> const &);
	
	~Tetrahedron();
	
	void print(std::ostream & os) const;
	
	void print() const;
	
	void ExtractFaces(std::array<Triangle,4> &) const;

};

