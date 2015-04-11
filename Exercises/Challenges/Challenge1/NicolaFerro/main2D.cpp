#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct Edge{
	unsigned v1;
	unsigned v2;

	Edge(unsigned a, unsigned b): v1(a), v2(b) {}
};

struct Triangle{
	unsigned v1;
	unsigned v2;
	unsigned v3;

	Triangle(unsigned a, unsigned b, unsigned c): v1(a), v2(b), v3(c) {}
};

//Ordering relation not considering orientation
struct notOr{
	bool operator()(Edge const & E1, Edge const & E2){
		unsigned max1 = std::max(E1.v1, E1.v2);
		unsigned max2 = std::max(E2.v1, E2.v2);
		if (max1 != max2) return max1 < max2;

		unsigned min1 = std::min(E1.v1, E1.v2);
		unsigned min2 = std::min(E2.v1, E2.v2);
		return min1 < min2;
	}
};

//Ordering relation considering orientation
struct Or{
	bool operator()(Edge const & E1, Edge const & E2){

		if (E1.v1 != E2.v1) return E1.v1 < E2.v1;

		return E1.v2 < E2.v2;
	}
};

//Functions that deal with oriented edges
std::set<Edge, Or> getEdges_OR(std::vector<Triangle> const & mesh){
	std::set<Edge, Or> edges;

	for(auto i:mesh){
		Edge L1(i.v1, i.v2);
		Edge L2(i.v2, i.v3);
		Edge L3(i.v3, i.v1);
		
		auto o1 = edges.insert(L1);
		auto o2 = edges.insert(L2);
		auto o3 = edges.insert(L3);
	}
	return edges;
};

std::set<Edge, notOr> getBoundaries_OR(std::vector<Triangle> const & mesh){
	std::set<Edge, notOr> boundaries;

	for(auto i:mesh){
		Edge L1(i.v1, i.v2);
		Edge L2(i.v2, i.v3);
		Edge L3(i.v3, i.v1);
		
		auto o1 = boundaries.insert(L1);
		if (o1.second == false) boundaries.erase(L1);

		auto o2 = boundaries.insert(L2);
		if (o2.second == false) boundaries.erase(L2);

		auto o3 = boundaries.insert(L3);
		if (o3.second == false) boundaries.erase(L3);
	}
	return boundaries;
};

//Functions that deal with unoriented edge
std::set<Edge, notOr> getEdges_NOR(std::vector<Triangle> const & mesh){
	std::set<Edge, notOr> edges;

	for(auto i:mesh){
		Edge L1(i.v1, i.v2);
		Edge L2(i.v1, i.v3);
		Edge L3(i.v2, i.v3);
		
		auto o1 = edges.insert(L1);
		auto o2 = edges.insert(L2);
		auto o3 = edges.insert(L3);
	}
	return edges;
};

std::set<Edge, notOr> getBoundaries_NOR(std::vector<Triangle> const & mesh){
	std::set<Edge, notOr> boundaries;

	for(auto i:mesh){
		Edge L1(i.v1, i.v2);
		Edge L2(i.v1, i.v3);
		Edge L3(i.v2, i.v3);
		
		auto o1 = boundaries.insert(L1);
		if (o1.second == false) boundaries.erase(L1);

		auto o2 = boundaries.insert(L2);
		if (o2.second == false) boundaries.erase(L2);

		auto o3 = boundaries.insert(L3);
		if (o3.second == false) boundaries.erase(L3);
	}
	return boundaries;
};

int main(){
	Triangle T1(0,1,2);
	Triangle T2(1,3,2);
	Triangle T3(0,2,3);

	std::vector<Triangle> Th{T1,T2,T3};

	std::cout<<"Do you want to consider orientation of the edges? [Y/N]"<<std::endl;
	char answ;
	std::cin>> answ;	

	if(answ == 'N' || answ == 'n'){
		auto edges=getEdges_NOR(Th);
		auto boundaries=getBoundaries_NOR(Th);
	
		//Print sets
		std::cout<<"The edges in the mesh are:"<<std::endl;
		for (auto i:edges){
			std::cout<<i.v1<<" "<<i.v2<<std::endl;
		}

		std::cout<<"The boundaries in the mesh are:"<<std::endl;
		for (auto i:boundaries){
			std::cout<<i.v1<<" "<<i.v2<<std::endl;
		}
	}else if(answ == 'Y' || answ == 'y'){
		auto edges=getEdges_OR(Th);
		auto boundaries=getBoundaries_OR(Th);
	
		//Print sets
		std::cout<<"The (oriented) edges in the mesh are:"<<std::endl;
		for (auto i:edges){
			std::cout<<i.v1<<" "<<i.v2<<std::endl;
		}

		std::cout<<"The (oriented) boundaries in the mesh are:"<<std::endl;
		for (auto i:boundaries){
			std::cout<<i.v1<<" "<<i.v2<<std::endl;
		}
	}
	else{
		std::cout<<"Input value not recognized."<<std::endl;
	}

	return 0;	
}
