#pragma once
#include "Commerciaux.h"
class Representant :
	public Commerciaux
{
	int nbDeplacements;

public:
	Representant(string nom, string prenom, int age);
	inline void addDeplacements(int n) { nbDeplacements += n; }
	inline int getDeplacements() { return nbDeplacements; }
	inline void resetDeplacements() { nbDeplacements = 0; }
	virtual int getSalaire();
};

