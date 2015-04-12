#ifndef EDGE_HPP
#define EDGE_HPP

#include<iostream>
#include<array>

#include "point.hpp"

//Class with an array of 2 unsigned int representing the identifiers of the points defining an edge. 
class Edge{
public:
  //Constructor
  Edge(const Point& first, const Point& second) : pointsId(std::array<Point,2>{{first,second}}){}
  //Overload of operators
  Point operator[](const std::size_t& i)const{
    return pointsId[i];
  }
  Point& operator[](const std::size_t& i){
    return pointsId[i];
  }
  //Other public method
  std::array<Point,2> getPoints() const{
    return pointsId;
  }
private:
  //Attribute
  std::array<Point,2> pointsId;
};


//Comparison between edges
struct compEdges{
  bool operator()(Edge const& a, Edge const& b) const;
};


#endif //EDGE_HPP
