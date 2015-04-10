#ifndef HH__Edges_HPP
#define HH__Edges_HPP
#include <array>

//! This class stores the Ids of Points in an Edge
class Edge
{
public:

  //! The constructor takes the points Ids
  Edge(const unsigned & a, const unsigned & b):M_pointId{{a,b}}{}

  //!Overloads of [] such that estracts the id of the Ith point
  unsigned int operator[](unsigned int i)const
  {
    return M_pointId[i];
  }

  //!Overloads of [] such that estracts the id of the Ith point, non const version
  unsigned int & operator[](unsigned int i)
  {
    return M_pointId[i];
  }

  //! Returns both points IDs, only const version
  std::array<unsigned,2> getPointId() const
  { 
    return M_pointId;
  }

private:
  //! Array storing the points
  std::array<unsigned,2> M_pointId;
};


//struct to define the set ordering relation
struct latimesh{
  bool operator()(Edge const& a, Edge const & b) const;
};

#endif
