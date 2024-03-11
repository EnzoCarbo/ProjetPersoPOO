#pragma once
#include"personnage.h"


class Guerrier : public Personnage
{
public:
    Guerrier(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int Mana, int manamax) :
        Personnage(nom, niveau, HP, HPMax, ATK, INT, DEX, exp, expmax, Mana, manamax)
    {
     
    }
    
    Guerrier() : Personnage("Guerrier", 1, 150, 150, 15, 1, 6, 0, 100, 50, 50)
    {
       
    }

    
    void CoupTranchant(Personnage& ennemi);
    void CoupDeBouclier(Personnage& ennemi);
    int getManaCost(std::string spellName);
    int getDamage(std::string spellName);
    void criDeGuerre();

private:
    bool critBuff;
    std::vector<std::string> inventaire;
};

