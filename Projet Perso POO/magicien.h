#pragma once
#include"personnage.h"
#include<iostream>

class Magicien : public Personnage
{
public:
    Magicien(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax) :
        Personnage(nom, niveau, HP, HPMax, ATK, INT, DEX, exp, expmax, mana, manamax)
    {
        if (niveau >= 4) {
            ThunderBolt(*this); // Débloque la nouvelle capacité si le niveau est supérieur ou égal à 4
        }
    }


    Magicien() :
        Personnage("Magicien", 1, 100, 100, 10, 1, 15, 4, 100, 50, 50)
    {

    }

    void Siphon(Personnage& ennemi);
    void FireBolt(Personnage& ennemi);
    void ThunderBolt(Personnage& ennemi);
    int getManaCost(std::string spellName);
    int getDamage(std::string spellName); // Fonction pour obtenir les dégâts d'un sort
   
private:

};
