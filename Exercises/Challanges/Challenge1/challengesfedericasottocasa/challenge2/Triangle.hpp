#ifndef HH__Triangle_HPP
#define HH__Triangle_HPP
#include <array>
#include "Edges.hpp"
#include <vector>

//! Class storing the Ids of Points in an Triangle

class Triangle
{
public:
  //constructor that takes the three points Ids
  Triangle(const unsigned & a, const unsigned & b, const unsigned & c):T_pointId{{a,b,c}}{}

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

  //! Returns all points IDs, only const version
  std::array<unsigned,3> getPointId() const
  { 
    return T_pointId;
  } 

private:
  //! Array containing the points of a Triangle
  std::array<unsigned,3> T_pointId;
};

#endif
