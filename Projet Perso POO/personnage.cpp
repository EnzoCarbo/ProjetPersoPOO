#include "personnage.h"
#include<string>
#include<iostream>




// Constructeur avec param�tres / classe jouable
Personnage::Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax)
    : nom(nom), Niveau(niveau), HP(HP), HPMax(HPMax), ATK(ATK), INT(INT), DEX(DEX), EXP(exp), ExpMax(expmax), Mana(mana), ManaMax(manamax) {
     inventaire.push_back({ "Potion de Mana", 3 });
     inventaire.push_back({ "Potion de HP", 3 });
    
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

void Personnage::ExpulsionDuTerritoire(Personnage& cible) {
    std::cout << "--------------------- " << "\n";
    std::cout << nom << "utilise Expulsion Du Territoire " << cible.getNom() << std::endl;
    cible.recevoirDegats(ATK * 3);
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

void Personnage::utiliserPotion() {
    // V�rifie si les points de vie actuels sont inf�rieurs au maximum
    if (HP < HPMax) {
        // Trouver une potion de vie dans l'inventaire
        auto it = std::find_if(inventaire.begin(), inventaire.end(), [](const Item& item) {
            return item.nom == "Potion de HP";
            });

        if (it != inventaire.end() && it->quantite > 0) {
            std::cout << nom << " utilise une potion de vie et r�cup�re 200 points de vie.\n";
            HP += 200;
            if (HP > HPMax) {
                HP = HPMax;
            }
            it->quantite--; // Diminuer la quantit� de potions de vie dans l'inventaire
            if (it->quantite == 0) {
                inventaire.erase(it); // Supprimer la potion de vie si sa quantit� atteint 0
            }
        }
        else {
            std::cout << "Aucune potion de vie disponible.\n";
        }
    }
    else {
        std::cout << "Vos points de vie sont d�j� au maximum.\n";
    }
}


void Personnage::potionMana() {
    // V�rifie si les points de mana actuels sont inf�rieurs au maximum
    if (Mana < ManaMax) {
        // Trouver une potion de Mana dans l'inventaire
        auto it = std::find_if(inventaire.begin(), inventaire.end(), [](const Item& item) {
            return item.nom == "Potion de Mana";
            });

        if (it != inventaire.end() && it->quantite > 0) {
            std::cout << nom << " utilise une potion de Mana et r�cup�re 50 points de Mana.\n";
            Mana += 50; // Vous pouvez ajuster la quantit� de mana r�cup�r�e selon vos besoins
            if (Mana > ManaMax) {
                Mana = ManaMax;
            }
            it->quantite--; // Diminuer la quantit� de potions de Mana dans l'inventaire
            if (it->quantite == 0) {
                inventaire.erase(it); // Supprimer la potion de Mana si sa quantit� atteint 0
            }
        }
        else {
            std::cout << "Aucune potion de Mana disponible.\n";
        }
    }
    else {
        std::cout << "Vos points de mana sont d�j� au maximum.\n";
    }
}

void Personnage::modifierArgent(int montant) {
    Or += montant;
    if (Or < 0) {
        Or = 0; // Assure que l'argent ne devienne jamais n�gatif
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
        Mana = 0; // Assure que la mana ne devienne pas n�gative
    }

    std::cout << nom << " perd " << manacost << " points de Mana." << std::endl;
    return true;
}

size_t Personnage::getQuantitePotionsHP() const {
    size_t quantiteHP = 0;
    for (const Item& item : inventaire) {
        if (item.nom == "Potion de HP") { // Acc�der � l'attribut "nom" de l'objet "item"
            quantiteHP += item.quantite; // Ajouter la quantit� de potions de vie
        }
    }
    return quantiteHP;
}

size_t Personnage::getQuantitePotionsMana() const {
    size_t quantiteMana = 0;
    for (const Item& item : inventaire) { // Parcourir l'inventaire du personnage
        if (item.nom == "Potion de Mana") { // V�rifier si l'objet est une potion de mana
            quantiteMana += item.quantite; // Ajouter la quantit� de potions de mana
        }
    }
    return quantiteMana;
}

void Personnage::addItem(const Item& objet, int montantArgent) {
    // V�rifie si l'objet est d�j� dans l'inventaire
    for (Item& item : inventaire) {
        if (item.nom == objet.nom) {
            // Si oui, ajoute simplement la quantit�
            item.quantite += objet.quantite;
            std::cout << "Vous obtenez : " << objet.quantite << " " << objet.nom <<  std::endl;
            return;
        }
    }
    // Si l'objet n'est pas d�j� dans l'inventaire, l'ajoute
    std::cout << "Vous obtenez : " << objet.quantite << " " << objet.nom << std::endl;
    inventaire.push_back(objet);
                                          
    // Si un montant d'argent est sp�cifi�, l'ajoute �galement � l'inventaire
    if (montantArgent > 0) {
        this->Or += montantArgent;
 
    }
}

void Personnage::afficherInventaire() const {
    std::cout << "Inventaire de " << nom << " :" << std::endl;
    for (const auto& item : inventaire) {
        std::cout << "- " << item.nom << " (Quantit� : " << item.quantite << ")" << std::endl;
    }
}