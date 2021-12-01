#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include "Studentas_class.h"

Studentas::Studentas(std::ifstream& is)
{
	// kreipiasi ? Studentas::readStudent;
	readStudent(is);
}

double Studentas::Getbalas()
{
	double gal = 0.4 * ( std::accumulate(this->nd.begin(), this->nd.end(), 0.0) / this->nd.size() ) + 0.6 * this->egz;
	return gal;
}

void Studentas::readStudent(std::ifstream& is)
{
	is >> this->vardas >> this->pavarde;
	this->nd.reserve(8);
	for (int i = 0; i < 8; i++)
	{
		double sk;
		is >> sk;
		this->nd.push_back(sk);
	}
	is >> this->egz;
	//std::istream& readStudent(std::ifstream&, Studentas&);
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

/*
Studentas::~Studentas()
{
	this->nd.clear();
}
*/

