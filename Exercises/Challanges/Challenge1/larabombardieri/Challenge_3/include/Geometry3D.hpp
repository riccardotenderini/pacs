//
//
// Geometry3D.hpp
//
// This file contains the definitions of the geometric elements (classes Triangl and Tetrahedron) and functions used 

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

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

// Functor to define the order relation in the Triangle class
struct Triangle_comp{
  bool operator()(Triangle const &t1, Triangle const &t2)const;
};

// Class TETRAHEDRON
class Tetrahedron{

private:
  unsigned Id_P1_, Id_P2_, Id_P3_, Id_P4_; 

public:

  // Constructor
  Tetrahedron(unsigned const &p1,unsigned const &p2, unsigned const &p3, unsigned const &p4);

  // Get methods
  inline unsigned get_Id_P1()const{return Id_P1_;}
  inline unsigned get_Id_P2()const{return Id_P2_;}
  inline unsigned get_Id_P3()const{return Id_P3_;}
  inline unsigned get_Id_P4()const{return Id_P4_;}
 
  // Overload of the output operator
  friend std::ostream& operator<<(std::ostream &os, Tetrahedron const &t);
};


typedef std::set<Triangle,Triangle_comp> type_Triangles_set;

// Print functions
void print_Triangles(type_Triangles_set const &Triangles_list);
void print_Mesh(std::vector<Tetrahedron> const &Mesh);

// Other funtions
type_Triangles_set get_Mesh_Faces(std::vector<Tetrahedron> const &Mesh);
type_Triangles_set get_Mesh_BoundaryFaces(std::vector<Tetrahedron> const &Mesh);



#endif
