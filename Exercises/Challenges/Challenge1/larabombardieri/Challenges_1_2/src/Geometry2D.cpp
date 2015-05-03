//
//
// Geometry2D.cpp
//
//

#include "Geometry2D.hpp"

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

// Constructor for the Edge class
Edge::Edge(unsigned const &a, unsigned const &b){
  if(a==b)
    std::cerr<<"Error : collapsing edge"<<std::endl;
  else{
    Id_P1_=a;
    Id_P2_=b;
  }
}

// Definition of the comparison operator for the Edge class

bool Edge_comp::operator()(Edge const &e1, Edge const &e2)const{
  auto e1_ordered=std::minmax(e1.get_Id_P1(),e1.get_Id_P2());
  auto e2_ordered=std::minmax(e2.get_Id_P1(),e2.get_Id_P2());
  if(e1_ordered.second != e2_ordered.second)
    return e1_ordered.second<e2_ordered.second;
  else
    return e1_ordered.first<e2_ordered.first;
  }

//Constructor for the Triangle class
Triangle::Triangle(unsigned const &p1, unsigned const &p2, unsigned const &p3){
  if((p1==p2)||(p2==p3)||(p3==p1))
    std::cerr<<"Error : the Triangle has a collapsing edge"<<std::endl;
  else{
    Id_P1_=p1;
    Id_P2_=p2;
    Id_P3_=p3;
  }
}

// Overloading of the output operator "<<" for the Edge and Triangle classes
std::ostream& operator<<(std::ostream &os, Edge const &e){
  os<<"{"<<e.Id_P1_<<","<<e.Id_P2_<<"} ";
  return os;
}
std::ostream& operator<<(std::ostream &os, Triangle const &t){
  os<<"{"<<t.Id_P1_<<","<<t.Id_P2_<<","<<t.Id_P3_<<"} ";
  return os;
}

// Print functions
void print_Edges(type_Edges_set const &Edges_list){
  for(auto i:Edges_list)
    std::cout<<i;
  std::cout<<"\nNb of Edges = "<<Edges_list.size()<<std::endl;
}

void print_Mesh(std::vector<Triangle> const &Mesh){
  std::cout<<"\nThe Mesh contains the following triangles :"<<std::endl;
  for(auto i:Mesh)
    std::cout<<i;
  std::cout<<"\nNb of Triangle = "<<Mesh.size()<<std::endl;
}

// Other functions

type_Edges_set get_Mesh_Edges(std::vector<Triangle> const &Mesh){

  type_Edges_set Mesh_edges;
  for(auto i:Mesh){
    Mesh_edges.emplace(i.get_Id_P1(),i.get_Id_P2());
    Mesh_edges.emplace(i.get_Id_P2(),i.get_Id_P3());
    Mesh_edges.emplace(i.get_Id_P3(),i.get_Id_P1());
  }
  return Mesh_edges;
}

type_Edges_set get_Mesh_BoundaryEdges(std::vector<Triangle> const &Mesh){

  type_Edges_set Mesh_BoundaryEdges;

  // Remark : the boundary edges are those that occur only once
  // the variable result will be used to check if an element already exists
  std::pair<type_Edges_set::iterator,bool> result;

  for(auto i:Mesh){
    result=Mesh_BoundaryEdges.emplace(i.get_Id_P1(),i.get_Id_P2()); // Remark : I used emplace and not find in order to avoid building ad Edge object
    if(!result.second) // i.e if the element was not inserted because it already existed
      Mesh_BoundaryEdges.erase(result.first);

    // same thing for the other two edges of the Triangle :
    result=Mesh_BoundaryEdges.emplace(i.get_Id_P2(),i.get_Id_P3()); 
    if(!result.second) 
      Mesh_BoundaryEdges.erase(result.first);

    result=Mesh_BoundaryEdges.emplace(i.get_Id_P3(),i.get_Id_P1()); 
    if(!result.second) 
      Mesh_BoundaryEdges.erase(result.first);

  }
  return Mesh_BoundaryEdges;
}


