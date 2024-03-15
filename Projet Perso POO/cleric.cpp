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

void Cleric::LumièreDivine(Personnage& ennemi) {
    if (!utiliseMana(40)) {
        return;
    }

    //Dégats fois 3 basé sur sa INT
    int degats = this->getINT() * 3; 
    std::cout << this->getNom() << " utilise Lumière Divine sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
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
    // Retourne le coût en mana en fonction du nom du sort
    if (spellName == "Heal") {
        return 50;
    }
    else if (spellName == "LumièreDivine") {
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
    // Retourne les dégâts en fonction du nom du sort
    if (spellName == "Heal") {
        return this->getINT() + 200;
    }
    else if (spellName == "LumièreDivine") {
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