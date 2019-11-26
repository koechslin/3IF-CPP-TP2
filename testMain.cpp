#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;

int main()
{
	/*Catalogue catalogue;
	while(1)
	{
		cout<<"Choix disponibles : "<<endl;
		cout<<"\t(1) Afficher le catalogue"<<endl;
		cout<<"\t(2) Ajouter un trajet au catalogue"<<endl;
		cout<<"\t(3) Rechercher un parcours"<<endl;
		break;
	}*/
	TrajetSimple ts1("Ambert", "Lyon", "Train");
	TrajetSimple ts2("Lyon","Paris","Train");
	TrajetSimple ts3("Lyon","Toulouse","Train");
	TrajetSimple ts4("Ambert","Toulouse","Bus");
	TrajetSimple ts5("Paris","Lyon","Avion");
	TrajetSimple l1[2] = {ts1,ts2};
	TrajetSimple l2[2] = {ts5,ts3};
	TrajetCompose tc1("Ambert","Paris",l1,2);


	//TrajetCompose tc2 = TrajetCompose("Ambert","Toulouse",l2,2);


	Catalogue c;

	//c.Ajouter(ts1);
	/*c.Ajouter(ts2);
	c.Ajouter(ts3);
	c.Ajouter(ts4);
	c.Ajouter(tc1);
	c.Ajouter(tc2);*/

	char villeDepartRecherche[] = "Ambert";
	char villeArriveeRecherche[] = "Toulouse";

	//c.RechercheSimple(villeDepartRecherche,villeArriveeRecherche);

	//c.AfficherCatalogue();

	return 0;
}
