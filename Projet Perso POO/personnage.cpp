#include "personnage.h"
#include<string>
#include<iostream>




// Constructeur avec paramètres / classe jouable
Personnage::Personnage(std::string nom, int niveau, int HP, int HPMax, int ATK, int INT, int DEX, int exp, int expmax, int mana, int manamax)
    : nom(nom), Niveau(niveau), HP(HP), HPMax(HPMax), ATK(ATK), INT(INT), DEX(DEX), EXP(exp), ExpMax(expmax), Mana(mana), ManaMax(manamax) {
     inventaire.push_back({ "Potion de Mana", 3 });
     inventaire.push_back({ "Potion de HP", 3 });
    
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
        // Trouver une potion de vie dans l'inventaire
        auto it = std::find_if(inventaire.begin(), inventaire.end(), [](const Item& item) {
            return item.nom == "Potion de HP";
            });

        if (it != inventaire.end() && it->quantite > 0) {
            std::cout << nom << " utilise une potion de vie et récupère 200 points de vie.\n";
            HP += 200;
            if (HP > HPMax) {
                HP = HPMax;
            }
            it->quantite--; // Diminuer la quantité de potions de vie dans l'inventaire
            if (it->quantite == 0) {
                inventaire.erase(it); // Supprimer la potion de vie si sa quantité atteint 0
            }
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
        // Trouver une potion de Mana dans l'inventaire
        auto it = std::find_if(inventaire.begin(), inventaire.end(), [](const Item& item) {
            return item.nom == "Potion de Mana";
            });

        if (it != inventaire.end() && it->quantite > 0) {
            std::cout << nom << " utilise une potion de Mana et récupère 50 points de Mana.\n";
            Mana += 50; // Vous pouvez ajuster la quantité de mana récupérée selon vos besoins
            if (Mana > ManaMax) {
                Mana = ManaMax;
            }
            it->quantite--; // Diminuer la quantité de potions de Mana dans l'inventaire
            if (it->quantite == 0) {
                inventaire.erase(it); // Supprimer la potion de Mana si sa quantité atteint 0
            }
        }
        else {
            std::cout << "Aucune potion de Mana disponible.\n";
        }
    }
    else {
        std::cout << "Vos points de mana sont déjà au maximum.\n";
    }
}

void Personnage::modifierArgent(int montant) {
    Or += montant;
    if (Or < 0) {
        Or = 0; // Assure que l'argent ne devienne jamais négatif
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
    for (const Item& item : inventaire) {
        if (item.nom == "Potion de HP") { // Accéder à l'attribut "nom" de l'objet "item"
            quantiteHP += item.quantite; // Ajouter la quantité de potions de vie
        }
    }
    return quantiteHP;
}

size_t Personnage::getQuantitePotionsMana() const {
    size_t quantiteMana = 0;
    for (const Item& item : inventaire) { // Parcourir l'inventaire du personnage
        if (item.nom == "Potion de Mana") { // Vérifier si l'objet est une potion de mana
            quantiteMana += item.quantite; // Ajouter la quantité de potions de mana
        }
    }
    return quantiteMana;
}

void Personnage::addItem(const Item& objet, int montantArgent) {
    // Vérifie si l'objet est déjà dans l'inventaire
    for (Item& item : inventaire) {
        if (item.nom == objet.nom) {
            // Si oui, ajoute simplement la quantité
            item.quantite += objet.quantite;
            std::cout << "Vous obtenez : " << objet.quantite << " " << objet.nom <<  std::endl;
            return;
        }
    }
    // Si l'objet n'est pas déjà dans l'inventaire, l'ajoute
    std::cout << "Vous obtenez : " << objet.quantite << " " << objet.nom << std::endl;
    inventaire.push_back(objet);
                                          
    // Si un montant d'argent est spécifié, l'ajoute également à l'inventaire
    if (montantArgent > 0) {
        this->Or += montantArgent;
 
    }
}

void Personnage::afficherInventaire() const {
    std::cout << "Inventaire de " << nom << " :" << std::endl;
    for (const auto& item : inventaire) {
        std::cout << "- " << item.nom << " (Quantité : " << item.quantite << ")" << std::endl;
    }
}