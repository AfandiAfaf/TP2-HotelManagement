#include "Hotel.h"
#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

int main() {
    
    Hotel h("OCEAN11","Le bellagio","Las Vegas");  

	cout<<"L'identifiant de l'hotel est : "<<h.getId()<<endl;
	cout<<"Le nom de l'hotel est : "<<h.getNom_hotel()<<endl;
	cout<<"La ville où se trouve l'hotel est : "<<h.getVille()<<endl;

    //ajout d'une chambre 
    Chambre A11(14,"double",130);
    cout<<"le nouveau nombre des chambres est:"<<h.ajouterChambre(A11)<<endl;	
	
	return 0;
}