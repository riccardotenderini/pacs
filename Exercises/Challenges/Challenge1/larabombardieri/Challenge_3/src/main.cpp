//
//
// main.cpp
//
//

#include<iostream>
#include<vector>
#include<algorithm>
#include "Geometry3D.hpp"

int main(){
  
  // Constructing the mesh
  std::vector<Tetrahedron> Mesh;
  Mesh.emplace_back(1,2,3,4);
  Mesh.emplace_back(2,5,4,3);
  //Mesh.emplace_back(2,6,3,5);
  print_Mesh(Mesh); // print the mesh
 
  // Building the set of all the faces (not considering the order, i.e. {1,2,3}={3,2,1})
  type_Triangles_set Faces_list=get_Mesh_Faces(Mesh);
  
  // Building the set of the boundary edges
  type_Triangles_set BoundaryFaces_list=get_Mesh_BoundaryFaces(Mesh);
  
  // printing the results
  std::cout<<"\nThe mesh contains the following faces :"<<std::endl;
  print_Triangles(Faces_list);
  std::cout<<"\nThe boundary faces are :"<<std::endl;
  print_Triangles(BoundaryFaces_list);
  
  return(0);
}
