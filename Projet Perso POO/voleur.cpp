#include "voleur.h"
#include<iostream>
#include <cstdlib>

void Voleur::LameEmpoisonn�e(Personnage& ennemi) {
    if (!utiliseMana(40)) {
        return;
    }
    
    // D�g�ts fois 4 bas� sur l'ATK
    int degats = this->getATK() * 5; 
    std::cout << this->getNom() << " utilise Lame Empoisonn�e sur " << ennemi.getNom() << " et inflige " << degats << " d�g�ts !" << std::endl;
    ennemi.recevoirDegats(degats);

}

void Voleur::CoupVampirique(Personnage& ennemi) {
    if (!utiliseMana(30)) {
        return;
    }

    // D�g�ts fois 3 bas� sur lA DEX
    int degats = this->getDEX() * 3; 
    std::cout << this->getNom() << " utilise Coup Vampirique sur " << ennemi.getNom() << " et inflige " << degats << " d�g�ts !" << std::endl;

    ennemi.recevoirDegats(degats);

    // R�cup�re la moiti� des d�gats inflig�s en HP
    int hp_recupere = degats / 2;
    this->recevoirSoins(hp_recupere);
}

int Voleur::getManaCost(std::string spellName) {
    // Retourne le co�t en mana en fonction du nom du sort
    if (spellName == "LameEmpoisonn�e") {
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
    // Retourne les d�g�ts en fonction du nom du sort
    if (spellName == "LameEmpoisonn�e") {
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