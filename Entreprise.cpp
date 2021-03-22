#include "Entreprise.h"
#include <algorithm>

Entreprise::Entreprise(string raisonSociale)
{
	this->raisonSociale = raisonSociale;
}

Employe * Entreprise::addEmploye(string nom, string prenom, int age, EmployeType type)
{
	Employe * e = NULL;
	if (canAddEmploye(type) && getEmploye(nom, prenom) == NULL)
	{
		switch (type)
		{
			case TECHNICIEN:
				e = new Technicien(nom, prenom, age);
				techniciens.push_back((Technicien*)e);
				break;

			case REPRESENTANT:
				e = new Representant(nom, prenom, age);
				commerciaux.push_back((Representant*)e);
				break;

			case VENDEUR:
				e = new Vendeur(nom, prenom, age);
				commerciaux.push_back((Vendeur*)e);
				break;

			default:
				e = NULL;
				break;
		}
	}

	return e;
}

bool Entreprise::canAddEmploye(EmployeType type)
{
	switch (type)
	{
	case TECHNICIEN:
		return techniciens.size() < 10;
		break;

	case REPRESENTANT:
		return commerciaux.size() < 10;
		break;

	case VENDEUR:
		return commerciaux.size() < 10;
		break;
	}

	return false;
}

Employe * Entreprise::getEmploye(string nom, string prenom)
{
	for (int i = 0; i < techniciens.size(); i++)
	{
		Employe * e = techniciens[i];
		if (e->getNom() == nom && e->getPrenom() == prenom)
			return e;
	}

	for (int i = 0; i < commerciaux.size(); i++)
	{
		Employe * e = commerciaux[i];
		if (e->getNom() == nom && e->getPrenom() == prenom)
			return e;
	}

	return NULL;
}

vector<Employe*> Entreprise::getAllEmployes()
{
	vector<Employe*> result;
	result.insert(result.begin(), techniciens.begin(), techniciens.end());
	result.insert(result.end(), commerciaux.begin(), commerciaux.end());
	return result;
}

bool Entreprise::removeEmploye(string nom, string prenom)
{
	Employe * e = getEmploye(nom, prenom);
	
	if (e != NULL)
	{
		if (dynamic_cast<Technicien*>(e) != NULL)
		{
			Technicien * t = (Technicien*)e;
			vector<Technicien*>::iterator it = find(techniciens.begin(), techniciens.end(), t);
			if (it != techniciens.end())
			{
				techniciens.erase(it);
				return true;
			}
		}
		else
		{
			Commerciaux * c = (Commerciaux*)e;
			auto it = find(commerciaux.begin(), commerciaux.end(), c);
			if (it != commerciaux.end())
			{
				commerciaux.erase(it);
				return true;
			}
		}
	}

	return false;
}
