#include<iostream>
#include <cstdlib>
#include <iomanip>
#include<ctime>
#include"guerrier.h"
#include"magicien.h"
#include"voleur.h"
#include"cleric.h"



//TO DO
//Redondance code, combat / menu
//Equilibrage
//Sort du Guerrier
//Merge inventaire + potion
//Sytème de marchand
//Systeme craft
//Système Equipement 
//Ne pas perdre un tour quand je sors de l'inventaire


Guerrier monGuerrier("Guerrier", 1, 1200, 1200, 20, 1, 8, 0, 100, 20, 20);
Magicien monMagicien("Magicien", 1, 7100, 7100, 5, 20, 4, 0, 100, 10000, 10000);
Voleur monVoleur("Voleur", 1, 1000, 1000, 10, 3, 15, 0, 100, 80, 80);
Cleric monCleric("Cleric", 1, 1000, 1000, 6, 15, 10, 0, 100, 80, 80);


void HUD(Personnage& personnage, Personnage& ennemie) {
	std::cout << personnage.getNom() << "			 | HP : " << personnage.getHP() << " / " << personnage.getHPMax() << "			| Mana : " << personnage.getMana() << " / " << personnage.getManaMax() << "\n";
	std::cout << "Niveau : " << personnage.getNiveau() << std::endl;
	std::cout << "Exp : " << personnage.getEXP() << " / " << personnage.getExpMax() << "\n";
	std::cout << "Or :" << personnage.getArgent() << std::endl;
 	std::cout << "\n";
	std::cout << ennemie.getNom() << "			 | HP : " << ennemie.getHP() << "\n";
	std::cout << "--------------------- " << "\n";
	std::cout << "Que voulez-vous faire ?" << std::endl;
	std::cout << "1. Attaquer			 | Degats : " << personnage.getATK() << std::endl;
	std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
	std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantité : " << personnage.getQuantitePotionsHP() << std::endl;
	std::cout << "4. Utiliser Potion de MP	 | MP + 50			| Quantité : " << personnage.getQuantitePotionsMana() << std::endl;
	std::cout << "--------------------- " << "\n";
	std::cout << "Compétences : " << "\n";
	if (personnage.getNom() == "Guerrier") {
		std::cout << "5. Coup Tranchant	 	 | Degats : " << monGuerrier.getDamage("CoupTranchant") << "			| MP : " << monGuerrier.getManaCost("CoupTranchant") << std::endl;
		std::cout << "6. Coup De Bouclier	 	 | Degats : " << monGuerrier.getDamage("CoupDeBouclier") << "			| MP : " << monGuerrier.getManaCost("CoupDeBouclier") << std::endl;
	}
	if (personnage.getNom() == "Magicien") {
		std::cout << "5. Fire Bolt			 | Degats : " << monMagicien.getDamage("FireBolt") << "			| MP : " << monMagicien.getManaCost("FireBolt") << std::endl;
		std::cout << "6. Siphon			 | Degats : " << monMagicien.getDamage("Siphon") << "			| MP : " << monMagicien.getManaCost("Siphon") << std::endl;
		if (personnage.getNiveau() >= 4) {
			std::cout << "7. ThunderBolt			 | Degats : " << monMagicien.getDamage("ThunderBolt") << "			| MP : " << monMagicien.getManaCost("ThunderBolt") << std::endl;
		}
	}
	if (personnage.getNom() == "Voleur") {
		std::cout << "5. Coup Vampirique		 | Degats : " << monVoleur.getDamage("CoupVampirique") << "			| MP : " << monVoleur.getManaCost("CoupVampirique") << std::endl;
		std::cout << "6. Lame Empoisonnée		 | Degats : " << monVoleur.getDamage("LameEmpoisonnée") << "			| MP : " << monVoleur.getManaCost("LameEmpoisonnée") << std::endl;
	}
	if (personnage.getNom() == "Cleric") {
		std::cout << "5. Heal				 | Heal : " << monCleric.getDamage("Heal") << "			| MP : " << monCleric.getManaCost("Heal") << std::endl;
		std::cout << "6. Lumière Divine		 | Degats : " << monCleric.getDamage("LumièreDivine") << "			| MP : " << monCleric.getManaCost("LumièreDivine") << std::endl;
	}
	std::cout << "Votre choix : " << std::endl;
}

void menuInventaire(Personnage& personnage) {
	personnage.afficherInventaire();
	std::cout << "Veuillez choisir une action :\n";
	std::cout << "1. Utiliser une potion de HP\n";
	std::cout << "2. Utiliser une potion de mana\n";
	int choixPotion;
	std::cin >> choixPotion;
	if (choixPotion == 1) {
		personnage.utiliserPotion();
	}
	else if (choixPotion == 2) {
		personnage.potionMana();
	}
	else {
		std::cout << "Choix invalide.\n";
	}
}

void menuCombat(Personnage& personnage, Personnage& ennemi) {
	bool choixValideBoss = false;
	int choixBoss;
	do {
		std::cin >> choixBoss;
		std::cout << std::endl;
		if (std::cin.fail() || (choixBoss < 1 || choixBoss > 7) || (choixBoss == 7 && monMagicien.getNiveau() < 4)) {
			std::cin.clear(); // Efface l'état d'erreur du flux
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore les caractères restants dans le flux
			std::cout << "Choix invalide. Veuillez saisir un choix valide.\n";
		}
		else {
			choixValideBoss = true;
		}
	} while (!choixValideBoss);

	// Effacer l'écran après avoir fait un choix valide
	system("cls");

	if (personnage.getNom() == "Guerrier") {
		switch (choixBoss) {
		case 1:
			monGuerrier.attaque(ennemi);
			break;
		case 2:
			monGuerrier.Defense();
			break;
		case 3:
			menuInventaire(personnage);
			break;
		case 4:
			monGuerrier.potionMana();
			break;
		case 5:
			monGuerrier.CoupTranchant(ennemi);
			break;
		case 6:
			monGuerrier.CoupDeBouclier(ennemi);
			break;
		default:
			break;
		}
	}
	// Exécuter l'action en fonction du choix
	if (personnage.getNom() == "Magicien") {
		switch (choixBoss) {
		case 1:
			monMagicien.attaque(ennemi);
			break;
		case 2:
			monMagicien.Defense();
			break;
		case 3:
			menuInventaire(personnage);
			break;
		case 4:
			monMagicien.potionMana();
			break;
		case 5:
			monMagicien.FireBolt(ennemi);
			break;
		case 6:
			monMagicien.Siphon(ennemi);
			break;
		case 7:
			monMagicien.ThunderBolt(ennemi);
			break;
		default:
			break;
		}
	}
	if (personnage.getNom() == "Voleur") {
		switch (choixBoss) {
		case 1:
			monVoleur.attaque(ennemi);
			break;
		case 2:
			monVoleur.Defense();
			break;
		case 3:
			menuInventaire(personnage);
			break;
		case 4:
			monVoleur.potionMana();
			break;
		case 5:
			monVoleur.CoupVampirique(ennemi);
			break;
		case 6:
			monVoleur.LameEmpoisonnée(ennemi);
			break;
		default:
			break;
		}
	}
	if (personnage.getNom() == "Cleric") {
		switch (choixBoss) {
		case 1:
			monCleric.attaque(ennemi);
			break;
		case 2:
			monCleric.Defense();
			break;
		case 3:
			menuInventaire(personnage);
			break;
		case 4:
			monCleric.potionMana();
			break;
		case 5:
			monCleric.Heal(ennemi);
			break;
		case 6:
			monCleric.LumièreDivine(ennemi);
			break;
		default:
			break;
		}
	}
}


void combat(Personnage& personnage) {

	srand(time(nullptr));
	//Initialise un Magicien avec un constructeur
	
	std::vector<Item> listLootChauveSouris = { {"Aile", 1},{"Dent", 2},{"Peau", 1} };
	std::vector<Item> listLootGobelin = { {"Dague", 1},{"Bourse d'or", 2},{"Anneau", 1} };
	std::vector<Item> listLootTroll = { {"Massue", 1},{"Casque", 2},{"Bottes", 1} };
	std::vector<Item> listLootBoss = { {"Nez", 1},{"Oreille", 2},{"Peau", 1} };
	//Variable pour faire des combats à la chaine et nommer les ennemies
	int ennemisBattus = 0;
	int bossBattu = 0;
	int toursDepuisDernierSpecial = 0;

	//Boucle de combat avec 25 combats
	for (int i = 1; i <= 25; i++) {

		int typeEnnemi = rand() % 3;
		std::string nomEnnemi;
		int atk, hp;
		switch (typeEnnemi) {
		case 0: 
			nomEnnemi = "Chauve-souris " + std::to_string(i);
			hp = 50 + i * 20;
			atk = 20 + i * 5;
			break;
		case 1: 
			nomEnnemi = "Gobelin " + std::to_string(i);
			hp = 100 + i * 30;
			atk = 30 + i * 10;
			break;
		case 2: 
			nomEnnemi = "Troll " + std::to_string(i);
			hp = 200 + i * 40;
			atk = 40 + i * 15;
			break;
		}

		//Initialise un ennemi avec un Constructeur (nom, hp, atk)
		Personnage ennemi(nomEnnemi, hp, atk);
		std::cout << "--------------------- " << "\n";
		std::cout << "Combat entre " << personnage.getNom() << " et " << ennemi.getNom() << " !\n";
		std::cout << "--------------------- " << "\n";
		std::cout << " \n";
		std::cout << " \n";

		//Boucle de combat tant que mon perso ou l'aderversaire est en vie
		while (personnage.EstVivant() && ennemi.EstVivant()) {
			HUD(personnage, ennemi);

			//Menu d'attaque pour le Magicien envers le gobelin
			menuCombat(personnage, ennemi);
			//Le gobelin attaque
			ennemi.attaque(personnage);
			std::cout << "--------------------- " << "\n";

			//Si le gobelin meurt donne de l'experience et augmente la difficultée
			if (!ennemi.EstVivant()) {
				personnage.gagnerEXP(50 + i * (10 * i));
				ennemisBattus++;
				Item objetLoot;
				switch (typeEnnemi) {
				case 0:
					objetLoot = listLootChauveSouris[rand() % listLootChauveSouris.size()];
					break;
				case 1:
					objetLoot = listLootGobelin[rand() % listLootGobelin.size()];
					break;
				case 2:
					objetLoot = listLootTroll[rand() % listLootTroll.size()];
					break;
				}

				int goldMob = rand() % 4 + 3;

				// Ajouter cet objet à l'inventaire du personnage
				personnage.addItem(objetLoot, goldMob);
				if (ennemisBattus % 5 == 0) {

					// Initialise le Boss
					std::string nomBoss = "Zemmour " + std::to_string(bossBattu + 1);
					Personnage boss(nomBoss, 500, 200);
					std::cout << "--------------------- " << "\n";
					std::cout << "Combat entre " << personnage.getNom() << " et " << boss.getNom() << " !\n";

					// Tant que le personnage ou le boss est en vie, le combat continue
					while (personnage.EstVivant() && boss.EstVivant()) {
						HUD(personnage, boss);
						std::cout << "Votre choix : ";

						// Menu d'attaque du Magicien contre le Boss
						menuCombat(personnage, boss);

						int goldBoss = rand() % 4 + 10;
						// Mort du Boss donne de l'expérience et augmente le compteur de 1
						if (!boss.EstVivant()) {
							// Donner de l'expérience
							personnage.gagnerEXP(150 + i * (10 * i));
							// Choisir aléatoirement un objet parmi ceux possibles
							int indexObjetLoot = rand() % listLootBoss.size();
							const Item& objetLootBoss = listLootBoss[indexObjetLoot];
							// Ajouter cet objet à l'inventaire du personnage
							personnage.addItem(objetLootBoss, goldBoss);
							bossBattu++;
							break;
						}

						// Attaque du Boss
						boss.attaque(personnage);
						toursDepuisDernierSpecial++;
						if (toursDepuisDernierSpecial == 3) {
							// Appel de la fonction pour le coup spécial du boss
							boss.ExpulsionDuTerritoire(personnage);

							// Réinitialisation du compteur de tours depuis le dernier coup spécial
							toursDepuisDernierSpecial = 0;
						}
						std::cout << "--------------------- " << "\n";
					}
				}
			}
		}
		// Sort de la boucle combat en cas de mort et retourne au menu
		if (!monMagicien.EstVivant()) {
			std::cout << "Vous êtes mort" << std::endl;
			break;
		}
		// Sort de la boucle combat en cas de mort et retourne au menu
		if (!personnage.EstVivant()) {
			std::cout << "Vous êtes mort" << std::endl;
			break;
		}
	}
}

//Focntion Rejouer
bool Rejouer() {
	int choix;
	std::cout << "Voulez-vous rejouer ? (1 pour oui, 0 pour non) : ";
	std::cin >> choix;

	//Si choisi autre que 0 et 1 renvoi la fonction rejouer et redemande
	if (choix != 0 && choix != 1) {
		std::cout << "Choix invalide. Veuillez saisir 1 pour oui ou 0 pour non." << std::endl;
		return Rejouer();
	}

	//Choisi 1 renvoie true
	return (choix == 1);
}

//Fonction main
int main() {

	bool jouer = true;

	//Si le joeur veux rejouer, display le menu de choix de classe
	while (jouer) {
		std::cout << "Choisissez votre classe" << std::endl;
		std::cout << "1. Guerrier" << std::endl;
		std::cout << "2. Magicien" << std::endl;
		std::cout << "3. Voleur" << std::endl;
		std::cout << "4. Cleric" << std::endl;
		std::cout << "Votre choix : ";
		int choice;
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice) {
		case 1:
			system("cls");
			combat(monGuerrier);
			break;
		case 2:
			system("cls");
			combat(monMagicien);
			break;
		case 3:
			system("cls");
			combat(monVoleur);
			break;
		case 4:
			system("cls");
			combat(monCleric);
			break;
		default:
			std::cout << "Choix invalide. Veuillez choisir une classe valide." << std::endl;
			break;
		}

		//Appelle fonction rejouer
		jouer = Rejouer();
	}

	return 0;
}
