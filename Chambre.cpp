#include "Chambre.h"
#include<cstring>
#include <iostream>
using namespace std;

Chambre::Chambre(int numero, string type , float prix): _numero(numero), _type(type), _prix(prix) {
}

int Chambre::getNumero(){
	return _numero;
}

string Chambre::getType(){
		return _type;
}

float Chambre::getPrix(){
	return _prix;
}

void Chambre::setChambre(int nv_numero, string nv_type , float nv_prix){
	_numero = nv_numero;
	_type = nv_type;
	_prix = nv_prix;
}

ostream& Chambre::operator<<(ostream& os,const Chambre& ch){
	string to_display;
    to_display="La chambre numero : "+ to_string(ch.getNumero()) + "est de type : " + ch.getType() + "et de prix par nuit : " + to_string(ch.getPrix()) ;
    os <<to_display<<endl;
    return os;
}