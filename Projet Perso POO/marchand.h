#pragma once
#include "personnage.h"

class Marchand {
private:
    std::vector<Item> vente;

public:
    Marchand();

    void afficherInventaire() const;
    bool acheter(Personnage& acheteur, const std::string& nomObjet);
};

