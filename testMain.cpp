#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main()
{

	TrajetSimple tr1 = TrajetSimple("Ambert", "Lyon", "Train");
	tr1.AfficherTrajet();
	return 0;
}
