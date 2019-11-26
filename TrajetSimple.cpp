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

char* TrajetSimple::getTransport() const
{
	return this->moyenTransport;
}

//------------------------------------------------- Surcharge d'opérateurs
bool TrajetSimple:: operator==(TrajetSimple & monTrajet) const{
	if (strcmp(this->villeDepart, monTrajet.villeDepart) == 0 && strcmp(this->villeArrivee, monTrajet.villeArrivee) == 0 && strcmp(this->moyenTransport, monTrajet.moyenTransport) == 0)
	{
		return true;
	}
	return false;

}

void TrajetSimple::initTrajet(const char* depart,const char* arrive, const char* moyenTransport)
{
	this->villeDepart = new char [strlen(depart) + 1];
	strcpy(this->villeDepart, depart);

	this->villeArrivee = new char [strlen(arrive) + 1];
	strcpy(this->villeArrivee, arrive);

	this->moyenTransport = new char [strlen(moyenTransport) + 1];
	strcpy(this->moyenTransport, moyenTransport);
}


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
 :Trajet(unTrajetSimple.villeDepart,unTrajetSimple.villeArrivee)
{
	#ifdef MAP
	    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
	#endif

	 //strcpy(this->villeDepart,unTrajetSimple.villeDepart);
	 //strcpy(this->villeArrivee,unTrajetSimple.villeArrivee);
	 this->moyenTransport = new char [strlen(unTrajetSimple.moyenTransport) + 1];
	 strcpy(this->moyenTransport, unTrajetSimple.moyenTransport);

} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple()
{
	#ifdef MAP
			cout << "Appel au constructeur par défaut de <TrajetSimple>" << endl;
	#endif
}

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

	cout << " de " << this->villeDepart << " à " << this->villeArrivee << " en " << this->moyenTransport;

}

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au destructeur de <TrajetSimple>" << endl;
	#endif
	cout<<"avant destruction :"<<endl;
	cout<<"depart : "<<this->villeDepart<<"  arrivee : "<<this->villeArrivee<<endl;
	delete[] this->moyenTransport ;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
