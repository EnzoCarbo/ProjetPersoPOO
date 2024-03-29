#include<iostream>
#include <cstdlib>
#include <iomanip>
#include<ctime>
#include"guerrier.h"
#include"magicien.h"
#include"voleur.h"
#include"cleric.h"
#include"marchand.h"	


//Initialisation des classes
Guerrier monGuerrier("Guerrier", 1, 1200, 1200, 20, 1, 8, 0, 100, 50, 50);
Magicien monMagicien("Magicien", 1, 700, 700, 5, 20, 4, 0, 100, 200, 200);
Voleur monVoleur("Voleur", 1, 800, 800, 10, 3, 15, 0, 100, 80, 80);
Cleric monCleric("Cleric", 1, 1000, 1000, 6, 15, 10, 0, 100,1200, 1200);



//Affichage de l'HUD pour tout les personnages
void HUD(Personnage& personnage, Personnage& ennemie) {
	std::cout << personnage.getNom() << "			 | HP : " << personnage.getHP() << " / " << personnage.getHPMax() << "			| Mana : " << personnage.getMana() << " / " << personnage.getManaMax() << "\n";
	std::cout << "Niveau : " << personnage.getNiveau() << std::endl;
	std::cout << "Exp : " << personnage.getEXP() << " / " << personnage.getExpMax() << "\n";
	std::cout << "Or : " << personnage.getArgent() << std::endl;
 	std::cout << "\n";
	std::cout << ennemie.getNom() << "			 | HP : " << ennemie.getHP() << "\n";
	std::cout << "--------------------- " << "\n";
	std::cout << "Que voulez-vous faire ?" << std::endl;
	std::cout << "1. Attaquer			 | Degats : " << personnage.getATK() << std::endl;
	std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
	std::cout << "3. Inventaire" << std::endl;
	std::cout << "--------------------- " << "\n";
	std::cout << "Compétences : " << "\n";
	if (personnage.getNom() == "Guerrier") {
		std::cout << "4. Coup Tranchant	 	 | Degats : " << monGuerrier.getDamage("CoupTranchant") << "			| MP : " << monGuerrier.getManaCost("CoupTranchant") << std::endl;
		std::cout << "5. Coup De Bouclier	 	 | Degats : " << monGuerrier.getDamage("CoupDeBouclier") << "			| MP : " << monGuerrier.getManaCost("CoupDeBouclier") << std::endl;
		if (personnage.getNiveau() >= 3) {
			std::cout << "6. Cri de guerre	 	 | Degats : " << monGuerrier.getDamage("CriDeGuerre") << "			| MP : " << monGuerrier.getManaCost("CriDeGuerre") << std::endl;
		}
	}
	if (personnage.getNom() == "Magicien") {
		std::cout << "4. Fire Bolt			 | Degats : " << monMagicien.getDamage("FireBolt") << "			| MP : " << monMagicien.getManaCost("FireBolt") << std::endl;
		std::cout << "5. Siphon			 | Degats : " << monMagicien.getDamage("Siphon") << "			| MP : " << monMagicien.getManaCost("Siphon") << std::endl;

		if (personnage.getNiveau() >= 4) {
			std::cout << "6. ThunderBolt			 | Degats : " << monMagicien.getDamage("ThunderBolt") << "			| MP : " << monMagicien.getManaCost("ThunderBolt") << std::endl;
		}
	}
	if (personnage.getNom() == "Voleur") {
		std::cout << "4. Coup Vampirique		 | Degats : " << monVoleur.getDamage("CoupVampirique") << "			| MP : " << monVoleur.getManaCost("CoupVampirique") << std::endl;
		std::cout << "5. Lame Empoisonnée		 | Degats : " << monVoleur.getDamage("LameEmpoisonnée") << "			| MP : " << monVoleur.getManaCost("LameEmpoisonnée") << std::endl;
	}
	if (personnage.getNom() == "Cleric") {
		std::cout << "4. Heal				 | Heal : " << monCleric.getDamage("Heal") << "			| MP : " << monCleric.getManaCost("Heal") << std::endl;
		std::cout << "5. Lumière Divine		 | Degats : " << monCleric.getDamage("LumièreDivine") << "			| MP : " << monCleric.getManaCost("LumièreDivine") << std::endl;
		if (personnage.getNiveau() >= 4) {
			std::cout << "6. Bénédiction	 	 | Degats : " << monCleric.getDamage("Benediction") << "			| MP : " << monCleric.getManaCost("Benediction") << std::endl;
		}
	}
	std::cout << "Votre choix : " << std::endl;
}

//Menu du marchant
void menuMarchant(Personnage& personnage) {
	Marchand marchand;
	std::cout << "Un marchand apparaît !" << std::endl;
	std::cout << "Or : " << personnage.getArgent() << std::endl;

	//Affiche l'inventaire du marchant
	marchand.afficherInventaire();
	bool choixValide = false;
	int choix;
	do {
		std::cin >> choix;
		std::cout << std::endl;
		if (std::cin.fail() || (choix < 1 || choix > 3)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Choix invalide. Veuillez saisir un choix valide.\n";
		}
		else {
			choixValide = true;
		}
	} while (!choixValide);

	switch (choix) { 
	case 1:
		system("cls");
		marchand.acheter(personnage, "Potion de HP");
		break;
	case 2:
		system("cls");
		marchand.acheter(personnage, "Potion de Mana");
		break;
	case 3:
		system("cls");
		std::cout << "Vous continuez votre aventure." << std::endl;
		break; 
	default:
		break;
	}
}

//Menu d'inventaire du personnage
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
		system("cls");
	}
}

//Menu de combat des personnages
void menuCombat(Personnage& personnage, Personnage& ennemi) {
	bool choixValide = false;
	int choix;
	do {
		std::cin >> choix;
		std::cout << std::endl;
		if (std::cin.fail() || (choix < 1 || choix > 7) || (choix == 7 && monMagicien.getNiveau() < 4)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Choix invalide. Veuillez saisir un choix valide.\n";
		}
		else {
			choixValide = true;
		}
	} while (!choixValide);
	system("cls");

	//Les capacités changent en fonction de la classe
	if (personnage.getNom() == "Guerrier") {
		switch (choix) {
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
			monGuerrier.CoupTranchant(ennemi);
			break;
		case 5:
			monGuerrier.CoupDeBouclier(ennemi);
			break;
		case 6:
			if (personnage.getNiveau() >= 3) {
				monGuerrier.criDeGuerre();
			}
			else {
				std::cout << "Ce sort n'est pas encore débloqué" << std::endl;
			}
		default:
			break;
		}
	}
	if (personnage.getNom() == "Magicien") {
		switch (choix) {
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
			monMagicien.FireBolt(ennemi);
			break;
		case 5:
			monMagicien.Siphon(ennemi);
			break;
		case 6:
			if (personnage.getNiveau() >= 4) {
			monMagicien.ThunderBolt(ennemi);;
		}
			  else {
			std::cout << "Ce sort n'est pas encore débloqué" << std::endl;
		}
			
			break;
		default:
			break;
		}
	}
	if (personnage.getNom() == "Voleur") {
		switch (choix) {
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
			monVoleur.CoupVampirique(ennemi);
			break;
		case 5:
			monVoleur.LameEmpoisonnée(ennemi);
			break;
		default:
			break;
		}
	}
	if (personnage.getNom() == "Cleric") {
		switch (choix) {
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
			monCleric.Heal(personnage);
			break;
		case 5:
			monCleric.LumièreDivine(ennemi);
			break;
		case 6:
			if (personnage.getNiveau() >= 4) {
			monCleric.Benediction(personnage);
			}
		default:
			break;
		}
	}
}


void combat(Personnage& personnage) {
	srand(static_cast<unsigned int>(time(nullptr)));
	
	//Initialise le loot des ennemis 
	std::vector<Item> listLootChauveSouris = { {"Aile", 1},{"Dent", 2},{"Peau", 1} };
	std::vector<Item> listLootGobelin = { {"Dague", 1},{"Bourse d'or", 2},{"Anneau", 1} };
	std::vector<Item> listLootTroll = { {"Massue", 1},{"Casque", 2},{"Bottes", 1}, {"Potion de HP", 1} };
	std::vector<Item> listLootBoss = { {"Nez", 1},{"Oreille", 2},{"Peau", 1}, {"Potion de HP", 2}, {"Potion de mana", 1} };
	int ennemisBattus = 0;
	int bossBattu = 0;
	int atkboss = 0;

	//Boucle de combat avec 25 combats avec une randomisation de 3 ennemis 
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

				// Ajouter le loot à l'inventaire du personnage
				personnage.addItem(objetLoot, goldMob);
				if (ennemisBattus % 5 == 0) {

					// Initialise le Boss
					std::string nomBoss = "SUPER GOLEM " + std::to_string(bossBattu + 1);
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
						atkboss++;
						if (atkboss == 3) {
							// Appel de la fonction pour le coup spécial du boss
							boss.superSmash(personnage);

							// Réinitialisation du compteur de tours depuis le dernier coup spécial
							atkboss = 0;
						}

						std::cout << "--------------------- " << "\n";
					}
					menuMarchant(personnage);
				}
				
			}
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
