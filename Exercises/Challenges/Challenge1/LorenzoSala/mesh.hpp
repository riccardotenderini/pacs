#ifndef MESHEDGETRIATETRA
#define MESHEDGETRIATETRA

#include <utility>
#include <algorithm>
#include <tuple>
#include <array>
#include <vector>
#include <set>

using namespace std;

// Creo Edge
struct Edge
{
	Edge(const unsigned & a, const unsigned & b):pointId{a,b}{}
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
	Triangle(const unsigned & a, const unsigned & b, const unsigned & c):pointId{a,b,c}{}
	std::tuple<unsigned, unsigned, unsigned> pointId;
};

struct yesOrientTriangle{
	bool operator()(Triangle const & a, Triangle const & b)
	{
		return a.pointId < b.pointId; // sfrutto il confronto già implementato per tuple
	}	
};

struct noOrientTriangle{
	bool operator()(Triangle const & a, Triangle const & b)
	{
		auto amax = max(max(get<0>(a.pointId),get<1>(a.pointId)),max(get<1>(a.pointId),get<2>(a.pointId)));
		auto bmax = max(max(get<0>(b.pointId),get<1>(b.pointId)),max(get<1>(b.pointId),get<2>(b.pointId)));
		if(amax != bmax)
			return amax<bmax;
		auto amin = min(min(get<0>(a.pointId),get<1>(a.pointId)),min(get<1>(a.pointId),get<2>(a.pointId)));
		auto bmin = min(min(get<0>(b.pointId),get<1>(b.pointId)),min(get<1>(b.pointId),get<2>(b.pointId)));
		auto amid = get<0>(a.pointId)+get<1>(a.pointId)+get<2>(a.pointId)-amin-amax;
		auto bmid = get<0>(b.pointId)+get<1>(b.pointId)+get<2>(b.pointId)-bmin-bmax;
		if(amid != bmid)	
			return amid < bmid;
		return amin < bmin;
	}	
};

// Creo Tetra
struct Tetra
{
	Tetra(const unsigned & a, const unsigned & b, const unsigned & c, const unsigned & d):pointId{a,b,c,d}{}
	std::tuple<unsigned, unsigned, unsigned,unsigned> pointId;
};

struct yesOrientTetra{
	bool operator()(Tetra const & a, Tetra const & b)
	{
		return a.pointId < b.pointId; // sfrutto il confronto già implementato per tuple
	}	
};

// Function declarations
set<Edge,yesOrient> findedgeO(const vector<Triangle> & v);
set<Edge,noOrient> findedgeNO(const vector<Triangle> & v);
set<Edge,yesOrient> findinnerboundaries(const vector<Triangle> & v);
set<Edge,yesOrient> findboundary(const vector<Triangle> & v);
set<Triangle,yesOrientTriangle> findfaces(const vector<Tetra> & v);
set<Edge,yesOrient> findedges(const vector<Tetra> & v);
set<Triangle,noOrientTriangle> findboundaryTetra(const vector<Tetra> & v);

#endif
