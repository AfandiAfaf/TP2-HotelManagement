#include "Client.h"
#include<cstring>
#include <iostream>
using namespace std;

Client::Client(string identifiant, string nom, string prenom, int num_reservation): _identifiant(identifiant), _nom(nom), _prenom(prenom), _num_reservation(num_reservation){
}
string Client::getNom() const {
	return _nom;
}
string Client::getPrenom() const {
	return _prenom;
}
string Client::getIdentifiant() const {
	return _identifiant;
}
int Client::getNumreservation() const {
	return _num_reservation;
}
void Client::setClient( string identifiant, string nom, string prenom, int num_reservation){
	_nom=nom;
	_prenom=prenom;
	_identifiant=identifiant;
	_num_reservation=num_reservation;
}
// Surcharge de l'operateur <<
ostream& Client::operator<<(ostream& os,const Client& c){
	string to_display;
    to_display="l'identifiant du client "+ c.getPrenom()+ " " +c.getNom()+ " est : " +c.getIdentifiant() + " avec la réservation:  " + to_string(c.getNumreservation()) ;
    os <<to_display<<endl;
    return os;
}