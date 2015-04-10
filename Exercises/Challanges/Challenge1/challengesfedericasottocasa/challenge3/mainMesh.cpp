#include "Triangle.hpp"
#include "Tetra.hpp"
#include <set>
#include <iostream>
#include <vector>


//function that returns mesh faces without repetition

std::set<Triangle,facemesh> faces(std::vector<Tetra> mesh){

std::vector<Triangle> meshFaces;

meshFaces=fromTetratoTriangle(mesh); //I create a vector containing ALL the 							faces starting from the mesh

std::set<Triangle,facemesh> Faces (meshFaces.begin(),meshFaces.end());
//Set of faces of the mesh without repetition of the same face

return Faces;

}



//function that returns boundary faces

std::set<Triangle,facemesh> boundaryfaces(std::vector<Tetra> mesh){

std::vector<Triangle> meshFaces;
meshFaces=fromTetratoTriangle(mesh); //I create a vector containing ALL the 							faces starting from the mesh

std::set<Triangle,facemesh> bFaces ;
std::pair<std::set<Triangle,facemesh>::iterator,bool> ret;

for(auto j=0;j<meshFaces.size();j++){

	ret=bFaces.insert(meshFaces[j]); //insert returns a pair

if(ret.second==false) 
		      //false means that the element is already in the set
		      //the iterator points to that element already in the set
	bFaces.erase(ret.first);
	            //I remove the element that I tried to insert twice			
}

return bFaces;

}





int main()
{  
   //my mesh is a vector of tetrahedron
   std::vector<Tetra> mesh;
   mesh.emplace_back(0,1,2,3);
   mesh.emplace_back(0,1,2,5);
   
   std::set<Triangle,facemesh> Faces;
   Faces=faces(mesh);

  std::cout<<"mesh faces"<<std::endl;
  for (auto i : Faces)
    {
      std::cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<std::endl;
    }

   std::set<Triangle,facemesh> bFaces;
   bFaces=boundaryfaces(mesh);

  std::cout<<"boundary mesh faces"<<std::endl;
  for (auto i : bFaces)
    {
      std::cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<std::endl;
    }
 
}







