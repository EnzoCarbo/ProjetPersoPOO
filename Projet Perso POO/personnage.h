#pragma once

#include <string>
#include <vector>

struct Item {
    std::string nom;
    int quantite;
    int prix;

    inline std::string getNom() { return nom;}
    inline int getQuantite() { return quantite; }
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
    int Or;
    std::vector<Item> inventaire;
   
    

public:

    Personnage();
    Personnage(std::string nom, int hp, int atk);
    Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax);
    ~Personnage();

    bool EstVivant();
    
    void attaque(Personnage& cible);
    void ExpulsionDuTerritoire(Personnage& cible);
    void Defense();
    void recevoirDegats(int degats);
    void recevoirMP(int mana);
    void recevoirSoins(int soins);
    void gagnerEXP(int exp);
    void levelUP();
    void utiliserPotion();
    void potionMana();
    bool utiliseMana(int manacost);
    void addItem(const Item& objet, int montantArgent);
    void afficherInventaire() const;
    void modifierArgent(int montant);

    
    size_t getQuantitePotionsHP() const;
    size_t getQuantitePotionsMana() const;
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

    inline int getArgent() { return Or; }
};

