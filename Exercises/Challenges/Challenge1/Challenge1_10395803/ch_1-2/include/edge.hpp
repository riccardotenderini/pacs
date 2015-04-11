#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <utility>
#include <tuple>
#include <array>
#include <functional>

struct Edge {

	std::array<unsigned,2> pointID;
	
	Edge();
	
	Edge(unsigned const &, unsigned const &);

	Edge(std::array<unsigned,2> const &);

	Edge(Edge const &);

	~Edge();
	
	void print(std::ostream &) const;
	 
	void print() const;
	
	void operator=(Edge const &);
	
};

bool operator<(Edge const &, Edge const &);


