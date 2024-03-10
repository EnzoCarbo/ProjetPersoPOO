#pragma once
#include"personnage.h"

class Cleric : public Personnage
{
public:
    Cleric(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax) :
        Personnage(nom, niveau, HP, HPMax, ATK, INT, DEX, exp, expmax, mana, manamax)
    {

    }


    Cleric() :
        Personnage("Cleric", 1, 100, 100, 10, 1, 15, 3, 100, 50, 50)
    {

    }

    void LumièreDivine(Personnage& ennemi);
    void Heal(Personnage& ennemi);
    int getManaCost(std::string spellName);
    int getDamage(std::string spellName);

private:

};
