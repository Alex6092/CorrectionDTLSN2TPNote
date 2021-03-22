#include "Commerciaux.h"

Commerciaux::Commerciaux(string nom, string prenom, int age, int prime)
	: Employe(nom, prenom, age, 50)
{
	this->prime = prime;
}
