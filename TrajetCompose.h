/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//    Cette classe permet de créer un trajet composé, constitué de plusieurs trajets simples,
//    et d'afficher les trajets simples successifs ainsi que leur moyen de transport associé
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual void AfficherTrajet() const;
    // Mode d'emploi :
    //    Affiche l'ensemble des trajets simples, et leur moyen de transport, constituant le trajet composé


//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose (const char* depart,const char* arrivee, const TrajetSimple* listeTrajet );
    // Mode d'emploi :
    //    Construit un trajet composé à partir du point de départ, d'arrivée, et de la liste des trajets simples le constituant

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //    Détruit le trajet composé en libérant de la mémoire le tableau de trajet simple

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TrajetSimple* listeTrajetSimple;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJETCOMPOSE_H
