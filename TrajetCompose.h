//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Cette classe permet de modéliser un trajet composé, constitué de plusieurs trajets simples
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void AfficherTrajet() const;
    // Mode d'emploi : Affiche l'ensemble des trajets simples, et leur moyen de transport, constituant le trajet composé
    //

//------------------------------------------------- Surcharge d'opérateurs
    bool  operator ==(TrajetCompose & monTrajet) const ;

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose (const TrajetSimple* listeTrajet,int nbTrajets);
    // Mode d'emploi : construit un trajet composé à partir de la liste des trajets simples le constituant
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi : détruit le trajet composé en libérant de la mémoire le tableau de trajet simple
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TrajetSimple* listeTrajetSimple; // Tableau contenant les trajet simple composant le trajet composé
	   int nbTrajetSimple; // Entier indiquant le nombre de trajet simple au sein du trajet composé

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
