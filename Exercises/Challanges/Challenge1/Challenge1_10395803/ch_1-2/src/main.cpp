#include "func.hpp"


int main() {
	
	std::vector<Triangle> v;
	v.push_back({0,1,7});
	v.push_back({1,2,7});
	v.push_back({2,3,4});
	v.push_back({2,4,7});
	v.push_back({5,4,7});
	v.push_back({5,6,7});
	v.push_back({0,6,7});
	
	std::set<Edge> s(AllEdges(v));
	std::cout << "Set of all edges :" << std::endl;
	for(std::set<Edge>::const_iterator i=s.cbegin(); i!=s.cend(); i++)
		i->print();
		
	s = BoundaryEdges(v);
	std::cout << "Set of boundary edges :" << std::endl;
	for(std::set<Edge>::const_iterator i=s.cbegin(); i!=s.cend(); i++)
		i->print();
	
	return 0;
	
}
