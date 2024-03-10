#include "guerrier.h"
#include<iostream>
#include <cstdlib>

void Guerrier::CoupTranchant(Personnage& ennemi) {
    
    int degats = this->getATK() * 2; // D�g�ts doubl�s
    std::cout << this->getNom() << " utilise Coup Tranchant sur " << ennemi.getNom() << " et inflige " << degats << " d�g�ts !" << std::endl;
    ennemi.recevoirDegats(degats);

}

void Guerrier::CoupDeBouclier(Personnage& ennemi) {
   
    int degats = this->getATK() * 1.5; // D�g�ts tripl�s
    std::cout << this->getNom() << " utilise Coup De Bouclier sur " << ennemi.getNom() << " et inflige " << degats << " d�g�ts !" << std::endl;
    ennemi.recevoirDegats(degats);
}
   
   
int Guerrier::getManaCost(std::string spellName) {
    // Retourne le co�t en mana en fonction du nom du sort
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
    // Retourne les d�g�ts en fonction du nom du sort
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