/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

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
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetCompose :: AfficherTrajet() const
// Algorithme :
// Aucun
{
  int i=0;
  for(i=0;i<this->nbTrajetSimple;i++)
  {
    this->listeTrajetSimple[i].AfficherTrajet();
    if(i!=(this->nbTrajetSimple-1))
      cout<<" - ";
  }
}


//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose ( const char* depart,const char* arrivee, const TrajetSimple* listeTrajet,int nbTrajets )
// Algorithme :
//    Aucun
  :Trajet(depart,arrivee),nbTrajetSimple(nbTrajets)
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetCompose>" << endl;
  #endif
  
  this->listeTrajetSimple = new TrajetSimple[nbTrajets];
  for(int i=0;i<nbTrajets;i++)
  {
    this->listeTrajetSimple[i]=(listeTrajet[i]);
  }

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//  Aucun
{
  #ifdef MAP
      cout << "Appel au destructeur de <TrajetCompose>" << endl;
  #endif
  delete[] this->listeTrajetSimple;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
