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
  int nbTrajets = sizeof(this->listeTrajetSimple)/sizeof(TrajetSimple);
  int i=0;
  for(i=0;i<nbTrajets;i++)
  {
    this->listeTrajetSimple[i].AfficherTrajet();
    if(i!=(nbTrajets-1))
      cout<<" - ";
  }
  cout<<endl;
}


//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose ( const char* depart,const char* arrivee, const TrajetSimple* listeTrajet )
// Algorithme :
//    Aucun
  :Trajet(depart,arrivee)
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetCompose>" << endl;
  #endif

  int nbTrajets = sizeof(listeTrajet)/sizeof(TrajetSimple);
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
