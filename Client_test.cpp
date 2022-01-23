#include <iostream>
#include "Client.h"
#include<cstring>
using namespace std;

int main (){

	Client C1("aafandi", "afandi", "afaf", 11);       
	
	cout<<"L'identifiant du client est: "<<C1.getIdentifiant()<<endl;   

	cout<<"Le com complet du client est: "<<C1.getPrenom()+ " " + C1.getNom()<<endl;

	cout<<"Le nombre de reservation est : "<< C1.getNumreservation()<<endl;
	
	//changement des infos du client
	C1.setClient("asabiri", "sabiri", "abderrahman", 8);                            
	
	cout<<"Le nouveau identifiant du client est: "<<C1.getIdentifiant()<<endl;  

	cout<<"Le nouveau nom complet est: "<<C1.getPrenom()+ " " + C1.getNom()<<endl;

	cout<<"Le nouveau nombre de reservation est : "<< C1.getNumreservation()<<endl;

    return 0;
};