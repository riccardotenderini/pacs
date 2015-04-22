#include<iostream>
#include<vector>
#include<set>
#include<array>
using namespace std;

class Pt2d {
public:
  int id;
  double x;
  double y;
  double z;
  Pt2d(int _id = 0, double a = 0, double b = 0, double c = 0) {
    id = _id;
    x  = a;
    y  = b;
    z  = c;
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
  Triangle(Pt2d,Pt2d,Pt2d);
};

class Tetrahedron {
public:
  Pt2d* vertices;
  int id;
  Tetrahedron(int, Pt2d,Pt2d,Pt2d,Pt2d);
};

inline Edge::Edge(Pt2d p0, Pt2d p1) {
  vertices = new Pt2d [2];
  vertices[0] = p0;
  vertices[1] = p1;
};

inline Triangle::Triangle(Pt2d p0, Pt2d p1, Pt2d p2) {
  vertices = new Pt2d [3];
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
};

inline Tetrahedron::Tetrahedron(int _id, Pt2d p0, Pt2d p1, Pt2d p2, Pt2d p3) {
  id = _id;
  vertices = new Pt2d [4];
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
  vertices[3] = p3;
}

bool operator < (Triangle t1, Triangle t2) {
  auto t1id1 = min(min(t1.vertices[0].id, t1.vertices[1].id), t1.vertices[2].id);
  auto t1id2 = max(min(t1.vertices[0].id, t1.vertices[1].id), min(max(t1.vertices[0].id, t1.vertices[1].id), t1.vertices[2].id));
  auto t1id3 = max(max(t1.vertices[0].id, t1.vertices[1].id), t1.vertices[2].id);
  auto t2id1 = min(min(t2.vertices[0].id, t2.vertices[1].id), t2.vertices[2].id);
  auto t2id2 = max(min(t2.vertices[0].id, t2.vertices[1].id), min(max(t2.vertices[0].id, t2.vertices[1].id), t2.vertices[2].id));
  auto t2id3 = max(max(t2.vertices[0].id, t2.vertices[1].id), t2.vertices[2].id);
  if (t1id1 == t2id1){
    if (t1id2 == t2id2) return t1id3 < t2id3;
    return t1id2 < t2id2;
  };
  return t1id1 < t2id1;
};

bool find_equal(Triangle t1, Triangle t2) {
  auto t1_id1 = min(min(t1.vertices[0].id, t1.vertices[1].id), t1.vertices[2].id);
  auto t1_id2 = max(min(t1.vertices[0].id, t1.vertices[1].id), min(max(t1.vertices[0].id, t1.vertices[1].id), t1.vertices[2].id));
  auto t1_id3 = max(max(t1.vertices[0].id, t1.vertices[1].id), t1.vertices[2].id);
  auto t2_id1 = min(min(t2.vertices[0].id, t2.vertices[1].id), t2.vertices[2].id);
  auto t2_id2 = max(min(t2.vertices[0].id, t2.vertices[1].id), min(max(t2.vertices[0].id, t2.vertices[1].id), t2.vertices[2].id));
  auto t2_id3 = max(max(t2.vertices[0].id, t2.vertices[1].id), t2.vertices[2].id);
  return ((t1_id1 == t2_id1) && (t1_id2 == t2_id2) && (t1_id3 == t2_id3));
};

main() {

  Pt2d p0(0,0,0,0);
  Pt2d p1(1,1,0,0);
  Pt2d p2(2,1,1,0);
  Pt2d p3(3,0,1,0);
  Pt2d p4(4,0,0,1);

  vector<Tetrahedron> vttrhd;
  Tetrahedron ttrhd0(0,p0,p1,p2,p4);
  vttrhd.push_back(ttrhd0);
  Tetrahedron ttrhd1(1,p0,p2,p3,p4);
  vttrhd.push_back(ttrhd1);

  set<Triangle> str;
  multiset<Triangle> mstr;
  for (auto i=0; i<vttrhd.size(); ++i) {
    Triangle trg1(vttrhd[i].vertices[0], vttrhd[i].vertices[1], vttrhd[i].vertices[2]);
    str.insert(trg1);
    mstr.insert(trg1);
    Triangle trg2(vttrhd[i].vertices[0], vttrhd[i].vertices[1], vttrhd[i].vertices[3]);
    str.insert(trg2);
    mstr.insert(trg2);
    Triangle trg3(vttrhd[i].vertices[0], vttrhd[i].vertices[2], vttrhd[i].vertices[3]);
    str.insert(trg3);
    mstr.insert(trg3);
    Triangle trg4(vttrhd[i].vertices[1], vttrhd[i].vertices[2], vttrhd[i].vertices[3]);
    str.insert(trg4);
    mstr.insert(trg4);
  };

  cout<<"The number of faces of this mesh is: "<<str.size()<<endl;
  cout<<"The faces of this mesh are: "<<'\n';
  for (auto i:str) cout<<"("<<i.vertices[0].id<<", "<<i.vertices[0].x<<", "<<i.vertices[0].y<<", "<<i.vertices[0].z<<"), ("\
                       <<i.vertices[1].id<<", "<<i.vertices[1].x<<", "<<i.vertices[1].y<<", "<<i.vertices[1].z<<"), ("\
                       <<i.vertices[2].id<<", "<<i.vertices[2].x<<", "<<i.vertices[2].y<<", "<<i.vertices[2].z<<")"<<endl;

  vector<Triangle> myvec;
  myvec.reserve(mstr.size());
  for (auto i:mstr) myvec.push_back(i);
  set<Triangle> sbtr;
  
  int mvit = 0;
  while (mvit < (myvec.size()-1)) {
    if (find_equal(myvec[mvit],myvec[mvit+1])) {
      mvit = mvit + 2;
    } else {
      sbtr.insert(myvec[mvit]);
      mvit++;
    };
  };
  if (!(find_equal(myvec[myvec.size()-2],myvec[myvec.size()-1]))) {sbtr.insert(myvec[myvec.size()-1]);};
  cout<<"The number of boundary faces of this mesh is: "<<sbtr.size()<<endl;
  cout<<"The boundary faces of this mesh are: "<<'\n';
  for (auto i:sbtr) cout<<"("<<i.vertices[0].id<<", "<<i.vertices[0].x<<", "<<i.vertices[0].y<<", "<<i.vertices[0].z<<"), ("\
                       <<i.vertices[1].id<<", "<<i.vertices[1].x<<", "<<i.vertices[1].y<<", "<<i.vertices[1].z<<"), ("\
                       <<i.vertices[2].id<<", "<<i.vertices[2].x<<", "<<i.vertices[2].y<<", "<<i.vertices[2].z<<")"<<endl;

}


