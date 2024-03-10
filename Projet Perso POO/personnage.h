#pragma once

#include <string>
#include <vector>

class Personnage
{
private:
    std::string nom;
    int Niveau;
    int HP;
    int HPMax;
    int Mana;
    int ManaMax;
    int ATK;
    int INT;
    int DEX;
    int EXP;
    int ExpMax;
    bool EnDefense;
    std::vector<std::string> potions;
   
    

public:
    Personnage();
    Personnage(std::string nom, int hp, int atk);
    Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax);
    ~Personnage();

    bool EstVivant();

    void attaque(Personnage& cible);
    
    void recevoirDegats(int degats);
    void Defense();
    void recevoirMP(int mana);
    void recevoirSoins(int soins);
    void gagnerEXP(int exp);
    void levelUP();
    void utiliserPotion();
    size_t getQuantitéPotions() const;
    bool utiliseMana(int manacost);


    inline std::string getNom() { return nom; };
    inline int getNiveau() { return Niveau; };

    inline int getHP() { return HP; };
    inline int getHPMax() { return HPMax; };
    inline int getMana() { return Mana; };
    inline int getManaMax() { return ManaMax; };

    inline int getATK() { return ATK; };
    inline int getINT() { return INT; };
    inline int getDEX() { return DEX; };

    inline int getEXP() { return EXP; };
    inline int getExpMax() { return ExpMax; };

};

