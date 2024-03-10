#pragma once
#include"personnage.h"

class Voleur : public Personnage
{
public:
    Voleur(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax) :
        Personnage(nom, niveau, HP, HPMax, ATK, INT, DEX, exp, expmax, mana, manamax)
    {

    }


    Voleur() :  Personnage("Voleur", 1, 100, 100, 10, 1, 15, 0, 100, 50, 50) {}

    void LameEmpoisonnée(Personnage& ennemi);
    void CoupVampirique(Personnage& ennemi);
    int getManaCost(std::string spellName);
    int getDamage(std::string spellName);

private:


};
