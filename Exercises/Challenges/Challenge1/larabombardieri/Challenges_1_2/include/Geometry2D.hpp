//
//
// Geometry2D.hpp
//
// This file contains the definitions of the geometric elements (classes Edge and Triangle) and functions used 

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

// CLASS EDGE
class Edge{

private:
  unsigned Id_P1_, Id_P2_;

public:

  // Constructor
  Edge(unsigned const &a,unsigned const &b);

  // Get methods
  inline unsigned get_Id_P1()const{return Id_P1_;}
  inline unsigned get_Id_P2()const{return Id_P2_;}

  // Overload of the output operator
  friend std::ostream& operator<<(std::ostream &os, Edge const &e);
};

// Functor to define the order relation in the Edge class
struct Edge_comp{
  bool operator()(Edge const &e1, Edge const &e2)const;
};


// Class TRIANGLE
class Triangle{

private:
  unsigned Id_P1_, Id_P2_, Id_P3_; 

public:

  // Constructor
  Triangle(unsigned const &p1,unsigned const &p2, unsigned const &p3);

  // Get methods
  inline unsigned get_Id_P1()const{return Id_P1_;}
  inline unsigned get_Id_P2()const{return Id_P2_;}
  inline unsigned get_Id_P3()const{return Id_P3_;}
 
  // Overload of the output operator
  friend std::ostream& operator<<(std::ostream &os, Triangle const &t);
};

typedef std::set<Edge,Edge_comp> type_Edges_set;

// Print functions
void print_Edges(type_Edges_set const &Edges_list);
void print_Mesh(std::vector<Triangle> const &Mesh);

// Other funtions
type_Edges_set get_Mesh_Edges(std::vector<Triangle> const &Mesh);
type_Edges_set get_Mesh_BoundaryEdges(std::vector<Triangle> const &Mesh);



#endif
