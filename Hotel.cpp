#include "Hotel.h"
#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

Hotel::Hotel(string id, string nom_hotel, string ville){
	    _id=id;
    	_nom_hotel=nom_hotel;
    	_ville=ville;
}
string Hotel::getId(){
	return _id;
}

string Hotel::getNom_hotel(){
	return _nom_hotel;
}
string Hotel::getVille(){
	return _ville;
}
vector<Chambre> Hotel::getTable(){
	return _table;
}

void Hotel::remplir_table(std::vector<Chambre> table){
	for (auto it=table.begin();it<table.size();++it){

		_table.push_back(*it);
    }
}
void Hotel::ajouterChambre(Chambre ch){
       _table.push_back(ch);   
}

ostream& Hotel::operator<<(ostream& os,const Hotel& h){
	string to_display;
    to_display="l'identifiant de l'hotel"+ h.getNom_hotel() + " est : "+ h.getId() + "situé à" + h.getVille() + "dont les chambres sont: /n "  ;
    vector<Chambre> table=h.getTable();
    for(auto it=table.begin();it!=table.end();++it){
    	string a="Le numero de la chambre  est : "+ to_string(*it.getNumero()) + "de type : " + *it.getType() + "et de prix par nuit : " + to_string(*it.getPrix()) ;
    	to_display=to_display+ " /n " + a  ;
    }
    os <<to_display<<endl;
    return os;
}