#include<utility>

#include "tetrahedron.hpp"


//Extract faces from a mesh made of tetrahedrons
std::set<Triangle,compTriangles> findFaces(std::vector<Tetrahedron> const& mesh){
  std::set<Triangle,compTriangles> faces;
  for(std::vector<Tetrahedron>::const_iterator t=mesh.begin(); t!=mesh.end(); t++){
    std::array<Point,4> tetra(t->getPoints());
    for(std::size_t i(0); i<4; i++){
      faces.insert(Triangle(tetra[i],tetra[(i+1)%4],tetra[(i+2)%4]));
    }
  }
  return faces;
}

//Extract boundary faces from a mesh made of tetrahedrons
std::set<Triangle,compTriangles> findBoundaryFaces(std::vector<Tetrahedron> const& mesh){
  std::set<Triangle,compTriangles> bdryFaces;
  for(std::vector<Tetrahedron>::const_iterator t=mesh.begin(); t!=mesh.end(); t++){
    std::array<Point,4> tetra(t->getPoints());
    for(std::size_t i(0); i<4; i++){
      std::pair<std::set<Triangle,compTriangles>::iterator,bool> inserted(bdryFaces.insert(Triangle(tetra[i],tetra[(i+1)%4],tetra[(i+2)%4])));
      if(!inserted.second){
	bdryFaces.erase(inserted.first);
      }
    }
  }
  return bdryFaces;
}
