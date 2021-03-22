#pragma once

#include "Technicien.h"
#include "Commerciaux.h"
#include "Representant.h"
#include "Vendeur.h"
#include <vector>
#include <string>

class Entreprise
{
	string raisonSociale;
	vector<Commerciaux*> commerciaux;
	vector<Technicien*> techniciens;

public:
	Entreprise(string raisonSociale);
	Employe * addEmploye(string nom, string prenom, int age, EmployeType type);
	bool canAddEmploye(EmployeType type);
	Employe * getEmploye(string nom, string prenom);
	vector<Employe*> getAllEmployes();
	string getRaisonSociale() { return raisonSociale; }

	bool removeEmploye(string nom, string prenom);
};

