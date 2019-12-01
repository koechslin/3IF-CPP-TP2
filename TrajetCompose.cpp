//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::AfficherTrajet() const
// Algorithme : affiche le trajet composé en appelant à tour de rôle les méthodes AfficherTrajet() de chaque trajet simple le composant
//
{
	for (int i = 0;i < this->nbTrajetSimple;i++)
	{
		this->listeTrajetSimple[i].AfficherTrajet();

		if (i != (this->nbTrajetSimple - 1)) // si ce n'est pas le dernier trajet simple, affiche un "-" pour séparer les affichages
		{
				cout << " -";
		}
	}
}
//------------------------------------------------- Surcharge d'opérateurs

bool TrajetCompose:: operator==(TrajetCompose & monTrajet) const
// Algorithme : compare 2 trajets composés en vérifier l'égalité entre chaque trajets simples les composant
//
{
	if (this->nbTrajetSimple == monTrajet.nbTrajetSimple)  // si ils n'ont pas la même "cardinalité" ils ne peuvent pas être égaux
	{
		for (int i = 0;i < this->nbTrajetSimple;i++)
		{
			if (this->listeTrajetSimple[i] != monTrajet.listeTrajetSimple[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose(const char* depart, const char* arrivee,const TrajetSimple* listeTrajet, int nbTrajets)
	:Trajet(depart, arrivee), nbTrajetSimple(nbTrajets)
{

	#ifdef MAP
		cout << "Appel au constructeur de <TrajetCompose>" << endl;
	#endif

	this->listeTrajetSimple = new TrajetSimple[nbTrajets];
	for(int i=0;i<nbTrajets;i++)
	{
		this->listeTrajetSimple[i] = listeTrajet[i];
	}

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose()
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

	delete[] this->listeTrajetSimple;

} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
