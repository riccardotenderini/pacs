#include<algorithm>
#include<utility>

#include "triangle.hpp"


//Comparison between triangles
bool compTriangles::operator()(Triangle const& a, Triangle const& b) const{
  std::array<Point,3> sortedA(a.getPoints()), sortedB(b.getPoints());
  std::sort(sortedA.begin(),sortedA.end());
  std::sort(sortedB.begin(),sortedB.end());
  return sortedA<sortedB;
}

//Extract edges from a mesh made of triangles
std::set<Edge,compEdges> findEdges(std::vector<Triangle> const& mesh){
  std::set<Edge,compEdges> edges;
  for(std::vector<Triangle>::const_iterator t=mesh.begin(); t!=mesh.end(); t++){
    std::array<Point,3> triangle(t->getPoints());
    edges.insert(Edge(triangle[0],triangle[1]));
    edges.insert(Edge(triangle[1],triangle[2]));
    edges.insert(Edge(triangle[2],triangle[0]));
  }
  return edges;
}

//Extract boundary edges from a mesh made of triangles
std::set<Edge,compEdges> findBoundaryEdges(std::vector<Triangle> const& mesh){
  std::set<Edge,compEdges> bdryEdges;
  for(std::vector<Triangle>::const_iterator t=mesh.begin(); t!=mesh.end(); t++){
    std::array<Point,3> triangle(t->getPoints());
    for(std::size_t i(0); i<3; i++){
      std::pair<std::set<Edge,compEdges>::iterator,bool> inserted(bdryEdges.insert(Edge(triangle[i],triangle[(i+1)%3])));
      if(!inserted.second){
	bdryEdges.erase(inserted.first);
	//Fact: an edge is not on the boundary iff it is shared by exactly two triangles.
      }
    }
  }
  return bdryEdges;
}
