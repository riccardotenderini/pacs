#include "Triangle.hpp"
#include "Edges.hpp"
#include <set>
#include <iostream>
#include <vector>
#include <utility>

//function that returns the boundary edges
std::set<Edge,latimesh> myfun(std::vector<Triangle> mesh){

std::vector<Edge> meshEdges;

//from my mesh I collect all the edges in a vector
for( auto i=0;i<mesh.size();i++){

meshEdges.emplace_back(mesh[i][0],mesh[i][1]);
meshEdges.emplace_back(mesh[i][1],mesh[i][2]);
meshEdges.emplace_back(mesh[i][2],mesh[i][0]); }


std::set<Edge,latimesh> Edges ;
std::pair<std::set<Edge,latimesh>::iterator,bool> ret;

for(auto j=0;j<meshEdges.size();j++){

	ret=Edges.insert(meshEdges[j]);
//insert returns a pair of the type described in the ret declaration 

if(ret.second==false)

//false means that the element is already in the set 
//so the iterator points to that element already in the set.

	Edges.erase(ret.first);

//In this way I remove from the set the element that I tried to insert twice

}

return Edges;

}




int main()
{
   
   //my mesh is a vector of Triangles
   std::vector<Triangle> mesh;
   mesh.emplace_back(0,1,3);
   mesh.emplace_back(1,2,3);
	
   //the set of boundary edges
   std::set<Edge,latimesh> Edges;
   Edges=myfun(mesh);

  std::cout<<"Boundary edges of my mesh"<<std::endl;
  for (auto i : Edges)
    {
      std::cout<<i[0]<<" "<<i[1]<<std::endl;
    }
 
}







