#include "marchand.h"
#include"personnage.h"
#include <iostream>

Marchand::Marchand() {
    vente.push_back({ "Potion de HP", 1, 10});
    vente.push_back({ "Potion de Mana", 3, 10 });// Exemple de potion de vie
}

void Marchand::afficherInventaire() const {
    int numeroItem = 1;
    std::cout << "Inventaire du marchand :" << std::endl;
    for (const auto& item : vente) {
        std::cout << numeroItem <<". " << item.nom << "         |Quantité :" << item.quantite << "            |Prix : "<< item.prix <<std::endl;
        numeroItem++;
    }
}


bool Marchand::acheter(Personnage& acheteur, const std::string& nomObjet) {
    for (Item& item : vente) {
        if (item.nom == nomObjet && item.quantite > 0) {
            if (acheteur.getArgent() >= item.prix) { // Utilise le prix de l'objet
                acheteur.addItem(item, 0); // Ajoute l'objet à l'inventaire du personnage
                acheteur.modifierArgent(-item.prix); // Retire le prix de l'argent du personnage
                item.quantite--; // Diminue la quantité de l'objet dans l'inventaire du marchand
                std::cout << "Vous avez acheté " << item.nom << " pour " << item.prix << " pièces d'or." << std::endl;
                afficherInventaire();
                return true;
            }
            else {
                std::cout << "Vous n'avez pas assez d'or pour acheter " << item.nom << "." << std::endl;
                afficherInventaire();
                return false;
            }
        }
    }
    std::cout << "Le marchand ne vend pas " << nomObjet << " ou l'objet n'est plus disponible." << std::endl;
    afficherInventaire();
    return false;
}
