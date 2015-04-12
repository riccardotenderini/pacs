#ifndef TETRAHEDRON_HPP
#define TETRAHEDRON_HPP

#include<iostream>
#include<vector>
#include<array>
#include<set>

#include "triangle.hpp"


//Class with an array of 4 unsigned int representing the identifiers of the points defining a tetrahedron.
class Tetrahedron{
public:
  //Constructor
  Tetrahedron(const Point& one, const Point& two, const Point& three, const Point& four) : pointsId(std::array<Point,4>{{one,two,three,four}}){}
  //Overload of operators
  Point operator[](const std::size_t& i) const{
    return pointsId[i];
  }
  Point& operator[](const std::size_t& i){
    return pointsId[i];
  }
  //Other public method
  std::array<Point,4> getPoints() const{
    return pointsId;
  }
private:
  //Attribute
  std::array<Point,4> pointsId;
};


//Function returning the set of faces (triangles) in a mesh made by tetrahedrons, without repetition.
std::set<Triangle,compTriangles> findFaces(std::vector<Tetrahedron> const&);

//Function returning the set of boundary faces of a mesh made by tetrahedrons. 
std::set<Triangle,compTriangles> findBoundaryFaces(std::vector<Tetrahedron> const&);

#endif //TETRAHEDRON_HPP
