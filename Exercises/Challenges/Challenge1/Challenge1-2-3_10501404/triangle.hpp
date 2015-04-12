#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include<iostream>
#include<vector>
#include<array>
#include<set>

#include "edge.hpp"


//Class with an array of 3 unsigned int representing the identifiers of the points defining a triangle.
class Triangle{
public:
  //Constructor
  Triangle(const Point& first, const Point& second, const Point& third) : pointsId(std::array<Point,3>{{first,second,third}}){}
  //Overload of operators
  Point operator[](const std::size_t& i) const{
    return pointsId[i];
  }
  Point& operator[](const std::size_t& i){
    return pointsId[i];
  }
  //Other public method
  std::array<Point,3> getPoints() const{
    return pointsId;
  }
private:
  //Attribute
  std::array<Point,3> pointsId;
};


//Comparison between triangles
struct compTriangles{
  bool operator()(Triangle const& a, Triangle const& b) const;
};


//Function returning the set of edges in a mesh made by triangles, without repetition.
std::set<Edge,compEdges> findEdges(std::vector<Triangle> const&);

//Function returning the set of boundary edges of a mesh made by triangles. 
std::set<Edge,compEdges> findBoundaryEdges(std::vector<Triangle> const&);

#endif //TRIANGLE_HPP
