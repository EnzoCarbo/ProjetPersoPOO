#pragma once
#include<string>
class Arme
{

public :
    Arme();
    Arme(std::string nom, int ATK, int INT, int DEX);

    std::string getNom() const {
        return nom;
    }

    int getAtk() const {
        return ATK;
    }

    int getIntelligence() const {
        return INT;
    }

    int getDexterite() const {
        return DEX;
    }

private:
	std::string nom;
	int ATK;
	int INT;
	int DEX;
};



