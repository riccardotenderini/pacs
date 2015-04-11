#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <utility>
#include <tuple>
#include <array>
#include <functional>

struct Triangle{

	std::array<unsigned,3> pointID;
	
	Triangle();
	
	Triangle(unsigned const &, unsigned const &, unsigned const &);

	Triangle(std::array<unsigned,3> const &);

	Triangle(Triangle const &);

	~Triangle();
	
	
	void print(std::ostream &) const;
	
	void print() const;

};

bool operator<(Triangle const &, Triangle const &);


