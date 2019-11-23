/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
bool TrajetSimple:: operator==(TrajetSimple & monTrajet) const{
	if (strcmp(this->villeDepart, monTrajet.villeArrivee) == 0 && strcmp(this->villeArrivee, monTrajet.villeArrivee) == 0 && strcmp(this->moyenTransport, monTrajet.moyenTransport) == 0) 
	{
		return true;
	}
	return false;

}

bool TrajetSimple:: operator==(TrajetCompose & monTrajet) const {

	return false;

}


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
 :Trajet(unTrajetSimple.villeDepart,unTrajetSimple.villeArrivee)
{

	 //strcpy(this->villeDepart,unTrajetSimple.villeDepart);
	 //strcpy(this->villeArrivee,unTrajetSimple.villeArrivee);
	 strcpy(this->moyenTransport, unTrajetSimple.moyenTransport);


#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif

} //----- Fin de TrajetSimple (constructeur de copie)



TrajetSimple::TrajetSimple (const char* depart,const char* arrive,const char* moyenTransport)
// Algorithme :
//
 : Trajet(depart, arrive)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	this->moyenTransport = new char [strlen(moyenTransport) + 1];
	strcpy(this->moyenTransport, moyenTransport);

} //----- Fin de TrajetSimple

void TrajetSimple::AfficherTrajet ()const {

	cout << " de " << this->villeDepart << " à " << this->villeArrivee << " en " << this->moyenTransport<<endl;

}

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
	delete [] this->moyenTransport ;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
