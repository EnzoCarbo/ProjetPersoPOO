#include "guerrier.h"
#include<iostream>
#include <cstdlib>

void Guerrier::CoupTranchant(Personnage& ennemi) {
    
    int degats = this->getATK() * 2; // Dégâts doublés
    std::cout << this->getNom() << " utilise Coup Tranchant sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    ennemi.recevoirDegats(degats);

}

void Guerrier::CoupDeBouclier(Personnage& ennemi) {
   
    int degats = this->getATK() * 1.5; // Dégâts triplés
    std::cout << this->getNom() << " utilise Coup De Bouclier sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    ennemi.recevoirDegats(degats);
}
   
   
int Guerrier::getManaCost(std::string spellName) {
    // Retourne le coût en mana en fonction du nom du sort
    if (spellName == "CoupTranchant") {
        return 50;
    }
    else if (spellName == "CoupDeBouclier") {
        return 30;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0; // Retourne 0 pour les sorts inconnus
    }
}

int Guerrier::getDamage(std::string spellName) {
    // Retourne les dégâts en fonction du nom du sort
    if (spellName == "CoupTranchant") {
        return this->getATK() * 3;
    }
    else if (spellName == "CoupDeBouclier") {
        return this->getATK() * 2;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0; // Retourne 0 pour les sorts inconnus
    }
}