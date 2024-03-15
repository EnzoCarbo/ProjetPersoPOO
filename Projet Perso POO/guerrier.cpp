#include "guerrier.h"
#include<iostream>
#include <cstdlib>
#include<string>




void Guerrier::CoupTranchant(Personnage& ennemi) {
    int degats;
    if (!utiliseMana(20)) {
        return;
    }
    if (critBuff) {
        degats = this->getATK() * 6;
        std::cout <<" L'attaque crit sur  " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    }
    else {
        degats = this->getATK() * 2;
        std::cout << this->getNom() << " utilise Coup Tranchant sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    }
    ennemi.recevoirDegats(degats);
    critBuff = false;
}

void Guerrier::CoupDeBouclier(Personnage& ennemi) {
    int degats;
    if (!utiliseMana(10)) {
        return;
    }
    Defense();
    if (critBuff) {
        degats = static_cast<int>(this->getATK() * 4.5);
        std::cout <<" L'attaque crit sur  " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;

    }
    else {
        degats = static_cast<int>(this->getATK() * 1.5);
        std::cout << this->getNom() << " utilise Coup De Bouclier sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;

    }
    ennemi.recevoirDegats(degats);
    critBuff = false;
}
   
   
int Guerrier::getManaCost(std::string spellName) {
    // Retourne le coût en mana en fonction du nom du sort
    if (spellName == "CoupTranchant") {
        return 20;
    }
    else if (spellName == "CoupDeBouclier") {
        return 10;
    }
    else if(spellName == "CriDeGuerre") {
        return 5;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0;
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
    else if (spellName == "CriDeGuerre") {
        return NULL;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0;
    }
}

void Guerrier::criDeGuerre()
{
    if (!utiliseMana(5)) {
        return;
    }
    critBuff = true;
}