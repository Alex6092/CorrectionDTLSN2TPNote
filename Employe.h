#pragma once

#include <vector>
#include <string>

using namespace std;

enum EmployeType
{
	TECHNICIEN,
	REPRESENTANT,
	VENDEUR
};

class Employe
{
	string nom, prenom;
	int age, salaireBase;

public:
	Employe(string nom, string prenom, int age, int salaireBase);
	inline string getNom() { return nom; }
	inline string getPrenom() { return prenom; }
	inline int getAge() { return age; }
	virtual int getSalaire() { return salaireBase; }
};

