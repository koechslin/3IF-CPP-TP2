/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool ComparerTrajet(Trajet & trajet1, Trajet & trajet2) const;

	void RechercheSimple(char* depart, char* arrivee) const;

	int Ajouter(Trajet  & monTrajet);

	void AfficherCatalogue() const;

	//int VerifieCoherenceTrajetCompose(char* depart, char* arrivee, TrajetSimple* listeTrajets, int nbTrajets);

//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
	Catalogue(int nbTrajetsMax);







    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

	//Trajet** getListeTrajets() { return listeTrajets; }
	//int GetNbTrajetsAct() { return nbTrajetsAct; }
	//int GetNbTrajetsMax() { return nbTrajetsMax; }



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Trajet** listeTrajets;
	int nbTrajetsMax;
	int nbTrajetsAct;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
