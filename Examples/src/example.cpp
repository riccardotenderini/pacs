#include <set>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{	
	Edge(const unsigned & a, const unsigned & b)
	{
		this -> pointId.first = a;
		this -> pointId.second = b;
	}
	std::pair<unsigned, unsigned> pointId;
};

// Potrei riutilizzare il confronto già inizializzato con pair che è orientato

struct yesOrient{
	bool operator()(Edge const & a, Edge const & b)
	{
		return a.pointId < b.pointId; // qua sfrutto appunto il confronto già implementato per pair
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

int main()
{
	vector<Edge> myedges;
	myedges.push_back(Edge(1,2));
	myedges.push_back(Edge(5,1));
	myedges.push_back(Edge(3,4));
	myedges.push_back(Edge(4,3));
	myedges.push_back(Edge(1,3));
	myedges.push_back(Edge(2,1)); 

	set<Edge,yesOrient> oEdges(myedges.begin(),myedges.end());
	set<Edge,noOrient> noEdges(myedges.begin(),myedges.end());
	
	cout << "With orientation: " << endl;
	for (auto i : oEdges)
	{
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	cout << "Without orientation: " << endl;
	for (auto i : noEdges)
	{
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}

}




	
