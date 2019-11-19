/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined (TrajetSimple_H )
#define trajetSimple_H

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
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

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

