#include "func.hpp"


std::set<Edge> AllEdges(std::vector<Triangle> const & v) {
	std::set<Edge> s;
	std::array<Edge,3> aux;
	std::pair<std::set<Edge>::iterator,bool> p;
	for (auto i : v) {
		i.ExtractEdges(aux);
		for (auto j : aux)
			p = s.insert(j);
	}
	return s;
}


std::set<Edge> BoundaryEdges(std::vector<Triangle> const & v) {
	std::set<Edge> s;
	std::array<Edge,3> aux;
	std::pair<std::set<Edge>::iterator,bool> p;
	for (auto i : v) {
		i.ExtractEdges(aux);
		for (auto j : aux) {
			p = s.insert(j);
			if (!p.second)
				s.erase(p.first);
		}
	}
	return s;
}


