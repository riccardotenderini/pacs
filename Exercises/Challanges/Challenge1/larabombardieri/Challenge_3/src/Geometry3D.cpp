//
//
// Geometry3D.cpp
//
//

#include "Geometry3D.hpp"
#include<array>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<tuple>

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

// Definition of the comparison operator for the Triangle class

bool Triangle_comp::operator()(Triangle const &t1, Triangle const &t2)const{
 
  std::array<unsigned,3> t1_ordered{t1.get_Id_P1(),t1.get_Id_P2(), t1.get_Id_P3()};
  std::sort(t1_ordered.begin(),t1_ordered.end());
  std::array<unsigned,3> t2_ordered={t2.get_Id_P1(),t2.get_Id_P2(), t2.get_Id_P3()};
  std::sort(t2_ordered.begin(),t2_ordered.end());

  if(t1_ordered[2] != t2_ordered[2])
    return t1_ordered[2] < t2_ordered[2];
  else if(t1_ordered[1] < t2_ordered[1])
    return t1_ordered[1] < t2_ordered[1];
  else
    return t1_ordered[0] < t2_ordered[0];
  }

// Constructor for the Tetrahedron class
Tetrahedron::Tetrahedron(unsigned const &p1, unsigned const &p2, unsigned const &p3, unsigned const &p4){
  if((p1==p2)||(p1==p3)||(p1==p4)||(p2==p3)||(p2==p4)||(p3==p4))
    std::cerr<<"Error : the Tetrahedron has a collapsing edge"<<std::endl;
  else{
    Id_P1_=p1;
    Id_P2_=p2;
    Id_P3_=p3;
    Id_P4_=p4;
  }
}


// Overloading of the output operator "<<" for the Triangle and Tetrahedron classes
std::ostream& operator<<(std::ostream &os, Triangle const &t){
  os<<"{"<<t.Id_P1_<<","<<t.Id_P2_<<","<<t.Id_P3_<<"} ";
  return os;
}
std::ostream& operator<<(std::ostream &os, Tetrahedron const &t){
  os<<"{"<<t.Id_P1_<<","<<t.Id_P2_<<","<<t.Id_P3_<<","<<t.Id_P4_<<"} ";
  return os;
}

// Print functions
void print_Triangles(type_Triangles_set const &Triangles_list){
  for(auto i:Triangles_list)
    std::cout<<i;
  std::cout<<"\nNb of Triangles = "<<Triangles_list.size()<<std::endl;
  }

void print_Mesh(std::vector<Tetrahedron> const &Mesh){
  std::cout<<"\nThe Mesh contains the following Tetrahedra :"<<std::endl;
  for(auto i:Mesh)
    std::cout<<i;
  std::cout<<"\nNb of Tetrahedra = "<<Mesh.size()<<std::endl;
}

// Other functions

type_Triangles_set get_Mesh_Faces(std::vector<Tetrahedron> const &Mesh){

  type_Triangles_set Mesh_faces;
  for(auto i:Mesh){
    Mesh_faces.emplace(i.get_Id_P1(),i.get_Id_P2(),i.get_Id_P3());
    Mesh_faces.emplace(i.get_Id_P2(),i.get_Id_P3(),i.get_Id_P4());
    Mesh_faces.emplace(i.get_Id_P3(),i.get_Id_P4(),i.get_Id_P1());
    Mesh_faces.emplace(i.get_Id_P4(),i.get_Id_P1(),i.get_Id_P2());
  }
  return Mesh_faces;
}

type_Triangles_set get_Mesh_BoundaryFaces(std::vector<Tetrahedron> const &Mesh){

  type_Triangles_set Mesh_BoundaryFaces;

  // Remark : the boundary triangles are those that occur only once
  // the variable result will be used to check if an element already exists
  std::pair<type_Triangles_set::iterator,bool> result;

  for(auto i:Mesh){
    result=Mesh_BoundaryFaces.emplace(i.get_Id_P1(),i.get_Id_P2(),i.get_Id_P3()); // Remark : I used emplace and not find in order to avoid building ad Triangle object
    if(!result.second) // i.e if the element was not inserted because it already existed
      Mesh_BoundaryFaces.erase(result.first);

    // same thing for the other three faces of the Tetrahedron :
    result=Mesh_BoundaryFaces.emplace(i.get_Id_P2(),i.get_Id_P3(),i.get_Id_P4()); 
    if(!result.second)      
      Mesh_BoundaryFaces.erase(result.first);

    result=Mesh_BoundaryFaces.emplace(i.get_Id_P3(),i.get_Id_P4(),i.get_Id_P1()); 
    if(!result.second)      
      Mesh_BoundaryFaces.erase(result.first);

    result=Mesh_BoundaryFaces.emplace(i.get_Id_P4(),i.get_Id_P1(),i.get_Id_P2()); 
    if(!result.second)      
      Mesh_BoundaryFaces.erase(result.first);
  }
  return Mesh_BoundaryFaces;
}

