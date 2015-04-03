#include "Triangle.hpp"
#include <algorithm>
#include <array>
#include "Tetra.hpp"
#include <vector>

//function that returns a vector containing all mesh triangles
//In the 2d case I create this vector directly in the other functions(in mainMesh)
//Here with the 3d case I create a function to do this operation.

std::vector<Triangle> fromTetratoTriangle(std::vector<Tetra> mesh){

std::vector<Triangle> meshFaces;
 
for( auto i=0;i<mesh.size();i++){
	meshFaces.emplace_back(mesh[i][2],mesh[i][1],mesh[i][0]);
	meshFaces.emplace_back(mesh[i][3],mesh[i][1],mesh[i][2]);
	meshFaces.emplace_back(mesh[i][0],mesh[i][3],mesh[i][2]);
	meshFaces.emplace_back(mesh[i][0],mesh[i][1],mesh[i][3]);  }
return meshFaces;
}


//In the set I don't want repetion of the same face (identified with the same points)
bool facemesh::operator()(Triangle const& a, Triangle const & b) const
{
  auto amax= std::max(std::max(a[0],a[1]),a[2]);
  auto bmax= std::max(std::max(b[0],b[1]),b[2]);
  if (amax != bmax) 
    return amax>bmax;
  else{
  auto amin= std::min(std::min(a[0],a[1]),a[2]);
  auto bmin= std::min(std::min(b[0],b[1]),b[2]);
  auto amid=a[0]+a[1]+a[2]-amin-amax;
  auto bmid=b[0]+b[1]+b[2]-bmin-bmax;
  if(amid!=bmid)
	return amid>bmid;
  else
	return amin > bmin;
			}
      
  }
