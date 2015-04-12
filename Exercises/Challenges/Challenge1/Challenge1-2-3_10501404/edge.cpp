#include<algorithm>
#include "edge.hpp"


//Comparison between edges
bool compEdges::operator()(Edge const& a, Edge const& b) const{
  if(std::min(a[0],a[1])<std::min(b[0],b[1]))
    return true;
  else 
    return std::max(a[0],a[1])<std::max(b[0],b[1]);
}
