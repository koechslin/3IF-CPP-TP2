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

char* TrajetSimple::getTransport() const
{
	return this->moyenTransport;
}

void TrajetSimple::AfficherTrajet () const
{
	cout << " de " << this->villeDepart << " à " << this->villeArrivee << " en " << this->moyenTransport;
}

//------------------------------------------------- Surcharge d'opérateurs

bool TrajetSimple:: operator ==(TrajetSimple & monTrajet) const
// Algorithme : compare la ville de départ, la ville d'arrivée et le moyen de transport des trajets considérés
//
{
	if (strcmp(this->villeDepart, monTrajet.villeDepart) == 0 && strcmp(this->villeArrivee, monTrajet.villeArrivee) == 0 && strcmp(this->moyenTransport, monTrajet.moyenTransport) == 0)
	{
		return true;
	}
	return false;
}

bool TrajetSimple:: operator !=(TrajetSimple & monTrajet) const
// Algorithme : utilise l'opérateur == redéfini juste avant afin de tester la différence
{
	return !(*this==monTrajet);
}

TrajetSimple & TrajetSimple::operator =(const TrajetSimple & trajet)
// Algorithme : copie en profondeur des attributs du paramètre "trajet" dans l'objet TrajetSimple qui appelle la méthode
//
{
	if(this != &trajet) // on vérifie que l'on n'a pas passé en paramètre le même trajet sans quoi les caractéristiques seraient détruites
	{
		if(this->villeDepart!=nullptr && this->villeArrivee!=nullptr && this->moyenTransport!=nullptr) // on vérifie que les pointeurs ne sont pas des "nullptr" afin de libérer leur zone mémoire
		{
			delete[] this->villeDepart;
			delete[] this->villeArrivee;
			delete[] this->moyenTransport;
		}

		// copie en profondeur des attributs
		this->villeDepart = new char [strlen(trajet.villeDepart) + 1];
		strcpy(this->villeDepart, trajet.villeDepart);

		this->villeArrivee = new char [strlen(trajet.villeArrivee) + 1];
		strcpy(this->villeArrivee, trajet.villeArrivee);

		this->moyenTransport = new char [strlen(trajet.moyenTransport) + 1];
		strcpy(this->moyenTransport, trajet.moyenTransport);

	}

	return *this;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
 :Trajet(unTrajetSimple.villeDepart,unTrajetSimple.villeArrivee)
{
	#ifdef MAP
	    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
	#endif

	 this->moyenTransport = new char [strlen(unTrajetSimple.moyenTransport) + 1];
	 strcpy(this->moyenTransport, unTrajetSimple.moyenTransport);

} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple()
// Algorithme : initialise les attributs comme étant des pointeurs nuls
: Trajet()
{
	#ifdef MAP
			cout << "Appel au constructeur par défaut de <TrajetSimple>" << endl;
	#endif
	this->moyenTransport=nullptr;
} //----- Fin de TrajetSimple (constructeur par défaut)

TrajetSimple::TrajetSimple (const char* depart,const char* arrive,const char* moyenTransport)
 : Trajet(depart, arrive)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	this->moyenTransport = new char [strlen(moyenTransport) + 1];
	strcpy(this->moyenTransport, moyenTransport);

} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple ( )
{
	#ifdef MAP
	    cout << "Appel au destructeur de <TrajetSimple>" << endl;
	#endif
	delete[] this->moyenTransport ;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
