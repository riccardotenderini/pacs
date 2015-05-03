#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Pt2d {
public:
  double x;
  double y;
  int id;
  Pt2d(int _id=0, double a = 0, double b = 0) {
    id = _id;
    x  = a;
    y  = b;
  };
};

class Edge {
public:
  Pt2d* vertices;
  Edge(Pt2d,Pt2d); 
};

class Triangle {
public:
  Pt2d* vertices;
  int id;
  Triangle(int, Pt2d,Pt2d,Pt2d);
};

inline Edge::Edge(Pt2d p0, Pt2d p1) {
  vertices = new Pt2d [2];
  vertices[0] = p0;
  vertices[1] = p1;
};

inline Triangle::Triangle(int _id, Pt2d p0, Pt2d p1, Pt2d p2) {
  id = _id;
  vertices = new Pt2d [3];
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
};

bool operator < (Edge e1, Edge e2) {
  auto e1id1 = min(e1.vertices[0].id, e1.vertices[1].id);
  auto e1id2 = max(e1.vertices[0].id, e1.vertices[1].id);
  auto e2id1 = min(e2.vertices[0].id, e2.vertices[1].id);
  auto e2id2 = max(e2.vertices[0].id, e2.vertices[1].id);
  if (e1id1 == e2id1) return e1id2 < e2id2;
  return e1id1 < e2id1;
}

main() {
  int n = 4; // number of rows of nodes on y
  int m = 6; // number of columns of nodes on x
  vector<Pt2d> vpt;
  vpt.reserve(n*m);
  vector<Triangle> vtr;
  vtr.reserve(2*(n-1)*(m-1));
//  cout<<"the size of vtr = "<< vtr.size() <<endl;

  for (auto i=0; i<n; ++i) {
    for (auto j=0; j<m; ++j) {    
      Pt2d p0(0,0,0);
      p0.id = i*m+j+1;
      p0.x = j*(1./(m-1));
      p0.y = i*(1./(n-1));
      vpt.push_back(p0);
      cout<<"("<<p0.id<<", "<<p0.x<<", "<<p0.y<<") ";
    };
    cout<<endl;
  };

  cout<<"number of points = "<<vpt.size()<<endl;

  for (auto i=0; i<n-1; ++i) {
    for (auto j=0; j<2*(m-1); ++j) {
      Pt2d p1(0,0,0);
      Triangle tri(0,p1,p1,p1);
      tri.id = i*2*(m-1)+j+1;
      tri.vertices[0] = vpt[i*m+(j+1)/2]; 
      tri.vertices[1] = vpt[(i+j%2)*m+(j+2)/2];
      tri.vertices[2] = vpt[(i+1)*m+(j)/2];
      vtr.push_back(tri);
      cout<<"{"<<tri.id<<", ("<<tri.vertices[0].id<<", "<<tri.vertices[0].x<<", "<<tri.vertices[0].y<<") "\
          <<"("<<tri.vertices[1].id<<", "<<tri.vertices[1].x<<", "<<tri.vertices[1].y<<") "\
          <<"("<<tri.vertices[2].id<<", "<<tri.vertices[2].x<<", "<<tri.vertices[2].y<<")} ";
    };
    cout<<endl;
  };

  cout<<"number of triangles = "<<vtr.size()<<endl;

  set<Edge> sed; 
  for (auto i=0; i<vtr.size(); ++i){
     Edge edg1(vtr[i].vertices[0], vtr[i].vertices[1]); 
     sed.insert(edg1);
     Edge edg2(vtr[i].vertices[1], vtr[i].vertices[2]);
     sed.insert(edg2);
     Edge edg3(vtr[i].vertices[2], vtr[i].vertices[0]);
     sed.insert(edg3);
  };

  cout<<"number of edges = "<< sed.size() <<endl;
  for (auto i:sed) cout<<"("<<i.vertices[0].id<<", "<<i.vertices[0].x<<", "<<i.vertices[0].y<<"), ("<<i.vertices[1].id<<", "<<i.vertices[1].x<<", "<<i.vertices[1].y<<")"<<endl;

}



