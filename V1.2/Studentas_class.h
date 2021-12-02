#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using std::string;

class Studentas {

private:
	string vardas;
	string pavarde;
	vector<double> nd;
	double egz;

public:
	Studentas() : egz(0) { }
	Studentas(std::istream&);
	Studentas(const Studentas&);

	Studentas& operator = (Studentas);
	~Studentas();

	inline string Getvardas() const { return vardas; }
	inline string Getpavarde() const { return pavarde; }
	inline double Getegz() const { return egz ; }
	double Getbalas();
	void readStudent(std::istream&);
	void keisk(Studentas& kopija);
};

bool compare(Studentas&, Studentas&);