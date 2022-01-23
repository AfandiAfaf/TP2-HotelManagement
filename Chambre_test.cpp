#include <iostream>
#include "Chambre.h"
#include <cstring>
using namespace std;

int main() {
    
    Chambre A11(14,"double",130);  

	cout<<"Le numero de la chambre est : "<<A11.getNumero()<<endl;
	cout<<"Le type de la chambre est:"<<A11.getType()<<endl;
	cout<<"Le prixde la chambre par nuit est : "<<A11.getPrix()<<endl;

	//modification des infos de la chambre 

	A11.setChambre(03,"suite",260);   

	cout<<"Le numero de la chambre est : "<<A11.getNumero()<<endl;  
	cout<<"le type de la chambre est : "<<A11.getType()<<endl;
	cout<<"le prix de la chambre est : "<<A11.getPrix()<<endl;

	return 0;
}