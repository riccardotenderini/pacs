#include "func.hpp" 

int main() {

	std::vector<Tetrahedron> v;
	v.push_back({0,2,3,1});
	v.push_back({4,3,2,0});
	
	std::set<Triangle> s = AllFaces(v);
	std::cout << "Set of all faces :" << std::endl;
	for (std::set<Triangle>::const_iterator i=s.cbegin(); i!=s.cend(); i++)
		i->print();
	
	s = BoundaryFaces(v);
	std::cout << "Set of boundary faces :" << std::endl;
	for (std::set<Triangle>::const_iterator i=s.cbegin(); i!=s.cend(); i++)
		i->print();
		
	return 0;
	
}
