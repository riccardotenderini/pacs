#include <iostream>
#include "functions.cpp"
#include "mesh.hpp"

using namespace std;

int main(){

	vector<Tetra> v2;
	v2.push_back(Tetra(1,2,4,5));
	v2.push_back(Tetra(2,3,4,5));
	v2.push_back(Tetra(1,4,5,6));
	
	cout << "Tetraedri: " << endl;
	for (auto i : v2){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << " " << get<3>(i.pointId) << endl;
	}

	cout << endl;	
	set<Triangle,yesOrientTr> faces = findfaces(v2);
	set<Triangle,yesOrientTr> boundary = findboundaryTetra(v2);
	// set<Edge,yesOrient> alledges = findedges(v2);

	cout << "Facce dei tetraedri: " << endl;
	for (auto i : faces){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << endl;
	}
	
	cout << endl;

	cout << "Boundary faces: " << endl;
	for (auto i : boundary){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << endl;
	}
	cout << endl;
	/*
	cout << "Lati dei tetraedri: " << endl;
	for (auto i : alledges){
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	cout << endl;
	*/
	
	return 0;
}

	
