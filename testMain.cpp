using namespace std;
#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main()
{
  TrajetSimple TS1("Ambert","Lyon","Pied");
  TrajetSimple TS2("Lyon","Ambert","Bus");
  TrajetSimple TS3("Ambert","Saint-Etienne","Train");
  TrajetSimple* L1 = new TrajetSimple[3];
  L1[0] = TS1;
  L1[1] = TS2;
  L1[2] = TS3;

  TrajetCompose TC1("Ambert","Saint-Etienne",L1,3);
  TC1.AfficherTrajet();
  cout<<endl;

  return 0;
}
