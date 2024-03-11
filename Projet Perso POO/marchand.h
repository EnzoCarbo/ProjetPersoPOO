#ifndef MARCHAND_H
#define MARCHAND_H

#include "personnage.h" // Incluez les en-t�tes n�cessaires

class Marchand {
private:
    std::vector<Item> vente;

public:
    Marchand();

    void afficherInventaire() const;
    bool acheter(Personnage& acheteur, const std::string& nomObjet);
};

#endif // MARCHAND_H
