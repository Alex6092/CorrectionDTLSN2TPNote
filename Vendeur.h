#pragma once
#include "Commerciaux.h"
class Vendeur :
	public Commerciaux
{
public:
	Vendeur(string nom, string prenom, int age);
	virtual int getSalaire();
};

