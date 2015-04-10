#include "Edges.hpp"
#include <algorithm>
#include <array>

//According to this relation the edge 31 is the same as the edge 13
bool latimesh::operator()(Edge const& a, Edge const & b) const
{
  auto amax= std::max(a[0],a[1]);
  auto bmax= std::max(b[0],b[1]);
  if (amax != bmax) 
    return amax>bmax;
    else
      {
	auto amin= std::min(a[0],a[1]);
	auto bmin= std::min(b[0],b[1]);
	return amin > bmin;
      }
  }
