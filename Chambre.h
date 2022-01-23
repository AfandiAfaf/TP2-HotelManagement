#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <cstring>
#include <iostream>
using namespace std;

class Chambre{
    
    public:
	    Chambre(int numero, string type ,float prix);
	    int  getNumero();
	    string getType();
	    float  getPrix();

	    void setChambre(int nv_numero, string nv_type , float nv_prix);

	    // surchage de l'opérateur <<  
	    friend ostream& operator<<(ostream& os,const Chambre& ch);

	private:
        int _numero;
        string _type;
        float _prix;
   
};
#endif