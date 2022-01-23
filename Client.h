#include <iostream>
#include <cstring>
#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

   class Client {
   public:
      Client(string identifiant, string nom, string prenom, int num_reservation=1);// je vois qu'un nombre de reservation est aussi utile
      
      string getIdentifiant() const;//selon l'exemple que vous avez donné l'identifiant est une chaine de caracteres
      string getNom() const;
      string getPrenom() const;
      int getNumReservation() const;

      void setIdentifiant(string identifiant);
      void setNom(string nom);
      void setPrenom(string prenom);
      void setNumreservation(int num_reservation);

      void setClient(string identifiant, string nom, string prenom, int num_reservation);
      friend ostream& operator<<(std::ostream& os,const Client& c);

   private:
      string _identifiant;
      string _nom;
      string _prenom;
      int _num_reservation;

   };

 // client

#endif // CLIENT_H