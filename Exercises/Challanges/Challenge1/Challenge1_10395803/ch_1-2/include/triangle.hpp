#include "edge.hpp"

struct Triangle{

	std::array<unsigned,3> pointID;
	
	Triangle();
	
	Triangle(unsigned const &, unsigned const &, unsigned const &);

	Triangle(std::array<unsigned,3> const &);

	Triangle(Triangle const &);

	~Triangle();
	
	
	void print(std::ostream &) const;
	
	void print() const;
	
	void ExtractEdges(std::array<Edge,3> &) const;

};



