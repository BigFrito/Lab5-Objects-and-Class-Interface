#ifndef RPG_H
#define RGP_H
#include <string>

using namespace std;

const int SKILL_SIZE = 2;

class RPG{
    public:
        //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);
        void setSkills();
        void printAction(string type, RPG);
        void updateHealth(int);
        void attack(RPG *);
        void useSkill(RPG *);
        bool isAlive();
        string getName()const;
        int getHealth()const;
        int getStrength()const;
        int getDefense()const;

    private:
        string name;
        int health;
        int strength;
        int defense;
        string type; //warrior, mage, thief, archer
        string skills[SKILL_SIZE];
};
#endif