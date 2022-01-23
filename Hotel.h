#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include<cstring>
#include "Chambre.h"
#include <vector>
using namespace std;
class Hotel{

    public :

        Hotel(string id, string nom_hotel , string ville); 
        string getId();
        string getNom_hotel();
        string getVille();
        vector<Chambre> getTable(); //l'ensemble des chambres represente un tableau

        void remplir_table(vector<Chambre> table);
        void ajouterChambre(Chambre ch);
        
        friend ostream& operator<<(ostream& os,const Hotel& h);

    private :
        string _id;
        string _nom_hotel;
        string _ville;
        vector<Chambre> _table;
};
# endif