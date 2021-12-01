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
	double egz;
	vector<double> nd;

public:
	Studentas() : egz(0) { }  // default konstruktorius
	Studentas(std::ifstream& is);
	inline string Getvardas() const { return vardas; }    // get'eriai, inline
	inline string Getpavarde() const { return pavarde; }  // get'eriai, inline
	double Getbalas();
	void readStudent(std::ifstream&);  // set'eriai
	//~Studentas();
};

bool compare(Studentas&, Studentas&);