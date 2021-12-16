#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include "Studentas_class.h"

/// Nuskaitymo is failo konstruktorius, besikreipiantis i skaitymo is failo funkcija readStudent.
Studentas::Studentas(std::istream& is)
{
	readStudent(is);
}

/// Kopijavimo konstruktorius.
Studentas::Studentas(const Studentas& naujas)
{
	vardas = naujas.Getvardas();
	pavarde = naujas.Getpavarde();
	nd.reserve(naujas.nd.size());
	std::copy(naujas.nd.begin(), naujas.nd.end(), std::back_inserter(nd));
	egz = naujas.Getegz();
};

/// Galutinio balo skaiciuokle.
/// @returns Grazina suskaiciuota galututini studento pazymi
double Studentas::Getbalas()
{
	double gal = 0.4 * ( std::accumulate(this->nd.begin(), this->nd.end(), 0.0) / this->nd.size() ) + 0.6 * egz;
	return gal;
}

/// Nuskaitymo is failo funkcija.
void Studentas::readStudent(std::istream& is)
{
	is >> this->vardas >> this->pavarde;
	this->nd.reserve(8);
	for (int i = 0; i < 8; i++)
	{
		double sk;
		is >> sk;
		this->nd.push_back(sk);
	}
	is >> egz;
}

/// Kopijavimo (apkeitimo (swap) metodu realizuota) funkcija.
void Studentas::keisk(Studentas& kopija)
{
	swap(vardas, kopija.vardas);
	swap(pavarde, kopija.pavarde);
	swap(nd, kopija.nd);
	std::swap(egz, kopija.egz);
}

bool compare(Studentas& v1, Studentas& v2)
{
	double balas1 = v1.Getbalas();
	double balas2 = v2.Getbalas();

	if (balas1 > balas2) { return true; }
	else if (balas1 < balas2) { return false; }
	else
	{
		if (v1.Getpavarde() > v2.Getpavarde()) { return true; }
		else if (v1.Getpavarde() < v2.Getpavarde()) { return false; }
	}
}

/// Kopijavimo priskyrimo operatorius.
Studentas& Studentas::operator = (Studentas kopija)
{	
	keisk(kopija);
	return *this;
}

/// Destruktorius.
Studentas::~Studentas()
{
	nd.clear();
}



