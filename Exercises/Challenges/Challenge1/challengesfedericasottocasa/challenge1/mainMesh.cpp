#include "Triangle.hpp"
#include "Edges.hpp"
#include <set>
#include <iostream>
#include <vector>

//function that returns the set of the edges

std::set<Edge,latimesh> myfun(std::vector<Triangle> mesh){

std::vector<Edge> meshEdges;

//I put ALL the mesh edges in a vector:

for( auto i=0;i<mesh.size();i++){

meshEdges.emplace_back(mesh[i][0],mesh[i][1]);
meshEdges.emplace_back(mesh[i][1],mesh[i][2]);
meshEdges.emplace_back(mesh[i][2],mesh[i][0]); }

//I fill the set of mesh edges without repetition:

std::set<Edge,latimesh> Edges (meshEdges.begin(),meshEdges.end());

return Edges;

}



int main()
{  
   //my mesh is a vector of triangles
   std::vector<Triangle> mesh;
   mesh.emplace_back(0,1,3);
   mesh.emplace_back(1,2,3);

   std::set<Edge,latimesh> Edges;
   Edges=myfun(mesh);

  std::cout<<"Mesh edges"<<std::endl;
  for (auto i : Edges)
    {
      std::cout<<i[0]<<" "<<i[1]<<std::endl;
    }
 
}







