#include "personnage.h"
#include<string>
#include<iostream>
#include "personnage.h"


// Constructeur avec param�tres / classe jouable
Personnage::Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax)
    : nom(nom), Niveau(niveau), HP(HP), HPMax(HPMax), ATK(ATK), INT(INT), DEX(DEX), EXP(exp), ExpMax(expmax), Mana(mana), ManaMax(manamax) {
    potions.resize(3, "Potion de vie");
};

// Constructeur avec param�tres / classe IA
Personnage::Personnage(std::string nom, int hp, int atk)
    : nom(nom), HP(hp), HPMax(hp), ATK(atk) {
}

// Destructeur
Personnage::~Personnage() {}

//V�rifie sur le personnage est vivant ou non
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

//Fonction attaque de base commune bas� sur l'ATK
void Personnage::attaque(Personnage& cible)
{
    std::cout << "--------------------- " << "\n";
    std::cout << nom << " attaque " << cible.getNom() << std::endl;
    cible.recevoirDegats(ATK);
}

//Fonction pour recevoir des d�gats
void Personnage::recevoirDegats(int degats)
{
    //Si le personnage se defend il prend 2 fois moins de d�gats sinon il prend 100%
    if (EnDefense) {
        degats /= 2;
        std::cout << nom << " se d�fend et r�duit les d�g�ts de moiti�.\n";
        EnDefense = false;
    }
    
    HP -= degats;
    std::cout << nom << " re�oit " << degats << " d�g�ts.\n";
}

//Fonction pour gagner des HP
void Personnage::recevoirSoins(int soins) {
    HP += soins;
    std::cout << nom << " r�cup�re " << soins << " points de vie !" << std::endl;

    //V�rifie si les HP ne d�passe pas le maximum et si c'est le cas le set au maximimun
    if (HP > HPMax) {
        HP = HPMax;
    }
}

//Fonction pour gagner du mana
void Personnage::recevoirMP(int mana) {
    Mana += mana;
    std::cout << nom << " r�cup�re " << mana << " points de Mana !" << std::endl;

    //V�rifie si le mana ne d�passe pas le maximum et si c'est le cas le set au maximimun
    if (Mana > ManaMax) {
        Mana = ManaMax;
    }
}

//Fonction pour gagner du niveau
void Personnage::gagnerEXP(int exp) {
    system("cls");
    std::cout << "Voys avez gang�" << exp << "point d'experience" << std::endl;
    EXP += exp;

    //Si assez d'EXP gagn� appelle la func LevelUP
    if (EXP >= ExpMax) {
        levelUP();
    }
}

//Fonction pour monter de niveau static et commun aux personnages 
void Personnage::levelUP() {
    std::cout << "Vous �tes pass� au niveau sup�rieur !" << std::endl;

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
    std::cout << "Stats am�lior�es:\n";
    std::cout << "PV maximum: " << HPMax << ", Mana maximum: " << ManaMax << "\n";
    std::cout << "ATK: " << ATK << ", INT: " << INT << ", DEX: " << DEX << "\n";
    std::cout << "Exp�rience n�cessaire pour le prochain niveau: " << ExpMax << "\n";
}

//Enable la defense sur true
void Personnage::Defense() {
    EnDefense = true;
}

//Fonction pour utiliser des potions de HP
void Personnage::utiliserPotion() {

    //Si potion presente dans le vecteur rend 200 HP et en supprime une sinon pas de potion disponible
    if (!potions.empty()) {
        std::cout << nom << " utilise une potion de vie et r�cup�re 200 points de vie.\n";
        HP += 200; 
        if (HP > HPMax) {
            HP = HPMax;
        }
        potions.erase(potions.begin());
    }
    else {
        std::cout << "Aucune potion disponible.\n";
    }
}

//Retourne le nombre de potion  dans le vecteur
size_t Personnage::getQuantit�Potions() const {
    return potions.size();
}

// Fonction pour perdre de la mana
bool Personnage::utiliseMana(int manacost) {
    if (manacost > Mana) {
        std::cout << "Impossible d'utiliser ce sort. Pas assez de Mana." << std::endl;
        return false;
    }

    Mana -= manacost;
    if (Mana < 0) {
        Mana = 0; // Assure que la mana ne devienne pas n�gative
    }

    std::cout << nom << " perd " << manacost << " points de Mana." << std::endl;
    return true;
}