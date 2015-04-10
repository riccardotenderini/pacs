#ifndef HH__Triangle_HPP
#define HH__Triangle_HPP
#include <array>
#include <vector>
#include "Tetra.hpp"

//! Class storing the Ids of Points in an Triangle
class Triangle
{
public:
  //! Constructor that takes the points Ids
 Triangle(const unsigned & a, const unsigned & b,const unsigned & c):M_pointId{{a,b,c}}{}
  
  //!Estracts the id of the Ith point
  unsigned int operator[](unsigned int i)const
  {
    return M_pointId[i];
  }

  //!Estracts the id of the Ith point, non const version
  unsigned int & operator[](unsigned int i)
  {
    return M_pointId[i];
  }

  //! Returns all points ID, only const version
  std::array<unsigned,3> getPointId() const
  { 
    return M_pointId;
  }


private:
  //! Arrray storing the points
  std::array<unsigned,3> M_pointId;
};

//declaration of a function that returns a vector containing all mesh triangles  
std::vector<Triangle> fromTetratoTriangle(std::vector<Tetra> mesh);

//struct to define the set ordering relation
struct facemesh{
  bool operator()(Triangle const& a, Triangle const & b) const;
};

#endif
