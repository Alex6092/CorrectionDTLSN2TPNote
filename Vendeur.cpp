#include "Vendeur.h"

Vendeur::Vendeur(string nom, string prenom, int age)
	: Commerciaux(nom, prenom, age, 2)
{
}

int Vendeur::getSalaire()
{
	return Employe::getSalaire() + getPrime();
}
