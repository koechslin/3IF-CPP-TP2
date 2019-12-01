//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Catalogue::ComparerTrajet(Trajet & trajet1, Trajet & trajet2) const
{
	if(typeid(trajet1)==typeid(trajet2)) // vérifie que les trajets sont de même nature
	{
		if(typeid(trajet1)==typeid(TrajetSimple)) // ce sont des trajets simples
		{
			if(dynamic_cast<TrajetSimple&>(trajet1)==dynamic_cast<TrajetSimple&>(trajet2))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if(dynamic_cast<TrajetCompose&>(trajet1)==dynamic_cast<TrajetCompose&>(trajet2)) // ce sont des trajets composés
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else // ils ne sont pas de même nature
	{
		return false;
	}
}

int Catalogue::Ajouter(Trajet* unTrajet) {

	for (int i = 0;i < this->nbTrajetsAct;i++) {
		if (ComparerTrajet(*unTrajet,*(this->listeTrajets[i]))) // vérifie si le trajet est déjà présent
		{
			return 0;
		}
	}
	if(this->nbTrajetsAct==this->nbTrajetsMax) // vérifie si la liste a besoin d'être agrandie
	{
		this->nbTrajetsMax *= 2;
		Trajet** tableauTemp = new Trajet* [this->nbTrajetsMax];
		for(int i=0;i<this->nbTrajetsAct;i++)
		{
			tableauTemp[i] = this->listeTrajets[i];
		}
		delete[] listeTrajets;
		listeTrajets = tableauTemp;
	}
	// ajout du trajet (grâce à son pointeur)
	this->listeTrajets[this->nbTrajetsAct] = unTrajet;
	this->nbTrajetsAct++;

	return 1;
}

void Catalogue::RechercheSimple(char* depart,char* arrivee) const
{
	cout<<"Liste des trajets allant de "<<depart<<" à "<<arrivee<<" : "<<endl;
	for(int i=0;i<this->nbTrajetsAct;i++)
	{
		// on regarde pour chaque trajet si sa ville de départ et sa ville d'arrivée (directe) correspondent à la recherche
		if(strcmp(this->listeTrajets[i]->getVilleDepart(),depart)==0 &&strcmp(this->listeTrajets[i]->getVilleArrivee(),arrivee)==0)
		{
			this->listeTrajets[i]->AfficherTrajet();
			cout<<endl;
		}
	}
}

void Catalogue::RechercheAvancee(char* depart,char* arrivee) const
{
	// lance la recherche avancée en initialisant un tableau permettant de retenir les trajets déjà parcourus dans la recherche
	cout<<"Liste des trajets allant de "<<depart<<" à "<<arrivee<<" : "<<endl;
	int* tableTrajetDejaParcouru = new int [this->nbTrajetsAct];
	for (int a = 0;a < this->nbTrajetsAct;a++) {
		tableTrajetDejaParcouru[a] = 0;
	}
	RechercheRecursive(depart,depart, arrivee, tableTrajetDejaParcouru,1);
	delete[] tableTrajetDejaParcouru;

}

void Catalogue::RechercheRecursive(char* departInitial,char* departActuel,char* arriveeFinale, int* tableTrajetParcouru, int profondeur) const
{ // Algorithme : recherche en backtracking qui parcourt en profondeur tous les trajets possibles et retient ceux qui partent de "departInitial" et arrivent à "arriveeFinale"

	for (int i = 0;i < this->nbTrajetsAct;i++)
	{
		if(strcmp(this->listeTrajets[i]->getVilleArrivee(), departInitial) != 0) // permet de ne pas revenir au point de départ ce qui ne servirait à rien dans la recherche
		{
			if (tableTrajetParcouru[i] == 0 && strcmp(this->listeTrajets[i]->getVilleDepart(), departActuel) == 0) // vérifie que l'on n'a pas encore parcouru ce trajet et qu'il part de là où l'on se trouve ("depart")
			{
				if (strcmp(this->listeTrajets[i]->getVilleArrivee(), arriveeFinale) == 0) // ce trajet arrive à la destination recherchée ("arrivee")
				{
					tableTrajetParcouru[i] = profondeur; // permet l'affichage du trajet "dans l'ordre" grâce à la profondeur à laquelle il se trouve dans la recherche
					cout << "------ Nouveau Trajet ------" << endl;
					for (int p = 1;p <= profondeur;p++)
					{
						for (int j = 0;j < this->nbTrajetsAct;j++)
						{
							if (tableTrajetParcouru[j] == p) // affiche les trajets par ordre de profondeur (de 1 à "profondeur")
							{
								this->listeTrajets[j]->AfficherTrajet();
								cout << endl;
							}
						}
					}
					tableTrajetParcouru[i] = 0; // remet le trajet dans un état "non parcouru" pour la suite de la recherche
				}
				else
				{
					tableTrajetParcouru[i] = profondeur;
					RechercheRecursive(departInitial, this->listeTrajets[i]->getVilleArrivee(), arriveeFinale, tableTrajetParcouru,profondeur+1); // si on n'est pas encore arrivé à la destination finale, on relance la méthode à partir de l'arrivée du trajet actuellement considéré
					tableTrajetParcouru[i] = 0;
				}
			}
		}
	}
}

void Catalogue::AfficherCatalogue() const
{
	if(this->nbTrajetsAct==0)
	{
		cout<<"Le catalogue est vide"<<endl;
		return;
	}
	cout<<"Les trajets présents dans le catalogue sont les suivants : "<<endl;
	for(int i=0;i<this->nbTrajetsAct;i++)
	{
		this->listeTrajets[i]->AfficherTrajet();
		cout<<endl;
	}
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	this->listeTrajets = new Trajet* [1]; // par défaut initialise la taille maximale du catalogue à 1
	this->nbTrajetsMax = 1;
	this->nbTrajetsAct = 0;
} //----- Fin de Catalogue (constructeur par défaut)

Catalogue::Catalogue(int nbTrajetsMax)
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	this->listeTrajets = new Trajet * [nbTrajetsMax]; // initialise la taille maximale du catalogue à la taille indiquée en paramètre
	this->nbTrajetsMax = nbTrajetsMax;
	this->nbTrajetsAct = 0;
} //----- Fin de Catalogue

Catalogue::~Catalogue()
{
	#ifdef MAP
	    cout << "Appel au destructeur de <Catalogue>" << endl;
	#endif
	for(int i=0;i<this->nbTrajetsAct;i++)
	{
		delete this->listeTrajets[i]; // détruit chaque trajet présent dans le catalogue
	}
	delete[] this->listeTrajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
