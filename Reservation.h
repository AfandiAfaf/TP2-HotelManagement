#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <cstring>
#include "Date.h"
#include<vector>
using namespace std;

class Reservation{

    public :
      	Reservation(Date d_debut, Date d_fin, string id_hotel, int id_chambre, string id_client, int id_reservation);//dans notre cas le client a un identifiant string
	    
	    Date get_date_debut();
	    Date get_date_fin();
	    string get_identifiant_hotel();
	    int get_identifiant_chambre();
	    string get_identifiant_client();
	    int get_identifiant_reservation();
        float get_montant_total();
	    
	    void set_identifiant_chambre(int id_chambre );
	    bool valide_date(Date d_debut,Date d_fin); //tester si la date est valide cad que d_debut < d_fin
	    bool chambre_disponible(Date d_debut , Date d_fin , int id_reservation, string id_hotel, int id_chambre); // tester si la chambre est disponibe pour un intervalle de temps precis
	    bool id_reservation_unique(int id_reservation);
	    int nombre_jours_total(); //calculer la periode de sejour 
	    void  montont_total(float prix_nuit);
	    void set_dates(Date date_debut,Date date_fin);

	    friend ostream& operator<<(ostream& os,const Reservation& r);
	    void annuler_reservation(int id_reservation);

	private :
	    int _id_reservation;
	    Date _d_debut;
	    Date _d_fin;
	    string _id_hotel;
	    int _id_chambre;
	    string _id_client;
	    float _montant_total;

	    vector<string> _table_hotel;   // les id_hotel des hôtels qui ont déjà des reservations
        vector<int> _table_chambre;        //  les id_chambre des chambres déjà réservées
        vector<Date> _table_date_debut;    //  les d_debut de toutes les reservations deja effectuées
        vector<Date> _table_date_fin;      //  les d_fin de toutes les reservations deja effectuées
        vector<int> _table_id_reservation; //  les id_reservation des reservations deja faites
        
};

#endif