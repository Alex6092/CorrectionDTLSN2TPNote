#include <iostream>
using namespace std;

#include "Entreprise.h"

// Un beau commentaire :)
// Le deuxième commentaire ;)

int menu(Entreprise & e)
{
	cout << "Gestion de l'entreprise " << e.getRaisonSociale().c_str() << endl;
	cout << endl;
	cout << "1 - Ajouter un employe" << endl;
	cout << "2 - Modifier un employe" << endl;
	cout << "3 - Supprimer un employe" << endl;
	cout << "4 - Afficher les salaires" << endl;
	cout << "5 - Quitter" << endl;
	cout << endl;

	int choix = -1;
	while (choix < 1 || choix > 5)
	{
		cout << "Votre choix : ";
		cin >> choix;
	}

	return choix;
}

int getTypeEmploye()
{
	cout << "Quel type d'employe voulez vous ajouter ?" << endl;
	cout << "1 = Technicien ; 2 = Vendeur ; 3 = Representant ; 4 = Annuler" << endl;
	cout << endl;

	int choix = -1;
	while (choix < 1 || choix > 4)
	{
		cout << "Votre choix : ";
		cin >> choix;
	}

	return choix;
}

void afficheSalaires(Entreprise & entreprise)
{
	vector<Employe*> employes = entreprise.getAllEmployes();

	cout << "Salaire des employes :" << endl;
	cout << endl;

	for (int i = 0; i < employes.size(); i++)
	{	
		Employe * e = employes[i];
		cout << "Nom      : " << e->getNom().c_str() << endl;
		cout << "Prenom   : " << e->getPrenom().c_str() << endl;
		cout << "Age      : " << e->getAge() << endl;
		cout << "Salaire  : " << e->getSalaire() << endl;

		if (dynamic_cast<Commerciaux*>(e) != NULL)
		{
			cout << "Prime    : " << ((Commerciaux*)e)->getPrime() << endl;

			if (dynamic_cast<Representant*>(e) != NULL)
			{
				Representant * representant = (Representant*)e;
				cout << "Nb depl. : " << representant->getDeplacements() << endl;
				representant->resetDeplacements();
			}
		}

		cout << endl;
	}
}

int main(int argc, char ** argv)
{
	Entreprise entreprise("SNEntreprise");

	int choix = 0;

	while (choix != 5)
	{
		choix = menu(entreprise);
		cout << endl << endl;

		switch (choix)
		{
		case 1:
			{
				int typeEmploye = getTypeEmploye();

				if (typeEmploye >= 1 && typeEmploye <= 3)
				{
					EmployeType type;
					if (typeEmploye == 1)
						type = TECHNICIEN;
					else if (typeEmploye == 2)
						type = VENDEUR;
					else
						type = REPRESENTANT;

					if (entreprise.canAddEmploye(type))
					{

						string nom, prenom;
						int age;

						cout << "Nom de l'employe : ";
						cin >> nom;
						cout << "Prenom de l'employe : ";
						cin >> prenom;
						cout << "Age de l'employe : ";
						cin >> age;

						Employe * newEmploye = entreprise.addEmploye(nom, prenom, age, type);

						if (type == REPRESENTANT)
						{
							cout << "Avez vous un nombre de deplacement a saisir pour le nouveau representant ? (1=OUI , 0=NON)" << endl;
							int saisieDemandee;
							cin >> saisieDemandee;
							if (saisieDemandee == 1)
							{
								cout << "Nombre de deplacement a ajouter : ";
								int nbDeplacement;
								cin >> nbDeplacement;

								Representant * representant = (Representant*)newEmploye;
								representant->addDeplacements(nbDeplacement);
							}
						}
					}
					else
					{
						cout << "ERREUR - Le nombre maximum d'employe pour cette categorie a ete atteint !" << endl;
					}
				}
			}
			break;
		case 2:
			{
				string nom, prenom;
				cout << "Nom de l'employe : ";
				cin >> nom;
				cout << "Prenom de l'employe : ";
				cin >> prenom;

				Employe * e = entreprise.getEmploye(nom, prenom);
				if (e != NULL)
				{
					cout << "Employe trouve !" << endl;

					if (dynamic_cast<Representant*>(e) != NULL)
					{
						cout << "Voulez vous modifier les deplacements du representant ? (1=OUI ; 0=NON)" << endl;
						int saisieDemandee;
						cin >> saisieDemandee;
						if (saisieDemandee == 1)
						{
							cout << "Nombre de deplacement a ajouter : ";
							int nbDeplacement;
							cin >> nbDeplacement;

							Representant * representant = (Representant*)e;
							representant->addDeplacements(nbDeplacement);

							cout << "Nouveau nombre de deplacement : " << representant->getDeplacements() << endl;
						}
					}
				}
			}
			break;
		case 3:
			{
				string nom, prenom;
				cout << "Nom de l'employe : ";
				cin >> nom;
				cout << "Prenom de l'employe : ";
				cin >> prenom;

				if (entreprise.removeEmploye(nom, prenom))
				{
					cout << "Employe supprime" << endl;
				}
				else
				{
					cout << "L'employe n'a pas ete trouve" << endl;
				}
			}
			break;
		case 4:
			afficheSalaires(entreprise);
			break;
		}

		cout << endl << endl;
	}
	
	
	return 0;
}