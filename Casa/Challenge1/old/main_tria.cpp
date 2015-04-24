#include <iostream>
#include "functions.cpp"
#include "mesh.hpp"


using namespace std;

int main(){

	vector<Triangle> v1;
	/* Codice per gestire un utente con la possibilità di scegliere

	bool flag = 1, def = 1;
	unsigned a,b,c;
	char p = 'A';
	while (p != 'Y' && p != 'N'){	
		cout << "Vuoi inserire tu i dati? Altrimenti saranno inizializzati di default [Y/N]" << endl;
		cin >> p; 
		cout << endl;
		if (p == 'Y')
			def = 0;
		else if (p == 'N')
			def = 1;
	}
	// Caso inserimento da utente
	if (def == 0){	
		while(flag == 1){
			cout << "Inserire nuove coordinate per triangolo: " << endl;
			cout << "Prima coordinata: ";		
			cin >> a;
			cout << endl;
			cout << "Seconda coordinata: ";
			cin >> b;
			cout << endl;
			cout << "Terza coordinata: ";
			cin >> c;
			cout << endl;
			v1.push_back(Triangle(a,b,c));	
			if (a==b || a==c || b == c)
				cerr << "Attenzione che il triangolo appena definito è degenere!" << endl;
			cout << endl;
			while (p != 'Y' && p != 'N'){
				cout << "Vuoi inserire un altro triangolo? [Y/N]" << endl;
				cin >> p;
				cout << endl;
				if (p=='N')
					flag = 0;
				else if (p == 'Y')
					flag = 1;
			}
			p = 'A';
		} 
	}

	// Caso di default
	if (def == 1){	
		v1.push_back(Triangle(1,4,2));
		v1.push_back(Triangle(2,4,5));
		v1.push_back(Triangle(2,5,3));
		v1.push_back(Triangle(3,5,6));
		v1.push_back(Triangle(4,7,5));
		v1.push_back(Triangle(5,7,8));
	}
	*/ 

	v1.push_back(Triangle(1,4,2));
	v1.push_back(Triangle(2,4,5));
	v1.push_back(Triangle(2,5,3));
	v1.push_back(Triangle(3,5,6));
	v1.push_back(Triangle(4,7,5));
	v1.push_back(Triangle(5,7,8));
	
	
	
	set<Edge,yesOrient> edges = findedgeO(v1);
	set<Edge,noOrient> edgesNO = findedgeNO(v1);
	// set<Edge,noOrient> edges = findedgeNO(v1); // ho immaginato che i lati non fossero orientati
	set<Edge,yesOrient> boundary = findboundary(v1);
	set<Edge,yesOrient> innerboundary = findinnerboundaries(v1);

	cout << "Triangoli: " << endl;
	for (auto i : v1){
		cout << get<0>(i.pointId) << " " << get<1>(i.pointId) << " " << get<2>(i.pointId) << endl;
	}
	/*
	cout << endl;
	cout << "Edges with orientation: " << endl;	
	
	for (auto i : edges){
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	
	cout << endl;
	cout << "Edges without orientation: " << endl;	
	
	for (auto i : edgesNO){
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	
	cout << endl;
	*/	

	cout << "Boundaries: " << endl;	
	
	for (auto i : boundary){
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	
	cout << endl;
	/*	
	cout << "Inner boundaries: " << endl;	
	
	for (auto i : innerboundary){
		cout << i.pointId.first << " " << i.pointId.second << endl;
	}
	*/
	
	return 0;
}

