#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>

struct Triangle{
	unsigned v1;
	unsigned v2;
	unsigned v3;

	Triangle(unsigned a, unsigned b, unsigned c): v1(a), v2(b), v3(c) {}
};

struct Tetrahedron{
	unsigned v1;
	unsigned v2;
	unsigned v3;
	unsigned v4;

	Tetrahedron(unsigned a, unsigned b, unsigned c, unsigned d): v1(a), v2(b), v3(c), v4(d) {}
};

//Ordering relation not considering orientation
struct notOr{
	bool operator()(Triangle const & T1, Triangle const & T2){
		std::array<unsigned, 3> t1={T1.v1, T1.v2, T1.v3};
		std::array<unsigned, 3> t2={T2.v1, T2.v2, T2.v3};

		std::sort(t1.begin(), t1.end());
		std::sort(t2.begin(), t2.end());

		if(t1[0] != t2[0]) return t1[0]<t2[0];
		if(t1[1] != t2[1]) return t1[1]<t2[1];
		return t1[2]<t2[2];
	}
};

//Ordering relation considering orientation
struct Or{
	bool operator()(Triangle const & T1, Triangle const & T2){

		if (T1.v1 != T2.v1) return T1.v1 < T2.v1;
		if (T1.v2 != T2.v2) return T1.v2 < T2.v2;
		return T1.v3 < T2.v3;
	}
};

//Functions that deal with oriented edges
std::set<Triangle, Or> getFacets_OR(std::vector<Tetrahedron> const & mesh){
	std::set<Triangle, Or> facets;

	for(auto i:mesh){
		Triangle T1(i.v1, i.v2, i.v4);
		Triangle T2(i.v1, i.v4, i.v3);
		Triangle T3(i.v3, i.v4, i.v2);
		Triangle T4(i.v1, i.v2, i.v3);
		
		auto o1 = facets.insert(T1);
		auto o2 = facets.insert(T2);
		auto o3 = facets.insert(T3);
		auto o4 = facets.insert(T4);
	}
	return facets;
};

std::set<Triangle, notOr> getExtFacets_OR(std::vector<Tetrahedron> const & mesh){
	std::set<Triangle, notOr> extfacets;

	for(auto i:mesh){
		Triangle T1(i.v1, i.v2, i.v4);
		Triangle T2(i.v1, i.v4, i.v3);
		Triangle T3(i.v3, i.v4, i.v2);
		Triangle T4(i.v1, i.v2, i.v3);
		
		auto o1 = extfacets.insert(T1);
		if (o1.second == false) extfacets.erase(T1);

		auto o2 = extfacets.insert(T2);
		if (o2.second == false) extfacets.erase(T2);

		auto o3 = extfacets.insert(T3);
		if (o3.second == false) extfacets.erase(T3);

		auto o4 = extfacets.insert(T4);
		if (o4.second == false) extfacets.erase(T4);
	}
	return extfacets;
};

//Functions that deal with unoriented edge
std::set<Triangle, notOr> getFacets_NOR(std::vector<Tetrahedron> const & mesh){
	std::set<Triangle, notOr> facets;

	for(auto i:mesh){
		Triangle T1(i.v1, i.v2, i.v4);
		Triangle T2(i.v1, i.v4, i.v3);
		Triangle T3(i.v3, i.v4, i.v2);
		Triangle T4(i.v1, i.v2, i.v3);
		
		auto o1 = facets.insert(T1);
		auto o2 = facets.insert(T2);
		auto o3 = facets.insert(T3);
		auto o4 = facets.insert(T4);
	}
	return facets;
};

std::set<Triangle, notOr> getExtFacets_NOR(std::vector<Tetrahedron> const & mesh){
	std::set<Triangle, notOr> extfacets;

	for(auto i:mesh){
		Triangle T1(i.v1, i.v2, i.v4);
		Triangle T2(i.v1, i.v4, i.v3);
		Triangle T3(i.v3, i.v4, i.v2);
		Triangle T4(i.v1, i.v2, i.v3);
		
		auto o1 = extfacets.insert(T1);
		if (o1.second == false) extfacets.erase(T1);

		auto o2 = extfacets.insert(T2);
		if (o2.second == false) extfacets.erase(T2);

		auto o3 = extfacets.insert(T3);
		if (o3.second == false) extfacets.erase(T3);

		auto o4 = extfacets.insert(T4);
		if (o4.second == false) extfacets.erase(T4);
	}
	return extfacets;
};

int main(){
	Tetrahedron Tetra1(1,2,3,4);
	Tetrahedron Tetra2(2,5,3,4);

	std::vector<Tetrahedron> Th{Tetra1,Tetra2};

	std::cout<<"Do you want to consider orientation of the edges? [Y/N]"<<std::endl;
	char answ;
	std::cin>> answ;	

	if(answ == 'N' || answ == 'n'){
		auto facets=getFacets_NOR(Th);
		auto extfacets=getExtFacets_NOR(Th);
	
		//Print sets
		std::cout<<"The facets in the mesh are:"<<std::endl;
		for (auto i:facets){
			std::cout<<i.v1<<" "<<i.v2<<" "<<i.v3<<std::endl;
		}

		std::cout<<"The external facets in the mesh are:"<<std::endl;
		for (auto i:extfacets){
			std::cout<<i.v1<<" "<<i.v2<<" "<<i.v3<<std::endl;
		}
	}else if(answ == 'Y' || answ == 'y'){
		auto facets=getFacets_OR(Th);
		auto extfacets=getExtFacets_OR(Th);
	
		//Print sets
		std::cout<<"The (oriented) facets in the mesh are:"<<std::endl;
		for (auto i:facets){
			std::cout<<i.v1<<" "<<i.v2<<" "<<i.v3<<std::endl;
		}

		std::cout<<"The (oriented) external facets in the mesh are:"<<std::endl;
		for (auto i:extfacets){
			std::cout<<i.v1<<" "<<i.v2<<" "<<i.v3<<std::endl;
		}
	}
	else{
		std::cout<<"Input value not recognized."<<std::endl;
	}

	return 0;	
}
