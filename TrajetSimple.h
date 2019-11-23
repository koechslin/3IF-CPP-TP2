/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined (TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
#include "TrajetCompose.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <trajetSimple>
// Cette classe permet de modéliser un trajet Simple, c'est à dire un trajet élémentaire partant d'une ville A à une ville B avec 1 seul moyen de transport
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	virtual bool operator==(TrajetSimple & monTrajet) const;

	virtual bool operator==(TrajetCompose & monTrajet) const;

    TrajetSimple (){};
    // Mode d'emploi : Constructeur par défaut de TrajetSimple

    TrajetSimple (const char* depart,const char* arrive ,const char * moyenTransport);
    // Mode d'emploi : Construit un trajet simple qui contient une ville de départ, une ville d'arrivée et un moyen de transport
    //
    // Contrat :
    //

	virtual void AfficherTrajet() const;
	// Mode d'emploi : Affiche le trajet correspondant sur la sortie standard: ville de départ, ville d'arrivée, moyen de transport

    virtual ~TrajetSimple ( );
    // Mode d'emploi : détruit les différents tableaux de caractères dynamiques attributs de la classe
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char* moyenTransport;


};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
