#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

#include "Asmuo.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Studentas : public Asmuo
{
protected:
	vector<double> nd;
	double egz;
public:
	Studentas() : egz(0) { nd.clear(); }
	Studentas(std::istream&);
	Studentas(const Studentas&);
	Studentas(string var, string pav, vector <double> nam, double e) : Asmuo{ var, pav }, nd(nam), egz(e) {}

	Studentas& operator = (Studentas);
	~Studentas();
	string Getvardas() const{ return vardas; }
	string Getpavarde() const{ return pavarde; }
	vector <double> Getnd() const { return nd; }
	void kas_as() { cout << "Isvestines klases objektas" << vardas << endl; };
	inline double Getegz() const { return egz ; }

	double Getbalas();
	void readStudent(std::istream&);
	void keisk(Studentas& kopija);
};

bool compare(Studentas&, Studentas&);