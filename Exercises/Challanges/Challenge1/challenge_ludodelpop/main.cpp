#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

#include "triangle.hpp"
#include "tetrahedon.hpp"
#include "edge.hpp"

int main(){
	std::vector<Triangle> mesh;
	mesh.emplace_back(1,2,3);
	mesh.emplace_back(2,4,3);
	std::set<Edge, EdgenoOrient> edges_no_rep;
	std::set<Edge, EdgenoOrient> boundary_edges;
	edges_no_rep = edges_with_no_repetition( mesh);
	boundary_edges = edeges_boundary(mesh);
	std::cout<<"All edges without repetition are:"<<std::endl;
	
	for(auto i:edges_no_rep){
		std::cout<<i.first<<" "<<i.second<<std::endl;
	}
	std::cout<<"Boundary edges are:"<<std::endl;
	
	for(auto i:boundary_edges){
		std::cout<<i.first<<" "<<i.second<<std::endl;
	}


	std::vector<Tetrahedon> mesh3d;
	mesh3d.emplace_back(1,2,3,4);
	mesh3d.emplace_back(2,5,3,4);
	std::set<Triangle, TrianglenoOrient> triangle_no_rep;
	std::set<Triangle, TrianglenoOrient> trg_boundary;
	triangle_no_rep = triangles_with_no_repetition(mesh3d);
	trg_boundary = faces_boundary(mesh3d); 
	std::cout<<"All triangles without repetition are:"<<std::endl;
	
	for(auto i:triangle_no_rep){
		std::cout<<i.point1<<" "<<i.point2<<" "<<i.point3<<std::endl;
	}
	std::cout<<"The boundary faces are:"<<std::endl;
	for(auto i:trg_boundary){
		std::cout<<i.point1<<" "<<i.point2<<" "<<i.point3<<std::endl;
	}

} 

	
