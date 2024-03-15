#include "cleric.h"
#include<iostream>
#include <cstdlib>

void Cleric::Heal(Personnage& cible) {
    if (!utiliseMana(40)) {
        return;
    }

    //Soigne la cible de 100 HP plus son INT
    int soin = 200 + getINT(); 
    cible.recevoirSoins(soin);
    std::cout << this->getNom() << " utilise le sort de soin sur " << cible.getNom() << " et restaure " << soin << " points de vie !" << std::endl;
}

void Cleric::Lumi�reDivine(Personnage& ennemi) {
    if (!utiliseMana(40)) {
        return;
    }

    //D�gats fois 3 bas� sur sa INT
    int degats = this->getINT() * 3; 
    std::cout << this->getNom() << " utilise Lumi�re Divine sur " << ennemi.getNom() << " et inflige " << degats << " d�g�ts !" << std::endl;
    ennemi.recevoirDegats(degats);
}

void Cleric::Benediction(Personnage& cible) {
    if (!utiliseMana(20)) {
        return;
        ATKBuff(10);
        INTBuff(10);
        DEXBuff(10);
    }

}

int Cleric::getManaCost(std::string spellName) {
    // Retourne le co�t en mana en fonction du nom du sort
    if (spellName == "Heal") {
        return 50;
    }
    else if (spellName == "Lumi�reDivine") {
        return 30;
    }
    else if (spellName == "Benediction") {
        return 20;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0; // Retourne 0 pour les sorts inconnus
    }
}

int Cleric::getDamage(std::string spellName) {
    // Retourne les d�g�ts en fonction du nom du sort
    if (spellName == "Heal") {
        return this->getINT() + 200;
    }
    else if (spellName == "Lumi�reDivine") {
        return this->getINT() * 3;
    }
    else if (spellName == "Benediction") {
        return NULL;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0; // Retourne 0 pour les sorts inconnus
    }
}