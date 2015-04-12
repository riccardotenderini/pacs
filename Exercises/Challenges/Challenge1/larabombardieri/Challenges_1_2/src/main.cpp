//
//
// main.cpp
//
//

#include<iostream>
#include<vector>
#include<algorithm>
#include "Geometry2D.hpp"

int main(){
  // Constructing the mesh
  std::vector<Triangle> Mesh;
  Mesh.emplace_back(1,2,3);
  Mesh.emplace_back(2,4,3);
  Mesh.emplace_back(2,5,43);
  print_Mesh(Mesh); // print the mesh

  // Building the set of all the edges (not considering the order, i.e. {1,5}={5,1})
  type_Edges_set Edges_list=get_Mesh_Edges(Mesh);

  // Building the set of the boundary edges
  type_Edges_set BoundaryEdges_list=get_Mesh_BoundaryEdges(Mesh);

  // printing the results
  std::cout<<"\nThe mesh contains the following edges :"<<std::endl;
  print_Edges(Edges_list);
  std::cout<<"\nThe boundary edges are :"<<std::endl;
  print_Edges(BoundaryEdges_list);
  
  return(0);
}
