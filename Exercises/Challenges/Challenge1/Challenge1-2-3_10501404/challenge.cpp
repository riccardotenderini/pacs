#include<iostream>
#include "tetrahedron.hpp"


int main() {

  //Create a 2D mesh "by hand" (not necessarily counter clockwise)
  std::vector<Triangle> my2DMesh({Triangle(0,10,7),Triangle(10,7,14),Triangle(10,14,23)});

  //Find the edges
  std::set<Edge,compEdges> myEdges(findEdges(my2DMesh));
  //Display the edges
  std::cout << std::endl << "    *** 2D CASE ***   " << std::endl;
  std::cout << "Edges of the given 2D mesh: " << std::endl;
  for(std::set<Edge,compEdges>::iterator p=myEdges.begin(); p!=myEdges.end(); ++p){
    std::cout << p->getPoints()[0] << " " << p->getPoints()[1] << std::endl;
  }
  std::cout << std::endl;

  //Find the boundary edges
  std::set<Edge,compEdges> myBdryEdges(findBoundaryEdges(my2DMesh));
  //Display the boundary edges
  std::cout << "Boundary edges of the given 2D mesh: " << std::endl;
  for(std::set<Edge,compEdges>::iterator p=myBdryEdges.begin(); p!=myBdryEdges.end(); ++p){
    std::cout << p->getPoints()[0] << " " << p->getPoints()[1] << std::endl;
  }
  std::cout << std::endl;



  //Creating a 3D mesh "by hand" (not necessarily counter clockwise)
  std::vector<Tetrahedron> my3DMesh({Tetrahedron(0,1,2,3),Tetrahedron(1,2,3,4),Tetrahedron(0,1,3,5)});

  //Find the faces
  std::set<Triangle,compTriangles> myFaces(findFaces(my3DMesh));
  //Display the faces
  std::cout << std::endl << "    *** 3D CASE ***   " << std::endl;
  std::cout << "Faces of the given 3D mesh: " << std::endl;
  for(std::set<Triangle,compTriangles>::iterator p=myFaces.begin(); p!=myFaces.end(); ++p){
    std::cout << p->getPoints()[0] << " " << p->getPoints()[1] << " " << p->getPoints()[2] << std::endl;
  }
  std::cout << std::endl;

  //Find the boundary faces
  std::set<Triangle,compTriangles> myBdryFaces(findBoundaryFaces(my3DMesh));
  //Display the boundary faces
  std::cout << "Boundary faces of the given 3D mesh: " << std::endl;
  for(std::set<Triangle,compTriangles>::iterator p=myBdryFaces.begin(); p!=myBdryFaces.end(); ++p){
    std::cout << p->getPoints()[0] << " " << p->getPoints()[1] << " " << p->getPoints()[2] << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
