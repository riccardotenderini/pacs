#include "mesh.hpp"
#include <vector>
#include <set>


using namespace std;

// Funzione che trova tutti i lati con orientatamento
set<Edge,yesOrient> findedgeO(const vector<Triangle> & v){
	
	set<Edge,yesOrient> alledges;
	for (auto i : v){
		alledges.emplace(Edge(get<0>(i.pointId),get<1>(i.pointId)));
		alledges.emplace(Edge(get<2>(i.pointId),get<0>(i.pointId)));
		alledges.emplace(Edge(get<1>(i.pointId),get<2>(i.pointId)));
	}

	vector<unsigned> cont;
	for (auto i : alledges){
		if(i.pointId.first==i.pointId.second){
			cont.emplace_back(i.pointId.first);			
		}
	}
	for (unsigned i=0; i < cont.size(); i++){
				auto it = alledges.find(Edge(cont[i],cont[i]));
				alledges.erase(it);		
	}	
			
	return alledges;
}

// Funzione che trova tutti i lati senza orientamento
set<Edge,noOrient> findedgeNO(const vector<Triangle> & v){
	
	set<Edge,noOrient> alledges;
	for (auto i : v){
		alledges.emplace(Edge(get<0>(i.pointId),get<1>(i.pointId)));
		alledges.emplace(Edge(get<0>(i.pointId),get<2>(i.pointId)));
		alledges.emplace(Edge(get<1>(i.pointId),get<2>(i.pointId)));
	}

	/*
	bool flag = 0;
	vector<unsigned> cont;
	for (auto i : alledges){
		if(i.pointId.first==i.pointId.second){
			flag = 1;
			cont.emplace_back(i.pointId.first);			
		}
	} 
	if (flag == 1){
		cout << "Attenzione ci sono dei lati 'falsi' tipo [1,1], vuoi cancellarli? [N=no,any key for Yes]" << endl;
		char p;
		cin >> p;
		cout << endl;
		if(p!='N'){
			for (unsigned i=0; i < cont.size(); i++){
				auto it = alledges.find(Edge(cont[i],cont[i]));
				alledges.erase(it);
			}
		}
	}
	*/
	vector<unsigned> cont;
	for (auto i : alledges){
		if(i.pointId.first==i.pointId.second){
			cont.emplace_back(i.pointId.first);			
		}
	}
	for (unsigned i=0; i < cont.size(); i++){
				auto it = alledges.find(Edge(cont[i],cont[i]));
				alledges.erase(it);		
	}		
			
	return alledges;
}


// Trova i lati interni di una mesh
set<Edge,yesOrient> findinnerboundaries(const vector<Triangle> & v){
 	set<Edge,yesOrient> alledges = findedgeO(v);
	set<Edge,yesOrient> result;
	auto it = alledges.end();

	for (auto i : alledges){
		it = alledges.find(Edge(i.pointId.second,i.pointId.first));
		if(it != alledges.end()){
			result.emplace(Edge(i.pointId.first,i.pointId.second));
			it = alledges.end();
		}
	}
	return result;
}
		
// Trova bordi della mesh
set<Edge,yesOrient> findboundary(const vector<Triangle> & v){
 	set<Edge,yesOrient> alledges = findedgeO(v);
	set<Edge,yesOrient> result = alledges;
	auto it = result.end();
	for (auto i : alledges){
		it = result.find(Edge(i.pointId.second,i.pointId.first));
		if(it != result.end()){
			result.erase(it);
			it = result.end();
		}
	}
	return result;
}
		
	
// Funzioni tetraedri

// Trova facce
set<Triangle,yesOrientTr> findfaces(const vector<Tetra> & v){
	set<Triangle,yesOrientTr> result;
	
	for (auto i : v){
		result.emplace(Triangle(get<0>(i.pointId),get<1>(i.pointId),get<2>(i.pointId)));
		result.emplace(Triangle(get<0>(i.pointId),get<1>(i.pointId),get<3>(i.pointId)));
		result.emplace(Triangle(get<2>(i.pointId),get<0>(i.pointId),get<3>(i.pointId)));
		result.emplace(Triangle(get<1>(i.pointId),get<2>(i.pointId),get<3>(i.pointId)));
	}
	
	return result;
}

// Trova lati
set<Edge,yesOrient> findedges(const vector<Tetra> & v){
	set<Edge,yesOrient> result;
	set<Triangle,yesOrientTr> faces = findfaces(v);
	
	vector<Triangle> temp(faces.begin(),faces.end());
	faces.clear();
	
	result = findedgeO(temp);

	return result;
}	

set<Triangle,yesOrientTr> findboundaryTetra(const vector<Tetra> & v){	
	set<Triangle,yesOrientTr> allfaces = findfaces(v);
	set<Triangle,yesOrientTr> result = findfaces(v);
	auto it = result.end();
	for (auto i : allfaces){
		it = result.find(Triangle(get<2>(i.pointId),get<1>(i.pointId),get<0>(i.pointId)));
		if(it != result.end()){
			result.erase(it);
			it = result.end();
		}		
		it = result.find(Triangle(get<2>(i.pointId),get<1>(i.pointId),get<0>(i.pointId)));
		if(it != result.end()){
			result.erase(it);
			it = result.end();
		}
		it = result.find(Triangle(get<1>(i.pointId),get<0>(i.pointId),get<2>(i.pointId)));
		if(it != result.end()){
			result.erase(it);
			it = result.end();
		}
		it = result.find(Triangle(get<1>(i.pointId),get<2>(i.pointId),get<0>(i.pointId)));
		if(it != result.end()){
			result.erase(it);
			it = result.end();
		}
		it = result.find(Triangle(get<0>(i.pointId),get<2>(i.pointId),get<1>(i.pointId)));
		if(it != result.end()){
			result.erase(it);
			it = result.end();
		}
	}
	return result;
}
	





