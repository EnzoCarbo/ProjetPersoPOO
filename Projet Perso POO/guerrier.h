#pragma once
#include"personnage.h"



class Guerrier : public Personnage
{
public:
    
    Guerrier(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax) :
        Personnage(nom, niveau, HP, HPMax, ATK, INT, DEX, exp, expmax, mana, manamax) 
    {

    }
    

    
    void CoupTranchant(Personnage& ennemi);
    void CoupDeBouclier(Personnage& ennemi);
    int getManaCost(std::string spellName);
    int getDamage(std::string spellName);
    void criDeGuerre();

private:
    Arme* arme;
    bool critBuff;
    std::vector<std::string> inventaire;
};

