/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AfficherTrajet() const = 0;
    // Mode d'emploi :
    // Permet d'afficher le trajet, qu'il soit simple ou composé
    //
    // Contrat :
    // La méthode doit être redéfinie dans les classes filles

//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( );
    // Mode d'emploi :
    //  Initialise la ville de départ et d'arrivée

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Libère la mémoire utilisée par villeDepart et villeArrivee

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* villeDepart;
    char* villeArrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
