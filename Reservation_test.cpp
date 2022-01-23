#include <iostream>
#include "Reservation.h"
#include "Date.h"
#include <string>
using namespace std;

int main(){
    Date d_debut(2021,2,5);
    Date d_fin(2021,5,23);
	Reservation R1(d_debut,d_fin,"OCEAN11",1108,"aafandi",2001);

	cout<<"l'identifiant de l'hotel est :"<<R1.get_identifiant_hotel()<<endl;
	cout<<"l'identifiant de la reservation est :"<<R1.get_identifiant_reservation()<<endl;
	cout<<"l'identifiant de la chambre est :"<<R1.get_identifiant_chambre()<<endl;
	R1.set_identifiant_chambre(1403);      //modification de l'identifiant de la chambre
	cout<<"l'identifiant de la chambre est :"<<R1.get_identifiant_chambre()<<endl; // affichage du nv identifiant de la chambre
	cout<<"la date de début de la reservation est :"<<R1.get_date_debut()<endl;
	cout<<"la date de fin de la reservation est :"<<R1.get_date_fin()<endl;
	Date date1_debut(2021,2,4);
	Date date1_fin(2021,9,1);
	R1.set_dates(date1_debut , date1_fin); //modification des jours de reservation
    //affichage des nv dates 
    cout<<"la nouvelle date de debut est :"<<R1.get_date_debut()<endl; 
	cout<<"la nouvelle date de fin est :"<<R1.get_date_fin()<endl;
	cout<<"le nombre total des jours de la reservation est :"<<R1.nombre_jours_total()<endl; // affichage du nombre des jours de séjour
	R1.montont_total(130); 
	cout<<"le prix total de la reservation est  :"<<R1.get_montant_total()<endl;//affichage du prix total de la reservation
    return 0;
}