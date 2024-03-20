#include <iostream>
#include "RPG.h"

using namespace std;

/**
 * @brief Prints both player's name and their health.
 * @param player1
 * @param player2
*/
void displayStats(RPG player1, RPG player2){
    printf("%s Current Stats\n", player1.getName().c_str());
    printf("Health: %i\n", player1.getHealth());

    printf("%s Current Stats\n", player2.getName().c_str());
    printf("Health: %i\n", player2.getHealth());
}

/**
 * @brief Displays who wins based on who is alive. Use an if statement to check whether
 * player 1 is alive. If so, print that they won, else player 2 won.
 * 
 * @param player1
 * @param player2
*/
void displayEnd(RPG player1, RPG player2){
    if (player2.getHealth() <= 1){
        printf("Great game! %s has defeated %s!", player1.getName(), player2.getName());
    }else{
        printf("Great game! %s had defeated %s!", player2.getName(), player1.getName());
    }
}    

/**
 * @brief uses a while loop to check whether both players are alive.
 * @param player1
 * @param player2
*/
void gameLoop(RPG * player1, RPG * player2){
    while ((*player1).isAlive() && (*player2).isAlive()){

        displayStats((*player1), (*player2));
        printf("%s it's you turn!", (*player1).getName().c_str());
        (*player1).useSkill(player2);
        printf("--------------------------------------\n");

        displayStats((*player2), (*player1));
        printf("%s it's you turn!", (*player2).getName().c_str());
        (*player2).useSkill(player1);
        printf("--------------------------------------\n");
    }
}

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

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
}