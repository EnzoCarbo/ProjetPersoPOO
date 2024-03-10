#pragma once
#include"personnage.h"

class Magicien : public Personnage
{
public:
    Magicien(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax) :
        Personnage(nom, niveau, HP, HPMax, ATK, INT, DEX, exp, expmax, mana, manamax)
    {

    }


    Magicien() :
        Personnage("Magicien", 1, 100, 100, 10, 1, 15, 4, 100, 50, 50)
    {

    }

    void Siphon(Personnage& ennemi);
    void FireBolt(Personnage& ennemi);
    int getManaCost(std::string spellName);
    int getDamage(std::string spellName); // Fonction pour obtenir les dégâts d'un sort
private:

};
