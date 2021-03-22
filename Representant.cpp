#include "Representant.h"

Representant::Representant(string nom, string prenom, int age)
	: Commerciaux(nom, prenom, age, 5)
{
	resetDeplacements();
}

int Representant::getSalaire()
{
	return Employe::getSalaire() + getPrime() + 3 * nbDeplacements;
}
