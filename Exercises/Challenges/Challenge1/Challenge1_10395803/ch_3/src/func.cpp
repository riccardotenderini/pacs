#include "func.hpp"


std::set<Triangle> AllFaces(std::vector<Tetrahedron> const & v) {
	std::set<Triangle> s;
	std::array<Triangle,4> aux;
	std::pair<std::set<Triangle>::iterator,bool> p;
	for (auto i : v) {
		i.ExtractFaces(aux);
		for (auto j : aux)
			p = s.insert(j);
	}
	return s;
}


std::set<Triangle> BoundaryFaces(std::vector<Tetrahedron> const & v) {
	std::set<Triangle> s;
	std::array<Triangle,4> aux;
	std::pair<std::set<Triangle>::iterator,bool> p;
	for (auto i : v) {
		i.ExtractFaces(aux);
		for (auto j : aux) {
			p = s.insert(j);
			if (!p.second)
				s.erase(p.first);
		}
	}
	return s;
}




