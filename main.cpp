#include <iostream>
#include "RPG.h"

using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Health: %i\t Stength %i\n Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Health: %i\t Stength %i\n Defense: %i\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    //Call updateHealth(0) on either p1 or p2
    p1.updateHealth(0);

    //Print out the new health
    printf("Health: %i\t", p1.getHealth());

    //Call isAlive() on both p1 and p2
    printf("%d\n", p1.isAlive());
    printf("%d\n", p2.isAlive());

    return 0;
}