#include <iostream>
#include "mesh.hpp"
#include <vector>
#include <set>
#include "functions.cpp"

using namespace std;

int main(){
	char p;
	while(1){
		cout << "Si vuole vedere la parte 2D, 3D o entrambe? [0] per 2D, [1] per 3D, [2] per entrambe" << endl;
		cin >> p;
		if(p == '0' || p == '1' || p == '2')
			break;
	}
    if(p == '0' || p == '2'){
	// PARTE 2D
	vector<Triangle> v1;
	// Inizializzazione mesh triangoli	
	v1.push_back(Triangle(1,4,2));
	v1.push_back(Triangle(2,4,5));
	v1.push_back(Triangle(2,5,3));
	v1.push_back(Triangle(3,5,6));
	v1.push_back(Triangle(4,7,5));
	v1.push_back(Triangle(5,7,8));
		
	set<Edge,yesOrient> edges = findedgeO(v1);
	set<Edge,yesOrient> boundary = findboundary(v1);
	
	cout << "Triangoli: " << endl;
	for (auto i : v1){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << endl;
	}
	cout << endl;
	cout << "Boundaries: " << endl;		
	for (auto i : boundary){
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	cout << endl;
    } 
    if (p == '2')
	cout << endl << endl;
    if (p == '1' || p == '2'){
	// PARTE 3D
	vector<Tetra> v2;
	// Inizializzazione mesh tetraedri
	v2.push_back(Tetra(1,2,4,5));
	v2.push_back(Tetra(2,3,4,5));
	v2.push_back(Tetra(1,4,5,6));
	cout << "Tetraedri: " << endl;
	for (auto i : v2){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << " " << get<3>(i.pointId) << endl;
	}
	cout << endl;	
	
	set<Triangle,yesOrientTriangle> faces = findfaces(v2);
	set<Triangle,noOrientTriangle> boundary3D = findboundaryTetra(v2);
	
	cout << "Facce dei tetraedri: " << endl;
	for (auto i : faces){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << endl;
	}
	cout << endl;

	cout << "Boundary faces: " << endl;
	for (auto i : boundary3D){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << endl;
	}
	cout << endl;
     }

     return 0;
}

