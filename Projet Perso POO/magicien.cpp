#include "magicien.h"
#include<iostream>
#include <cstdlib>

void Magicien::FireBolt(Personnage& ennemi) {
    if (!utiliseMana(50)) {   
        return;
    }

    //Dégats fois 5 basé sur la INT
    int degats = this->getINT() * 5; 
    std::cout << this->getNom() << " utilise FireBolt sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    ennemi.recevoirDegats(degats);
}

void Magicien::Siphon(Personnage& ennemi) {
    if (!utiliseMana(40)) {    
         return;
    }

    //Dégats fois 3 basé sur la INT
    int degats = this->getINT() * 2;
    std::cout << this->getNom() << " utilise Siphon sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    ennemi.recevoirDegats(degats);
 
    //Retourne des points de mana basé sur les dégats
    int mana_recupere = degats / 2; 
    this->recevoirMP(mana_recupere);
}

void Magicien::ThunderBolt(Personnage& ennemi) {

    if (!utiliseMana(70)) {
        return;
    }

    //Dégats fois 5 basé sur la INT
    int degats = this->getINT() * 7;
    std::cout << this->getNom() << " utilise ThunderBolt sur " << ennemi.getNom() << " et inflige " << degats << " dégâts !" << std::endl;
    ennemi.recevoirDegats(degats);
}

int Magicien::getManaCost(std::string spellName) {
    if (spellName == "FireBolt") {
        return 50;
    }
    else if (spellName == "Siphon") {
        return 40;
    }
    else if (spellName == "ThunderBolt") {
        return 70;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0;
    }
}

int Magicien::getDamage(std::string spellName) {
    if (spellName == "FireBolt") {
        return this->getINT() * 5;
    }
    else if (spellName == "Siphon") {
        return this->getINT() * 2;
    }
    else if (spellName == "ThunderBolt") {
        return this->getINT() * 7;
    }
    else {
        std::cout << "Sort inconnu !" << std::endl;
        return 0;
    }
}


