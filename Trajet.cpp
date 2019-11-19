/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet ( const char* depart, const char* arrivee )
// Algorithme :
//  Aucun
{
  #ifdef MAP
      cout << "Appel au constructeur de <Trajet>" << endl;
  #endif
  this->villeDepart = new char[strlen(depart)+1];
  this->villeDepart = strcpy(this->villeDepart,depart);

  this->villeArrivee = new char[strlen(arrivee)+1];
  this->villeArrivee = strcpy(this->villeArrivee,arrivee);
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
// Aucun
{
  #ifdef MAP
      cout << "Appel au destructeur de <Trajet>" << endl;
  #endif
  delete[] this->villeDepart;
  delete[] this->villeArrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
