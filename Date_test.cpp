#include <iostream>
#include "Date.h"

using namespace std;

int main(){

    int year, month, day;

	Date d(2022, 1, 1);

	cout << "Entrer une date de réservation (année puis mois puis jour): "<< endl;
	cin >> year;
	cin >> month;
	cin >> day;

	cout<<"La date de votre résérvation est: \n";
	cout<<"\t L'année est: " << d.getYear() << endl;
	cout<<"\t Le mois est: " << d.getMonth() << endl;
	cout<<"\t Le jour est: " << d.getDay() << endl;
}
