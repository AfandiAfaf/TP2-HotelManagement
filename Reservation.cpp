#include "Reservation.h"
#include <iostream>
#include <array>
using namespace std;

bool Reservation::valide_date(Date d_debut,Date d_fin){
	if (d_debut.getYear()<d_fin.getYear()){
	     return true;
	}
	else if (d_debut.getYear()==d_fin.getYear()){
		if(d_debut.getMonth()<d_fin.getMonth()){
			return true;
		}
		else if (d_debut.getMonth()==d_fin.getMonth()){
			if(d_debut.getDay()<d_fin.getDay()){
				return true;
			}
			else {
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool Reservation::chambre_disponible(Date d_debut , Date d_fin , int id_reservation , string id_hotel ,int id_chambre){
    for (int i=0 ; i<__table_id_reservation.size() ; i++ ) {
      	if ((_table_hotel[i]==id_hotel) && (_table_chambre[i]==id_chambre) && ( valide_date(d_debut,d_fin)) &&  (( valide_date(d_fin , _table_date_debut[i]) || (valide_date(_table_date_fin[i] , d_debut))) )){ 
      	   	    return false ;
      	} //on teste tous les parametres liés à la chambre si ils sont deja présents dans les tables créées cad que la chambre est NON DISPONIBLE
    }
    return true;
}

bool Reservation::id_reservation_unique(int id_reservation){
	for (auto it=_table_id_reservation.begin() ; it <_table_id_reservation.end(); ++it){
		if (*it== id_reservation){
			return false;
		} 
	}
	return true;
}

Reservation::Reservation(Date d_debut, Date d_fin, string id_hotel, int id_chambre, string id_client, int id_reservation){

    if(id_reservation_unique(id_reservation)){
        if (valide_date(d_debut,d_fin)==true) && (chambre_disponible( d_debut , d_fin, id_reservation,  id_hotel, id_chambre)){  
         	_d_fin=d_fin;
         	_d_debut=d_debut;
            _id_reservation=id_reservation;
            _id_hotel=id_hotel;
            _id_chambre=id_chambre;
            _id_client=id_client;

            // ajout des informations de la nouvlle réservation dans les tableaux qui ont la même taille 
            _table_hotel.push_back(_id_hotel);
            _table_chambre.push_back(_id_chambre);
            _table_date_debut.push_back(_d_debut);
            _table_date_fin.push_back(_d_fin);
            _table_id_reservation.push_back(id_reservation);

            cout<<"Réservation acceptée"<<endl;
        }
        else{
    	    cout<<"Opération échouée, la chambre est déjà occupée"<<endl;
        }
    }
    else{
    	cout<<"Un réservation est déjà faite pour ce même identifiant"<<endl;
    }
}

Date Reservation::get_date_debut(){
	return _d_debut;
}
Date Reservation::get_date_fin(){
	return _d_fin;
}
int Reservation::get_identifiant_reservation(){
	return _id_reservation;
}
string Reservation::get_identifiant_hotel(){
	return _id_hotel;
}
string Reservation::get_identifiant_client(){
	return _id_client;
}
int Reservation::get_identifiant_chambre(){
	return _id_chambre;
}

void Reservation::set_dates(Date d_debut,Date d_fin){
	    if ((valide_date(d_debut,d_fin)==true) && (chambre_disponible( _d_debut , _d_fin, _id_reservation, _id_hotel, id_chambre))){
         	_d_fin=d_fin;
         	_d_debut=d_debut;
        }
}

void Reservation::set_identifiant_chambre(int id_chambre ){
	if(chambre_disponible( _d_debut, _d_fin,_id_reservation,  _id_hotel, id_chambre)){
      	_id_chambre=id_chambre;
	}
}


int Reservation::nombre_jours_total(){
	int s=0;
	Date date=_d_debut;
	while(date != d_fin){
		date.next();
        s=s+1;
	}
	return s;
}

void Reservation::montont_total(float prix_nuit){
    int s=nombre_jours_total();
	float p=prix_nuit*s;
    _montant_total=p;	
}

float get_montant_total(){
	return _montant_total;
}

// Surcharge de l'operateur <<
ostream& Reservation::operator<<(ostream& os,const Reservation& r){
	string to_display;
    to_display=" votre réservation commence le : " + r.get_date_debut().toString() + " et finit le : " + r.get_date_fin().toString() + " dans l'hotel " + r.get_identifiant_hotel() +"dans la chambre : " + to_string(get_identifiant_chambre()) + " et l'dentifiant de votre réservation est :  " + to_string(get_identifiant_reservation()) ;
    os <<to_display<<endl;
    return os;
}

void Reservation::annuler_reservation(int id_reservation){
	for (int i=0; it<table_id_reservation.size();i++){
		if(_table_id_reservation[i]==id_reservation){  //j'enlève toute information relative a la reservation des tableaux ou on stocke ces infos
			 _table_hotel.erase(_table_hotel.begin()+i);
            _table_chambre.erase(_table_chambre.begin()+i);
            _table_date_debut.erase(_table_date_debu.begin()+i);
            _table_date_fin.erase(_table_date_fini.begin()+i);
            _table_id_reservation.erase(_table_id_reservation.begin()+i);
		}
	}
}