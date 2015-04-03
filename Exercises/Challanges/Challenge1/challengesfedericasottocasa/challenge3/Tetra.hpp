#ifndef HH__Tetra_HPP
#define HH__Tetra_HPP
#include <array>
#include "Triangle.hpp"
#include <vector>

//!  Class storing the Ids of Points in an Tetrahedron
class Tetra
{
public:

  //constructor that takes four points Ids
  Tetra(const unsigned & a, const unsigned & b, const unsigned & c, const unsigned & d):T_pointId{{a,b,c,d}}{}

  //!Estracts the id of the Ith point
  unsigned int operator[](unsigned int i)const
  {
    return T_pointId[i];
  }

  //!Estracts the id of the Ith point, non const version
  unsigned int & operator[](unsigned int i)
  {
    return T_pointId[i];
  }

  //! Returns all points ID, only const version
  std::array<unsigned,4> getPointId() const
  { 
    return T_pointId;
  }

private:
  //! Arrray containing the points
  std::array<unsigned,4> T_pointId;
};

#endif
