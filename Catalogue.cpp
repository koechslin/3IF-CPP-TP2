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

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode




int Catalogue::Ajouter(Trajet  & montrajet) {

	for (int i = 0;i <= nbTrajetsAct;i++) {
		if (montrajet == listeTrajets[i][1]) {
			return 0;
		}
	}

	return 0;
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

	this->listeTrajets = new Trajet * [1];
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
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

