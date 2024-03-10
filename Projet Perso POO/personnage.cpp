#include "personnage.h"
#include<string>
#include<iostream>
#include "personnage.h"



// Constructeur avec paramètres / classe jouable
Personnage::Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax)
    : nom(nom), Niveau(niveau), HP(HP), HPMax(HPMax), ATK(ATK), INT(INT), DEX(DEX), EXP(exp), ExpMax(expmax), Mana(mana), ManaMax(manamax) {
    potions.resize(3, "Potion de vie");
    potions.resize(6, "Potion de Mana");
};

// Constructeur avec paramètres / classe IA
Personnage::Personnage(std::string nom, int hp, int atk)
    : nom(nom), HP(hp), HPMax(hp), ATK(atk) {
}

// Destructeur
Personnage::~Personnage() {}

//Vérifie sur le personnage est vivant ou non
bool Personnage::EstVivant()
{
	if (HP > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Fonction attaque de base commune basé sur l'ATK
void Personnage::attaque(Personnage& cible)
{
    std::cout << "--------------------- " << "\n";
    std::cout << nom << " attaque " << cible.getNom() << std::endl;
    cible.recevoirDegats(ATK);
}

void Personnage::ExpulsionDuTerritoire(Personnage& cible) {
    std::cout << "--------------------- " << "\n";
    std::cout << nom << "utilise Expulsion Du Territoire " << cible.getNom() << std::endl;
    cible.recevoirDegats(ATK * 3);
}

//Fonction pour recevoir des dégats
void Personnage::recevoirDegats(int degats)
{
    //Si le personnage se defend il prend 2 fois moins de dégats sinon il prend 100%
    if (EnDefense) {
        degats /= 2;
        std::cout << nom << " se défend et réduit les dégâts de moitié.\n";
        EnDefense = false;
    }
    
    HP -= degats;
    std::cout << nom << " reçoit " << degats << " dégâts.\n";
}

//Fonction pour gagner des HP
void Personnage::recevoirSoins(int soins) {
    HP += soins;
    std::cout << nom << " récupère " << soins << " points de vie !" << std::endl;

    //Vérifie si les HP ne dépasse pas le maximum et si c'est le cas le set au maximimun
    if (HP > HPMax) {
        HP = HPMax;
    }
}

//Fonction pour gagner du mana
void Personnage::recevoirMP(int mana) {
    Mana += mana;
    std::cout << nom << " récupère " << mana << " points de Mana !" << std::endl;

    //Vérifie si le mana ne dépasse pas le maximum et si c'est le cas le set au maximimun
    if (Mana > ManaMax) {
        Mana = ManaMax;
    }
}

//Fonction pour gagner du niveau
void Personnage::gagnerEXP(int exp) {
    system("cls");
    std::cout << "Voys avez gangé" << exp << "point d'experience" << std::endl;
    EXP += exp;

    //Si assez d'EXP gagné appelle la func LevelUP
    if (EXP >= ExpMax) {
        levelUP();
    }
}

//Fonction pour monter de niveau static et commun aux personnages 
void Personnage::levelUP() {
    std::cout << "Vous êtes passé au niveau supérieur !" << std::endl;

    //Gain de niveau et de stat
    Niveau++; 
    HPMax += 10;
    HP = HPMax;
    ManaMax += 5;
    Mana = ManaMax; 
    ATK += 2; 
    INT += 2; 
    DEX += 2; 
    ExpMax *= 2;

    std::cout << nom << " passe au niveau " << Niveau << " !\n";
    std::cout << "--------------------- " << "\n";
    std::cout << "Stats améliorées:\n";
    std::cout << "PV maximum: " << HPMax << ", Mana maximum: " << ManaMax << "\n";
    std::cout << "ATK: " << ATK << ", INT: " << INT << ", DEX: " << DEX << "\n";
    std::cout << "Expérience nécessaire pour le prochain niveau: " << ExpMax << "\n";
}

//Enable la defense sur true
void Personnage::Defense() {
    EnDefense = true;
}

void Personnage::utiliserPotion() {
    // Vérifie si les points de vie actuels sont inférieurs au maximum
    if (HP < HPMax) {
        // Si une potion de vie est présente dans le vecteur
        auto it = std::find(potions.begin(), potions.end(), "Potion de vie");
        if (it != potions.end()) {
            std::cout << nom << " utilise une potion de vie et récupère 200 points de vie.\n";
            HP += 200;
            if (HP > HPMax) {
                HP = HPMax;
            }
            potions.erase(it); // Supprime la potion de vie utilisée
        }
        else {
            std::cout << "Aucune potion de vie disponible.\n";
        }
    }
    else {
        std::cout << "Vos points de vie sont déjà au maximum.\n";
    }
}


void Personnage::potionMana() {
    // Vérifie si les points de mana actuels sont inférieurs au maximum
    if (Mana < ManaMax) {
        // Si une potion de Mana est présente dans le vecteur
        auto it = std::find(potions.begin(), potions.end(), "Potion de Mana");
        if (it != potions.end()) {
            std::cout << nom << " utilise une potion de Mana et récupère 50 points de Mana.\n";
            Mana += 50; // Vous pouvez ajuster la quantité de mana récupérée selon vos besoins
            if (Mana > ManaMax) {
                Mana = ManaMax;
            }
            potions.erase(it); // Supprime la potion de Mana utilisée
        }
        else {
            std::cout << "Aucune potion de Mana disponible.\n";
        }
    }
    else {
        std::cout << "Vos points de mana sont déjà au maximum.\n";
    }
}


// Fonction pour perdre de la mana
bool Personnage::utiliseMana(int manacost) {
    if (manacost > Mana) {
        std::cout << "Impossible d'utiliser ce sort. Pas assez de Mana." << std::endl;
        return false;
    }

    Mana -= manacost;
    if (Mana < 0) {
        Mana = 0; // Assure que la mana ne devienne pas négative
    }

    std::cout << nom << " perd " << manacost << " points de Mana." << std::endl;
    return true;
}

size_t Personnage::getQuantitePotionsHP() const {
    size_t quantiteHP = 0;
    for (const std::string& potion : potions) {
        if (potion == "Potion de vie") {
            quantiteHP++;
        }
    }
    return quantiteHP;
}

size_t Personnage::getQuantitePotionsMana() const {
    size_t quantiteMana = 0;
    for (const std::string& potion : potions) {
        if (potion == "Potion de Mana") {
            quantiteMana++;
        }
    }
    return quantiteMana;
}