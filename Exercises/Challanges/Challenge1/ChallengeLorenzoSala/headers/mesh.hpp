#include <utility>
#include <algorithm>
#include <tuple>
#include <array>

using namespace std;

// Creo Edge
struct Edge
{
	Edge(const unsigned & a, const unsigned & b)
	{
		this -> pointId.first = a;
		this -> pointId.second = b;
	}
	std::pair<unsigned, unsigned> pointId;
};

struct yesOrient{
	bool operator()(Edge const & a, Edge const & b)
	{
		return a.pointId < b.pointId; // sfrutto il confronto già implementato per pair
	}	
};

struct noOrient{
	bool operator()(Edge const & a, Edge const & b)
	{
		auto amax = max(a.pointId.first,a.pointId.second);
		auto bmax = max(b.pointId.first,b.pointId.second);
		if(amax != bmax)
			return amax<bmax;
		auto amin = min(a.pointId.first,a.pointId.second);
		auto bmin = min(b.pointId.first,b.pointId.second);
		return amin < bmin;
	}	
};


// Creo Triangle
struct Triangle
{
	Triangle(const unsigned & a, const unsigned & b, const unsigned & c)
	{
		get<0>(this->pointId) = a;
		get<1>(this->pointId) = b;
		get<2>(this->pointId) = c;
	}
	std::tuple<unsigned, unsigned, unsigned> pointId;
};

struct yesOrientTr{
	bool operator()(Triangle const & a, Triangle const & b)
	{
		return a.pointId < b.pointId; // sfrutto il confronto già implementato per tuple
	}	
};

/*
void TriangleOrientation(Triangle & T){
	array<unsigned,3> v {{get<0>(T.pointId),get<1>(T.pointId),get<2>(T.pointId)}}; 
	sort(begin(v),end(v));
	
	get<0>(T.pointId) = v[0];
	get<1>(T.pointId) = v[1];
	get<2>(T.pointId) = v[2];
	return;
}
*/

// Creo Tetra
struct Tetra
{
	Tetra(const unsigned & a, const unsigned & b, const unsigned & c, const unsigned & d)
	{
		get<0>(this->pointId) = a;
		get<1>(this->pointId) = b;
		get<2>(this->pointId) = c;
		get<3>(this->pointId) = d;
	}
	std::tuple<unsigned, unsigned, unsigned,unsigned> pointId;
};

struct yesOrientTetra{
	bool operator()(Tetra const & a, Tetra const & b)
	{
		return a.pointId < b.pointId; // sfrutto il confronto già implementato per tuple
	}	
};

