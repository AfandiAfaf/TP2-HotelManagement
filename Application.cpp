#include "Hotel.h"
#include "Chambre.h"
#include "Client.h"
#include "Date.h"
#include "Resarvation.h"
#include<iostream>
#include<vector>
using namespace std;

// je vais utiliser ces deux fonctions à la question 7-a 
bool valide_date(Date date_debut,Date date_fin){
	if (date_debut.getYear()<date_fin.getYear()){
	     return true;
	}
	else if (date_debut.getYear()==date_fin.getYear()){
		if(date_debut.getMonth()<date_fin.getMonth()){
			return true;
		}
		else if (date_debut.getMonth()==date_fin.getMonth()){
			if(date_debut.getDay()<date_fin.getDay()){
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
bool checkDate(int year,int month, int day) const {
   bool status=true;
   if ((month == 1 || month == 3 || month == 5 || month == 7|| month == 8 || month == 10 || month == 12) && ( day>31 || day<1) ) {
   	     status = false;
   }
   else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day>30 || day<1) ) { 
   	     status = false;
   }
   else if ((year % 4)==0 && ((month == 2) && (day>29 || day<1)) || ((year % 4)!=0 && ((month == 2) && (day>28 || day<1)))) {
         status = false;
    }

    if ((month < 1) || (month > 12)) {
         status = false;
    }
    return status;
}


/* fonction utiliser à la question 7-a : si les dates placer dans les paramètres ne sont pas valides (càd date_debut ou date_fin n'existent pas ou date_debut>date_fin ) 
il permet de modifier ces parametres jusqu'à avoir des bonne dates c'est pour ça j'ai fait tous les pramètres de la fonction en type références  */
    
void introduit_dates_valides(int& day_debut , int& month_debut , int& year_debut , int& day_fin , int& month_fin , int& year_fin){   
    Date date_test(2020,1,1);   /*  on introduit une date valide telle que le jour  est inférieure ou égale à 28 
                                ( 28=nombre de jours dans le mois 2, le mois 2 est le mois qui contient le nombre des jours minimale ) 
                                ce choix est oblégatoire car dans la boucle while on va modifier le mois avant la modification du jour   
                                et la modication de mois  n'est possible que si la date contient un jour valable pour tous les mois.
                                (car on sait pas le nouveau mois introduit par l'utilisateur danc il faut choisir un jour valable poour tous les mois) */

    Date date_test1(2020,1,5);    // dexièmme date valide (elle verifér les mêmes condition de la première date) 

    while((checkDate(year_debut,month_debut,day_debut)==false)||(checkDate(year_fin,month_fin,day_fin)==false)||(valide_date(date_test, date_test1)==false)){
         date_debut.setDay(1); // à chaque fois on va modifier le jour par un jour valable pour tous les mois pour qu'on peut modifier le mois de date_test (par exemple si date_test=31/01/2021 et l'utilisateur va introduire 12/02/2021 donc on peut pas modifier le mois de  date_test car 31/02 n'existe pas )
         date_fin.setDay(1); // on peut prendre à la place de 1 un entiér  entre [1,28], le choix de nombre ne change rien
         cout<<"introduit une date valide de debut ( jour puis mois puis année) "<<endl;
         cin>>day_debut>>month_debut>>year_debut;
         date_test.setYear(year_debut);
         date_test.setMonth(month_debut);
         date_test.setDay(day_debut);
         cout<<"introduit une date valide de fin ( jour puis mois puis anée) "<<endl;
         cin>>day_fin>>month_fin>>year_fin; 
         date_test1.setYear(year_debut);
         date_test1.setMonth(month_debut);
         date_test1.setDay(day_debut);
    }  

}


/* deux fonctions utiliser à la question 7-b : 
    1ère fonction return nombre de jours ente deux date */
int nombre_jours(Date date_debut, Date date_fin){
	if (valide_date(Date date_debut,Date date_fin)){
	   int s=0;
	   Date d=date_debut;
	   while(d!=date_fin){
	      d.nextDay();
          s=s+1;
	   }
	   return s;
	}
	else{
		return 0;
	}
}
   //2ème fonction qui aficche le nombre de jours entre deux dates 
void affichage_nombre_jours(Date date_debut, Date date_fin){
     cout<<"le nombre de jours que vous voulez rèservé est :  "<< nombre_jours(date_debut, date_fin)<<endl;
}



/* fonction utilisée à la fonction suivante : return true si la chambre introduit en paramètre est disponible
 dans l'hotel entre les dates debut et fin et false sinon*/
bool disponible(Chambre c1 , Hotel h , Date date_debut , Date date_fin){
	Resarvation R1;
	return  R1.chambre_disponible( date_debut ,  date_fin , h.getIdentifiant() , c1.getIdentifiant());
}

/*fonction utilisée à la question 8-b return l'indice de la chambre souhaité par l'utilisateur ( càd type souhaité ) dans la table table_chambre 
et si l'utilisateur ne veut aucune chambre il renvoi l'indice du dernier élement + 1 dans la table */  
auto indice_chambre_dans_table( Hotel h ,vector<Chambre> table_chambre, Date date_debut , Date date_fin,std::string type){    
    
    for(auto it=table_chambre.begin();it!=table_chambre.end();++it){
    	if(disponible( *it , h , date_debut , date_fin) && *it==type ){
           return it;
    	}
    }

    cout<<"il ya pas des chambres disponible avec ce type chez nous "<<enl;
    cout<<" les types des chambres disponible dans ce hotel sont : "<<endl;
    for(auto it=table_chambre.begin();it!=table_chambre.end();++it){
    	    if(disponible( *it , H1 , date_debut , date_fin) ){
                cout<<*it.getType()<<endl; 
    	        bool a;
    	        cout<<"voulez vous ce type de chambre ?: introduit true ou false :"<<endl;
    	        cin>>a;
    	        if(a){
    	         	return it;
    	        }
    	    }
    }
    return  table_chambre.end();

}


/*fonction utilisée à la question 9-b return l'indice du bon du client choisit parmi l'utulisateur dans la table vect_client 
et si l'utilisateur n'a pas  trouvé son nom il renvoi l'indice du dernier élement +1 dans la table */ 
auto indice_client_dans_table( vector<Client> vect_client,std::string nom){
	for(auto it=vect_client.begin();it!=vect_client.end();++it){
       if( *it.getNom()== nom){
                cout<<*it<<endl; 
    	        bool a;
    	        cout<<"c'est toi ce client ?: introduit true ou false :"<<endl;
    	        cin>>a;
    	        if(a){
    	         	return it; 
       }
	}
	return vect_client.end();
}


// fonction utiliser à la question 11-a: affichage de tous les rèservation 
void affiche_reservation(vector<Reservation> table){
   for(auto it=table.begin(); it<table.end(); ++it){
   	  cout<< *it<<endl;
   }
}

//fonction utiliser à la question 11-b: affichage de la réservation à l'aide de l'dentifiant de la réservation
void affiche_reservation_par_ide_reservation(vector<Reservation> table, int identifiant_reservation){
	auto i;
	for(auto it=table.begin(); it<table.end(); ++it){
		if(*it.get_identifiant_reservation()==identifiant_reservation){
			i=it;
		}
	}
	cout<<*it<<endl;
}

//fonction utiliser à la question 11-c:affichage de tous  les réservations d'un client à l'aide de l'dentifiant de ce client
void affiche_reservation_par_ide_client(vector<Reservation> table, int identifiant_client){
	
	for(auto it=table.begin(); it<table.end(); ++it){
		if(*it.get_identifiant_client()==identifiant_client){
			cout<<*it<<endl;
		}
	}
	
}

//fonction utiliser à la question 11-d:permet de modifier la Reservation
void modifier_reservation(Reservation R, Chambre c1 , Hotel h , Date date_debut , Date date_fin){
	if (disponible(c1 , h , date_debut ,  date_fin)) {  
	   R.set_identifiant_chambre(identifiant_chambre );
	   R.set_dates(date_debut,date_fin);
    }
}

//fonction utiliser à la question 11-e:permet d'annuler une Rèservation
void annuler_reservation(vector<Reservation> table_reservation, Reservation R){
    R.annule_rese( R.get_identifiant_reservation());
	for (auto it=table_reservation.begin(); it<table_reservation.end();++it){
		if(*it.get_identifiant_reservation()==R.get_identifiant_reservation()){
			table_reservation.erase(it);
		}
	}
}





//main


int main(){
    
    // question 6-a: 
        // création des chambres de mon hotel

            // 3 Single
    Chambre Single_1(01,"Single",100);
    Chambre Single_2(02,"Single",100);
    Chambre Single_3(03,"Single",100);

           // 2 Suite
    Chambre Suite_1(04,"Suite",210);
    Chambre Suite_2(05,"Suite",210);

          // 5 Double
    Chambre Double_1(11,"Double",125);
    Chambre Double_2(12,"Double",125);
    Chambre Double_3(13,"Double",125);
    Chambre Double_4(14,"Double",125);
    Chambre Double_5(15,"Double",125);
    vector<Chambre> table_chambre={Single_1 , Single_2 , Single_3 , Suite_1 , Suite_2 , Double_1 , Double_2 , Double_3 , Double_4 , Double_5};
    Hotel H1("Ho1234","Hotel de Dijon","Dijon"); // création de mon hotel
    H1.remplir_table(table_chambre);       

    


    // question 6-b:

        //aprés le surcharge de l'opérateur << dans la classe Chambre et Hotel
    cout <<H1; // affichage de informations de l'hotele H1
    cout <<Single_3; // affichage d'informations de la chambre Single_3
    cout <<Suite_1;  // affichage d'informations de la chambre Suite_1
    


    //question 6-c:

        // la création des 7 clients
    Client C1("aafandi","afandi","prenom",11);
    Client C2("anafandi","afandi","anas",1);
    Client C3("dafandi","afandi","douaa",5);
    Client C3("ijilal","ait jilali","imane",17);
    Client C4("nbenradi","benradi","nora",23);
    Client C5("rafandi","afandi","rachid",4);
    Client C6("imouhtaram","el mouhtaram","ibtissam",3);
    Client C7("asabiri","sabiri","abderrahman",31);


        // la créationt du tableau des clients
    vector<Client> vect_client;
    vect_client={C1,C2,C3,C4,C5,C6,C7};


    
    //question 6-d:

        //aprés le surcharge de l'opérateur << dans la classe Client
    cout <<C1; // affichage de informations  du client C1
    cout <<C5; // affichage de informations du client C5


    

   
    // question 7-a:
    
    cout<<"introduit une date valide de debut ( jour puis mois puis année) "<<endl;
    cin>>day_debut>>month_debut>>year_debut;
    cout<<"introduit une date valide de fin ( jour puis mois puis anée) "<<endl;
    cin>>day_fin>>month_fin>>year_fin;

    int& ref_day_debut=day_debut; 
    int& ref_month_debut=month_debut;
    int& ref_year_debut=year_debut;
    int& ref_day_fin=day_fin;
    int& ref_month_fin=month_fin;
    int& ref_year_fin=year_fin;

    introduit_dates_valides( ref_day_debut , ref_month_debut , ref_year_debut , ref_day_fin , ref_month_fin , ref_year_fin); //fonction définie avant le main
    
    Date date_debut(year_debut,month_debut,day_debut); //la date debut valide 
    Date date_fin(year_fin,month_fin,day_fin);        //la date fin valide 

    
    

    // question 7-b:

    
    
    affichage_nombre_jours( date_debut,  date_fin);
    

    

    // question 8-a:

    std::strint type;
    cout<<"introduit le type de la chambre souhaitée : "<<endl;
    cin>>type;
    
   

    // question 8-b et question 8-c :
    
    auto it=indice_chambre_dans_table( H1 , table_chambre,  date_debut , date_fin , type); //fonction définie avant le main
    if(it != table_chambre.end()){
       cout<< *it<<endl; // car on a déjà fait le surcharge de l'opèrateur << dans la classe Chambre
    }
    else{
    	cout<<"nous sommes désolés, votre type n'existe pas dans notre hotel : "<<endl;
    }
    
    
    
    
    // question 9-a:

    cout<<"introduit votre nom : "<<endl;
    cin>>nom_client;



    // question 9-b et 9-c :

    auto it1=indice_client_dans_table( vect_client, nom);//fonction définie avant le main
    if(it1!=vect_client.end()){
    	cout<< *it1<<endl; // car on a déjà fait le surcharge de l'opèrateur << dans la classe Client
    }
    else{
    	cout<<"nous sommes désolés, Votre nom n'existe pas"<<endl;
    }
    

    // question 10-a et question 10-b:

    vector<Resarvation> table_reservation={}; // table des rèservations vide au dèbut
    if((it1 != vect_client.end()) && (it != table_chambre.end())){
        Resarvation resarvation_1(date_debut,date_fin , 1 , H1.getIdentifiant() , *it.getIdentifiant() , *it1.getIdentifiant()); // création de la première rèservation saisaie par l'utilisateur dans l'hotel H1
        float montant_total;
        bool x;
        if(*it1.getNm_reservations()==0){
        	x=false;
        }
        else{
        	x=true;
        }
        montant_total=reservation_1.montont_total( *it.getPrix(),x);
        cout<<"montant totale de la rèservation égale à : "<<montant_total<<endl;
        table_reservation.push_back(reservation_1);
        cout<<reservation_1<<endl;   //car on a déjà fait le surcharge de l'opèrateur << dans la classe Reservation

    }


    // question 10-c :
       // 1ére cas : bonne rèservation (car les dates sont valide et la chambre disponible puisque c'est la premiére rèservation dans mon hotel)
    Date date_debut1(2021,1,3);  
    Date date_fin1(2021,1,15);
    Reservation re1( date_debut1 ,  date_fin1 ,"Ho1234", 1000 );
    table_reservation.push_back(re1);

      //2ème cas : bonne rèservation (car les dates sont valide et la chambre disponible puisque cette chambre n'est jamais réserver )
    Date date_debut2(2021,1,23);  
    Date date_fin2(2021,1,28);
    Reservation re2( date_debut2 , date_fin2 ,"Ho1234", 1001 );
    table_reservation.push_back(re2);

      //3ème cas : rèservation non valide (car la chambre n'est pas dans cette date disponible puisque il est réservé par re1 )
    Date date_debut3(2021,1,4);  
    Date date_fin3(2021,1,13);
    Reservation re3( date_debut3 , date_fin3 ,"Ho1234", 1000 );
    

      //4ème cas : rèservation non valide ( car les dates ne sont pas valides date_debut >date_fin )
    Date date_debut4(2021,2,4);  
    Date date_fin4(2021,1,13);
    Reservation re4( date_debut4 , date_fin4 ,"Ho1234", 1000 );
    
      // 5ére cas : bonne rèservation (car les dates sont valide et la chambre disponible puisque c'est la premiére rèservation de cette chambre)
    Date date_debut1(2021,1,3);  
    Date date_fin1(2021,1,15);
    Reservation re5( date_debut5 ,  date_fin5 ,"Ho1234", 1002 );
    table_reservation.push_back(re5);


    // question 11-a:

    affiche_reservation(table_reservation);

    // question 11-b ----> 11-e : j'ai créer tous ces fonctions avant le main 


    // question 12: j'ai ajouté des méthodes qui gèrent mieux les Rèservation :
    

	return 0;
}