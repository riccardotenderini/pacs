#include "mesh.hpp"

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

	/* Parte di gestione nel caso in cui l'utente inserisca dei dati sbagliati
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
	*/		
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
			break;
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
		
	
/////////////////// Funzioni tetraedri /////////////////////////77

// Trova facce
set<Triangle,yesOrientTriangle> findfaces(const vector<Tetra> & v){
	set<Triangle,yesOrientTriangle> result;
	
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
	set<Triangle,yesOrientTriangle> faces = findfaces(v);
	
	vector<Triangle> temp(faces.begin(),faces.end());
	faces.clear();
	
	result = findedgeO(temp);

	return result;
}	


set<Triangle,noOrientTriangle> findboundaryTetra(const vector<Tetra> & v){	
	set<Triangle,yesOrientTriangle> allfaces = findfaces(v);
	set<Triangle,noOrientTriangle> result;
	pair<set<Triangle,noOrientTriangle>::iterator,bool> flag = make_pair(result.end(),0);
	unsigned a,b,c;
	for (auto i : allfaces){
		a = get<0>(i.pointId);
		b = get<1>(i.pointId);
		c = get<2>(i.pointId);
		flag = result.insert(Triangle(a,b,c));
		if (flag.second == 0)
			result.erase(flag.first);
	}
	return result;
}
	





