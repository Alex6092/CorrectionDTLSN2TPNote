#pragma once
#include "Employe.h"

class Commerciaux :
	public Employe
{
	int prime;
public:
	Commerciaux(string nom, string prenom, int age, int prime);
	inline int getPrime() { return prime; }
};