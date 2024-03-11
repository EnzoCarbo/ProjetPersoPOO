#pragma once

#include <string>
#include <vector>

struct Item {
    std::string nom;
    int quantite;
};

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
    std::vector<std::string> potion;
    std::vector<Item> inventaire;
   
    

public:
    Personnage();
    Personnage(std::string nom, int hp, int atk);
    Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax);
    ~Personnage();

    bool EstVivant();
    void addItem(const Item& objet);
    void attaque(Personnage& cible);
    void ExpulsionDuTerritoire(Personnage& cible);
    void recevoirDegats(int degats);
    void Defense();
    void recevoirMP(int mana);
    void recevoirSoins(int soins);
    void gagnerEXP(int exp);
    void levelUP();
    void utiliserPotion();
    void potionMana();
    size_t getQuantitePotionsHP() const;
    size_t getQuantitePotionsMana() const;
    bool utiliseMana(int manacost);
    void looterObjet(const Item& objet);

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

