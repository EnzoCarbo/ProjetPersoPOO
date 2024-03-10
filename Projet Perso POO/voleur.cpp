#include "voleur.h"
#include<iostream>
#include <cstdlib>

void Voleur::LameEmpoisonnée(Personnage& ennemi) {
    if (!utiliseMana(40)) {
        return;
    }
    
    // Dégâts fois 4 basé sur l'ATK
    int degats = this->getATK() * 5; 
    std::cout << this->getNom() << " utilise Lame Empoisonnée sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    ennemi.recevoirDegats(degats);

}

void Voleur::CoupVampirique(Personnage& ennemi) {
    if (!utiliseMana(30)) {
        return;
    }

    // Dégâts fois 3 basé sur lA DEX
    int degats = this->getDEX() * 3; 
    std::cout << this->getNom() << " utilise Coup Vampirique sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;

    ennemi.recevoirDegats(degats);

    // Récupère la moitié des dégats infligés en HP
    int hp_recupere = degats / 2;
    this->recevoirSoins(hp_recupere);
}

int Voleur::getManaCost(std::string spellName) {
    // Retourne le coût en mana en fonction du nom du sort
    if (spellName == "LameEmpoisonnée") {
        return 40;
    }
    else if (spellName == "CoupVampirique") {
        return 30;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0; // Retourne 0 pour les sorts inconnus
    }
}

int Voleur::getDamage(std::string spellName) {
    // Retourne les dégâts en fonction du nom du sort
    if (spellName == "LameEmpoisonnée") {
        return this->getATK() * 5;
    }
    else if (spellName == "CoupVampirique") {
        return this->getDEX() * 2;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0; // Retourne 0 pour les sorts inconnus
    }
}