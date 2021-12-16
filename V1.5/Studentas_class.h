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

///Studento klase.
///
/// Prie bazines klases 'Asmuo' paveldetu kintamuju, sauganciu studento varda ir pavarde, prijungiami namu darbu bei egzamino ivertinimai.
/// Realizuoti informacijos isgavimo (get'eriai), galutinio balo skaiciavimo metodai.
class Studentas : public Asmuo
{
protected:
	vector<double> nd;
	double egz;
public:
	/// Numatytasis konstruktorius.
	Studentas() : egz(0) { nd.clear(); }
	Studentas(std::istream&);
	Studentas(const Studentas&);
	Studentas(string var, string pav) : Asmuo{ var, pav }, egz(0) {nd.clear();}

	Studentas& operator = (Studentas);
	~Studentas();

	/// Get metodas gauti studento vardui
	/// @returns Grazina studento varda
	string Getvardas() const{ return vardas; }

	/// Get metodas gauti studento pavardei
	/// @returns Grazina studento pavarde
	string Getpavarde() const{ return pavarde; }

	/// Klases, kuriai priklauso objektas, indikatorine funkcija
	void kas_as() { cout << "Isvestines klases objektas" << vardas << endl; };

	/// Get metodas gauti studento egzamino pazymiui
	/// @returns Grazina studento egzamino pazymi
	inline double Getegz() const { return egz ; }

	double Getbalas();
	void readStudent(std::istream&);
	void keisk(Studentas& kopija);
};

/// Studentu lygimimo metodas.
/// @param v1,v2 - du lyginami studentai.
/// @returns true, jeigu didesnis pirmasis; false, jeigu didesnis antrasis.
bool compare(Studentas&, Studentas&);