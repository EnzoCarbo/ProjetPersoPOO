#include<iostream>
#include <cstdlib>
#include <iomanip>
#include"guerrier.h"
#include"magicien.h"
#include"voleur.h"
#include"cleric.h"



//TO DO
//Eviter redondance (func combat)
//Equilibrage
//Sort du Guerrier
//Sort sp�cial pour le Boss ?
//Potion de Mana

//Faire en sorte de pas perdre un tour quand utilise un input faux dans les menu combat
//HUD G C V
//D�bloque capacit� au niveau 4 ?


Magicien monMagicien("Magicien", 1, 700, 700, 5, 20, 4, 0, 100, 100, 100);
Voleur monVoleur("Voleur", 1, 1000, 1000, 6, 15, 12, 0, 100, 80, 80);
Cleric monCleric("Cleric", 1, 1000, 1000, 6, 15, 12, 0, 100, 80, 80);

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

// Combat avec une personnage Guerrier
void mainGuerrier() {

	//Initialise un Guerrier avec un constructeur
	Guerrier monGuerrier("Guerrier", 1, 1, 1200, 20, 1, 8, 0, 100, 20, 20);

	//Variable pour faire des combats � la chaine et nommer les ennemies
	int ennemisBattus = 0;
	int bossBattu = 0;

	//Boucle de combat avec 25 combats
	for (int i = 1; i <= 25; i++) {

		//Le nom de l'ennemi augmente de 1 avec i++
		std::string nomGobelin = "Gobelin " + std::to_string(i);

		//Initialise un ennemi avec un Constructeur (nom, hp, atk)
		Personnage ennemi(nomGobelin, 50 + i * 20, 20 + i * 5);
		std::cout << "--------------------- " << "\n";
		std::cout << "Combat entre " << monGuerrier.getNom() << " et " << ennemi.getNom() << " !\n";

		//Boucle de combat tant que mon perso ou l'aderversaire est en vie
		while (monGuerrier.EstVivant() && ennemi.EstVivant()) {
			std::cout << monGuerrier.getNom() << "			 | HP : " << monGuerrier.getHP() << "			| Mana : " << monGuerrier.getMana() << "\n";
			std::cout << "Exp : " << monGuerrier.getEXP() << " / " << monGuerrier.getExpMax() << "\n";
			std::cout << "\n";
			std::cout << ennemi.getNom() << "			 | HP : " << ennemi.getHP() << "\n";
			std::cout << "--------------------- " << "\n";
			std::cout << "Que voulez-vous faire ?" << std::endl;
			std::cout << "1. Attaquer			 | Degats : " << monGuerrier.getATK() << std::endl;
			std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
			std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monGuerrier.getQuantit�Potions() << std::endl;
			std::cout << "--------------------- " << "\n";
			std::cout << "Comp�tences : " << "\n";
			std::cout << "4. Coup Tranchant	 	 | Degats : " << monGuerrier.getDamage("CoupTranchant") << "			| MP : " << monGuerrier.getManaCost("CoupTranchant") << std::endl;
			std::cout << "5. Coup De Bouclier	 	 | Degats : " << monGuerrier.getDamage("CoupDeBouclier") << "			| MP : " << monGuerrier.getManaCost("CoupDeBouclier") << std::endl;
			std::cout << "Votre choix : ";

			//Menu d'attaque pour le guerrier envers le gobelin
			int choix;
			std::cin >> choix;
			std::cout << std::endl;
			if (choix == 1) {
				system("cls");
				monGuerrier.attaque(ennemi);
			}
			else if (choix == 2) {
				system("cls");
				monGuerrier.Defense();
			}
			else if (choix == 3) {
				system("cls");
				monGuerrier.utiliserPotion();
			}
			else if (choix == 4) {
				system("cls");
				monGuerrier.CoupTranchant(ennemi);
			}
			else if (choix == 5) {
				system("cls");
				monGuerrier.CoupDeBouclier(ennemi);
			}
			else {
				std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
				continue;
			}
			//Le gobelin attaque
			ennemi.attaque(monGuerrier);
			std::cout << "--------------------- " << "\n";
			
			//Si le gobelin meurt donne de l'experience et augmente la difficult�e
			if (!ennemi.EstVivant()) {
				monGuerrier.gagnerEXP(50 + i * (10 * i));
				ennemisBattus++;
				if (ennemisBattus % 5 == 0) {

					// Initialise le Boss
					std::string nomBoss = "Boss " + std::to_string(bossBattu + 1);
					Personnage boss(nomBoss, 500, 200);
					std::cout << "--------------------- " << "\n";
					std::cout << "Combat entre " << monGuerrier.getNom() << " et " << boss.getNom() << " !\n";

					// Tant que le personnage ou le boss est en vie, le combat continue
					while (monGuerrier.EstVivant() && boss.EstVivant()) {
						std::cout << monGuerrier.getNom() << "			 | HP : " << monGuerrier.getHP() << "			| Mana : " << monGuerrier.getMana() << "\n";
						std::cout << "Exp : " << monGuerrier.getEXP() << " / " << monGuerrier.getExpMax() << "\n";
						std::cout << "\n";
						std::cout << boss.getNom() << "				 | HP : " << boss.getHP() << "\n";
						std::cout << "--------------------- " << "\n";
						std::cout << "Que voulez-vous faire ?" << std::endl;
						std::cout << "1. Attaquer			 | Degats : " << monGuerrier.getATK() << std::endl;
						std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
						std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monGuerrier.getQuantit�Potions() << std::endl;
						std::cout << "--------------------- " << "\n";
						std::cout << "Comp�tences : " << "\n";
						std::cout << "4. Coup Tranchant		  | Degats : " << monGuerrier.getDamage("CoupTranchant") << "			| MP : " << monGuerrier.getManaCost("CoupTranchant") << std::endl;
						std::cout << "5. Coup De Bouclier		  | Degats : " << monGuerrier.getDamage("CoupDeBouclier") << "			| MP : " << monGuerrier.getManaCost("CoupDeBouclier") << std::endl;
						std::cout << "Votre choix : ";

						// Menu d'attaque du Guerrier contre le Boss
						int choix;
						std::cin >> choix;
						std::cout << std::endl;
						if (choix == 1) {
							system("cls");
							monGuerrier.attaque(boss);
						}
						else if (choix == 2) {
							system("cls");
							monGuerrier.Defense();
						}
						else if (choix == 3) {
							system("cls");
							monGuerrier.utiliserPotion();
						}
						else if (choix == 4) {
							system("cls");
							monGuerrier.CoupTranchant(boss);
						}
						else if (choix == 5) {
							system("cls");
							monGuerrier.CoupDeBouclier(boss);
						}
						else {
							std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
							continue;
						}


						// Mort du Boss donne de l'exp�rience et augmente le compteur de 1
						if (!boss.EstVivant()) {
							monGuerrier.gagnerEXP(150 + i * (10 * i));
							std::cout << "Le " << boss.getNom() << " est Mort !\n";
							bossBattu++;
							break;
						}

						// Attaque du Boss
						boss.attaque(monGuerrier);
						std::cout << "--------------------- " << "\n";
					}
				}
			}	
		}
		// Sort de la boucle combat en cas de mort et retourne au menu
		if (!monGuerrier.EstVivant()) {
			std::cout << "Vous �tes mort" << std::endl;
			break;
		}
	}
}

// Combat avec une personnage Magicien
void mainMagicien() {

	//Initialise un Magicien avec un constructeur
	Magicien monMagicien("Magicien", 1, 7100, 7100, 5, 20, 4, 0, 100, 10000, 10000);

	//Variable pour faire des combats � la chaine et nommer les ennemies
	int ennemisBattus = 0;
	int bossBattu = 0;

	//Boucle de combat avec 25 combats
	for (int i = 1; i <= 25; i++) {

		//Le nom de l'ennemi augmente de 1 avec i++
		std::string nomGobelin = "Gobelin " + std::to_string(i);

		//Initialise un ennemi avec un Constructeur (nom, hp, atk)
		Personnage ennemi(nomGobelin, 50 + i * 20, 20 + i * 5);
		std::cout << "--------------------- " << "\n";
		std::cout << "Combat entre " << monMagicien.getNom() << " et " << ennemi.getNom() << " !\n";

		//Boucle de combat tant que mon perso ou l'aderversaire est en vie
		while (monMagicien.EstVivant() && ennemi.EstVivant()) {
			std::cout << monMagicien.getNom() << "			 | HP : " << monMagicien.getHP() << "			| Mana : " << monMagicien.getMana() << "\n";
			std::cout << "Exp : " << monMagicien.getEXP() << " / " << monMagicien.getExpMax() << "\n";
			std::cout << "\n";
			std::cout << ennemi.getNom() << "			 | HP : " << ennemi.getHP() << "\n";
			std::cout << "--------------------- " << "\n";
			std::cout << "Que voulez-vous faire ?" << std::endl;
			std::cout << "1. Attaquer			 | Degats : " << monMagicien.getATK() << std::endl;
			std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
			std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monMagicien.getQuantit�Potions() << std::endl;
			std::cout << "--------------------- " << "\n";
			std::cout << "Comp�tences : " << "\n";
			std::cout << "4. Fire Bolt			 | Degats : " << monMagicien.getDamage("FireBolt") << "			| MP : " << monMagicien.getManaCost("FireBolt") << std::endl;
			std::cout << "5. Siphon			 | Degats : " << monMagicien.getDamage("Siphon") << "			| MP : " << monMagicien.getManaCost("Siphon") << std::endl;
			std::cout << "Votre choix : ";

			//Menu d'attaque pour le Magicien envers le gobelin
			int choix;
			std::cin >> choix;
			std::cout << std::endl;
			if (choix == 1) {
				system("cls");
				monMagicien.attaque(ennemi);
			}
			else if (choix == 2) {
				system("cls");
				monMagicien.Defense();
			}
			else if (choix == 3) {
				system("cls");
				monMagicien.utiliserPotion();
			}
			else if (choix == 4) {
				system("cls");
				monMagicien.FireBolt(ennemi);
			}
			else if (choix == 5) {
				system("cls");
				monMagicien.Siphon(ennemi);
			}
			else {
				std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
				continue;
			}
			//Le gobelin attaque
			ennemi.attaque(monMagicien);
			std::cout << "--------------------- " << "\n";

			//Si le gobelin meurt donne de l'experience et augmente la difficult�e
			if (!ennemi.EstVivant()) {
				monMagicien.gagnerEXP(50 + i * (10 * i));
				ennemisBattus++;
				if (ennemisBattus % 5 == 0) {

					// Initialise le Boss
					std::string nomBoss = "Boss " + std::to_string(bossBattu + 1);
					Personnage boss(nomBoss, 500, 200);
					std::cout << "--------------------- " << "\n";
					std::cout << "Combat entre " << monMagicien.getNom() << " et " << boss.getNom() << " !\n";

					// Tant que le personnage ou le boss est en vie, le combat continue
					while (monMagicien.EstVivant() && boss.EstVivant()) {
						std::cout << monMagicien.getNom() << "			 | HP : " << monMagicien.getHP() << "			| Mana : " << monMagicien.getMana() << "\n";
						std::cout << "Exp : " << monMagicien.getEXP() << " / " << monMagicien.getExpMax() << "\n";
						std::cout << "\n";
						std::cout << boss.getNom() << "				 | HP : " << boss.getHP() << "\n";
						std::cout << "--------------------- " << "\n";
						std::cout << "Que voulez-vous faire ?" << std::endl;
						std::cout << "1. Attaquer			 | Degats : " << monMagicien.getATK() << std::endl;
						std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
						std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monMagicien.getQuantit�Potions() << std::endl;
						std::cout << "--------------------- " << "\n";
						std::cout << "Comp�tences : " << "\n";
						std::cout << "4. Fire Bolt			 | Degats : " << monMagicien.getDamage("FireBolt") << "			| MP : " << monMagicien.getManaCost("FireBolt") << std::endl;
						std::cout << "5. Siphon			 | Degats : " << monMagicien.getDamage("Siphon") << "			| MP : " << monMagicien.getManaCost("Siphon") << std::endl;
						std::cout << "Votre choix : ";

						// Menu d'attaque du Magicien contre le Boss
						int choix;
						std::cin >> choix;
						std::cout << std::endl;
						if (choix == 1) {
							system("cls");
							monMagicien.attaque(boss);
						}
						else if (choix == 2) {
							system("cls");
							monMagicien.Defense();
						}
						else if (choix == 3) {
							system("cls");
							monMagicien.utiliserPotion();
						}
						else if (choix == 4) {
							system("cls");
							monMagicien.FireBolt(boss);
						}
						else if (choix == 5) {
							system("cls");
							monMagicien.Siphon(boss);
						}
						else {
							std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
							continue;
						}


						// Mort du Boss donne de l'exp�rience et augmente le compteur de 1
						if (!boss.EstVivant()) {
							monMagicien.gagnerEXP(150 + i * (10 * i));
							std::cout << "Le " << boss.getNom() << " est Mort !\n";
							bossBattu++;
							break;
						}

						// Attaque du Boss
						boss.attaque(monMagicien);
						std::cout << "--------------------- " << "\n";
					}
				}
			}
		}
		// Sort de la boucle combat en cas de mort et retourne au menu
		if (!monMagicien.EstVivant()) {
			std::cout << "Vous �tes mort" << std::endl;
			break;
		}
	}
}

// Combat avec une personnage Voleur
void mainVoleur() {

	//Initialise un Voleur avec un constructeur
	Voleur monVoleur("Voleur", 1, 1000, 1000, 6, 15, 12, 0, 100, 80, 80);

	//Variable pour faire des combats � la chaine et nommer les ennemies
	int ennemisBattus = 0;
	int bossBattu = 0;

	//Boucle de combat avec 25 combats
	for (int i = 1; i <= 25; i++) {

		//Le nom de l'ennemi augmente de 1 avec i++
		std::string nomGobelin = "Gobelin " + std::to_string(i);

		//Initialise un ennemi avec un Constructeur (nom, hp, atk)
		Personnage ennemi(nomGobelin, 50 + i * 20, 20 + i * 5);
		std::cout << "--------------------- " << "\n";
		std::cout << "Combat entre " << monVoleur.getNom() << " et " << ennemi.getNom() << " !\n";

		//Boucle de combat tant que mon perso ou l'aderversaire est en vie
		while (monVoleur.EstVivant() && ennemi.EstVivant()) {
			std::cout << monVoleur.getNom() << "				 | HP : " << monVoleur.getHP() << "			| Mana : " << monVoleur.getMana() << "\n";
			std::cout << "Exp : " << monVoleur.getEXP() << " / " << monVoleur.getExpMax() << "\n";
			std::cout << "\n";
			std::cout << ennemi.getNom() << "			 | HP : " << ennemi.getHP() << "\n";
			std::cout << "--------------------- " << "\n";
			std::cout << "Que voulez-vous faire ?" << std::endl;
			std::cout << "1. Attaquer			 | Degats : " << monVoleur.getATK() << std::endl;
			std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
			std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monVoleur.getQuantit�Potions() << std::endl;
			std::cout << "--------------------- " << "\n";
			std::cout << "Comp�tences : " << "\n";
			std::cout << "4. Coup Vampirique	 	 | Degats : " << monVoleur.getDamage("CoupVampirique") << "			| MP : " << monVoleur.getManaCost("CoupVampirique") << std::endl;
			std::cout << "5. Lame Empoisonn�e		 | Degats : " << monVoleur.getDamage("LameEmpoisonn�e") << "			| MP : " << monVoleur.getManaCost("LameEmpoisonn�e") << std::endl;
			std::cout << "Votre choix : ";

			//Menu d'attaque pour le Voleur envers le gobelin
			int choix;
			std::cin >> choix;
			std::cout << std::endl;
			if (choix == 1) {
				system("cls");
				monVoleur.attaque(ennemi);
			}
			else if (choix == 2) {
				system("cls");
				monVoleur.Defense();
			}
			else if (choix == 3) {
				system("cls");
				monVoleur.utiliserPotion();
			}
			else if (choix == 4) {
				system("cls");
				monVoleur.CoupVampirique(ennemi);
			}
			else if (choix == 5) {
				system("cls");
				monVoleur.LameEmpoisonn�e(ennemi);
			}
			else {
				std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
				continue;
			}
			//Le gobelin attaque
			ennemi.attaque(monVoleur);
			std::cout << "--------------------- " << "\n";

			//Si le gobelin meurt donne de l'experience et augmente la difficult�e
			if (!ennemi.EstVivant()) {
				monVoleur.gagnerEXP(50 + i * (10 * i));
				ennemisBattus++;
				if (ennemisBattus % 5 == 0) {

					// Initialise le Boss
					std::string nomBoss = "Boss " + std::to_string(bossBattu + 1);
					Personnage boss(nomBoss, 500, 200);
					std::cout << "--------------------- " << "\n";
					std::cout << "Combat entre " << monVoleur.getNom() << " et " << boss.getNom() << " !\n";

					// Tant que le personnage ou le boss est en vie, le combat continue
					while (monVoleur.EstVivant() && boss.EstVivant()) {
						std::cout << monVoleur.getNom() << "				 | HP : " << monVoleur.getHP() << "			| Mana : " << monVoleur.getMana() << "\n";
						std::cout << "Exp : " << monVoleur.getEXP() << " / " << monVoleur.getExpMax() << "\n";
						std::cout << "\n";
						std::cout << boss.getNom() << "				 | HP : " << boss.getHP() << "\n";
						std::cout << "--------------------- " << "\n";
						std::cout << "Que voulez-vous faire ?" << std::endl;
						std::cout << "1. Attaquer			 | Degats : " << monVoleur.getATK() << std::endl;
						std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
						std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monVoleur.getQuantit�Potions() << std::endl;
						std::cout << "--------------------- " << "\n";
						std::cout << "Comp�tences : " << "\n";
						std::cout << "4. Coup Vampirique		 | Degats : " << monVoleur.getDamage("CoupVampirique") << "			| MP : " << monVoleur.getManaCost("CoupVampirique") << std::endl;
						std::cout << "5. Lame Empoisonn�e		 | Degats : " << monVoleur.getDamage("LameEmpoisonn�e") << "			| MP : " << monVoleur.getManaCost("LameEmpoisonn�e") << std::endl;
						std::cout << "Votre choix : ";

						// Menu d'attaque du Voleur contre le Boss
						int choix;
						std::cin >> choix;
						std::cout << std::endl;
						if (choix == 1) {
							system("cls");
							monVoleur.attaque(boss);
						}
						else if (choix == 2) {
							system("cls");
							monVoleur.Defense();
						}
						else if (choix == 3) {
							system("cls");
							monVoleur.utiliserPotion();
						}
						else if (choix == 4) {
							system("cls");
							monVoleur.CoupVampirique(boss);
						}
						else if (choix == 5) {
							system("cls");
							monVoleur.LameEmpoisonn�e(boss);
						}
						else {
							std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
							continue;
						}


						// Mort du Boss donne de l'exp�rience et augmente le compteur de 1
						if (!boss.EstVivant()) {
							monVoleur.gagnerEXP(150 + i * (10 * i));
							std::cout << "Le " << boss.getNom() << " est Mort !\n";
							bossBattu++;
							break;
						}

						// Attaque du Boss
						boss.attaque(monVoleur);
						std::cout << "--------------------- " << "\n";
					}
				}
			}
		}
		// Sort de la boucle combat en cas de mort et retourne au menu
		if (!monVoleur.EstVivant()) {
			std::cout << "Vous �tes mort" << std::endl;
			break;
		}
	}
}

// Combat avec une personnage Cleric
void mainCleric() {

	//Initialise un Cleric avec un constructeur
	Cleric monCleric("Cleric", 1, 1000, 1000, 6, 15, 12, 0, 100, 80, 80);

	//Variable pour faire des combats � la chaine et nommer les ennemies
	int ennemisBattus = 0;
	int bossBattu = 0;

	//Boucle de combat avec 25 combats
	for (int i = 1; i <= 25; i++) {

		//Le nom de l'ennemi augmente de 1 avec i++
		std::string nomGobelin = "Gobelin " + std::to_string(i);

		//Initialise un ennemi avec un Constructeur (nom, hp, atk)
		Personnage ennemi(nomGobelin, 50 + i * 20, 20 + i * 5);
		std::cout << "--------------------- " << "\n";
		std::cout << "Combat entre " << monCleric.getNom() << " et " << ennemi.getNom() << " !\n";

		//Boucle de combat tant que mon perso ou l'aderversaire est en vie
		while (monCleric.EstVivant() && ennemi.EstVivant()) {
			std::cout << monCleric.getNom() << "				 | HP : " << monCleric.getHP() << "			| Mana : " << monCleric.getMana() << "\n";
			std::cout << "Exp : " << monCleric.getEXP() << " / " << monCleric.getExpMax() << "\n";
			std::cout << "\n";
			std::cout << ennemi.getNom() << "			 | HP : " << ennemi.getHP() << "\n";
			std::cout << "--------------------- " << "\n";
			std::cout << "Que voulez-vous faire ?" << std::endl;
			std::cout << "1. Attaquer			 | Degats : " << monCleric.getATK() << std::endl;
			std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
			std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monCleric.getQuantit�Potions() << std::endl;
			std::cout << "--------------------- " << "\n";
			std::cout << "Comp�tences : " << "\n";
			std::cout << "4. Heal				 | Heal : " << monCleric.getDamage("Heal") << "			| MP : " << monCleric.getManaCost("Heal") << std::endl;
			std::cout << "5. Lumi�re Divine		 | Degats : " << monCleric.getDamage("Lumi�reDivine") << "			| MP : " << monCleric.getManaCost("Lumi�reDivine") << std::endl;
			std::cout << "Votre choix : ";

			//Menu d'attaque pour le Cleric envers le gobelin
			int choix;
			std::cin >> choix;
			std::cout << std::endl;
			if (choix == 1) {
				system("cls");
				monCleric.attaque(ennemi);
			}
			else if (choix == 2) {
				system("cls");
				monCleric.Defense();
			}
			else if (choix == 3) {
				system("cls");
				monCleric.utiliserPotion();
			}
			else if (choix == 4) {
				system("cls");
				monCleric.Heal(ennemi);
			}
			else if (choix == 5) {
				system("cls");
				monCleric.Lumi�reDivine(ennemi);
			}
			else {
				std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
				continue;
			}
			//Le gobelin attaque
			ennemi.attaque(monCleric);
			std::cout << "--------------------- " << "\n";

			//Si le gobelin meurt donne de l'experience et augmente la difficult�e
			if (!ennemi.EstVivant()) {
				monCleric.gagnerEXP(150 + i * (10 * i));
				ennemisBattus++;
				if (ennemisBattus % 5 == 0) {

					// Initialise le Boss
					std::string nomBoss = "Boss " + std::to_string(bossBattu + 1);
					Personnage boss(nomBoss, 500, 200);
					std::cout << "--------------------- " << "\n";
					std::cout << "Combat entre " << monCleric.getNom() << " et " << boss.getNom() << " !\n";

					// Tant que le personnage ou le boss est en vie, le combat continue
					while (monCleric.EstVivant() && boss.EstVivant()) {
						std::cout << monCleric.getNom() << "				 | HP : " << monCleric.getHP() << "			| Mana : " << monCleric.getMana() << "\n";
						std::cout << "Exp : " << monCleric.getEXP() << " / " << monCleric.getExpMax() << "\n";
						std::cout << "\n";
						std::cout << boss.getNom() << "				| HP : " << boss.getHP() << "\n";
						std::cout << "--------------------- " << "\n";
						std::cout << "Que voulez-vous faire ?" << std::endl;
						std::cout << "1. Attaquer			 | Degats : " << monCleric.getATK() << std::endl;
						std::cout << "2. Se mettre en position defense | Degats recus /2" << std::endl;
						std::cout << "3. Utiliser Potion de HP	 | HP + 200			| Quantit� : " << monCleric.getQuantit�Potions() << std::endl;
						std::cout << "--------------------- " << "\n";
						std::cout << "Comp�tences : " << "\n";
						std::cout << "4. Heal				 | Heal : " << monCleric.getDamage("Heal") << "			| MP : " << monCleric.getManaCost("Heal") << std::endl;
						std::cout << "5. Lumi�re Divine		 | Degats : " << monCleric.getDamage("Lumi�reDivine") << "			| MP : " << monCleric.getManaCost("Lumi�reDivine") << std::endl;
						std::cout << "Votre choix : ";

						// Menu d'attaque du Cleric contre le Boss
						int choix;
						std::cin >> choix;
						std::cout << std::endl;
						if (choix == 1) {
							system("cls");
							monCleric.attaque(boss);
						}
						else if (choix == 2) {
							system("cls");
							monCleric.Defense();
						}
						else if (choix == 3) {
							system("cls");
							monCleric.utiliserPotion();
						}
						else if (choix == 4) {
							system("cls");
							monCleric.Heal(boss);
						}
						else if (choix == 5) {
							system("cls");
							monCleric.Lumi�reDivine(boss);
						}
						else {
							std::cout << "Choix invalide. Veuillez saisir 1 pour attaquer, 2 pour se d�fendre, 3 pour utiliser une potion, ou 4 pour la comp�tence sp�ciale.\n";
							continue;
						}


						// Mort du Boss donne de l'exp�rience et augmente le compteur de 1
						if (!boss.EstVivant()) {
							monCleric.gagnerEXP(150 + i * (10 * i));
							std::cout << "Le " << boss.getNom() << " est Mort !\n";
							bossBattu++;
							break;
						}

						// Attaque du Boss
						boss.attaque(monCleric);
						std::cout << "--------------------- " << "\n";
					}
				}
			}
		}
		// Sort de la boucle combat en cas de mort et retourne au menu
		if (!monCleric.EstVivant()) {
			std::cout << "Vous �tes mort" << std::endl;
			break;
		}
	}
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
			mainGuerrier();
			break;
		case 2:
			system("cls");
			mainMagicien();
			break;
		case 3:
			system("cls");
			mainVoleur();
			break;
		case 4:
			system("cls");
			mainCleric();
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