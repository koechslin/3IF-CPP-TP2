/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

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
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

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

int Catalogue::Ajouter(Trajet  & unTrajet) {

	for (int i = 0;i < this->nbTrajetsAct;i++) {
		if (ComparerTrajet(unTrajet,*(this->listeTrajets[i]))) // vérifie si le trajet est déjà présent
		{
			return 0;
		}
	}
	// ajout du trajet
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
	this->listeTrajets[this->nbTrajetsAct] = &unTrajet;
	this->nbTrajetsAct++;

	return 1;
}

void Catalogue::RechercheSimple(char* depart, char* arrivee) const
{
	cout<<"Liste des trajets allant de "<<depart<<" à "<<arrivee<<" : "<<endl;
	for(int i=0;i<this->nbTrajetsAct;i++)
	{
		if(strcmp(this->listeTrajets[i]->getVilleDepart(),depart)==0 &&strcmp(this->listeTrajets[i]->getVilleArrivee(),arrivee)==0)
		{
			this->listeTrajets[i]->AfficherTrajet();
			cout<<endl;
		}
	}
}

void Catalogue::AfficherCatalogue() const
{
	cout<<"Les trajets présents dans le catalogue sont les suivants : "<<endl;
	for(int i=0;i<this->nbTrajetsAct;i++)
	{
		this->listeTrajets[i]->AfficherTrajet();
		cout<<endl;
	}
}

//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	this->listeTrajets = new Trajet* [1];
	this->nbTrajetsMax = 1;
	this->nbTrajetsAct = 0;


} //----- Fin de Catalogue

Catalogue::Catalogue(int nbTrajetsMax)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

	this->listeTrajets = new Trajet * [nbTrajetsMax];
	this->nbTrajetsMax = nbTrajetsMax;
	this->nbTrajetsAct = 0;


} //----- Fin de Catalogue




Catalogue::~Catalogue ( )
// Algorithme :
//
{
	delete[] this->listeTrajets;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
