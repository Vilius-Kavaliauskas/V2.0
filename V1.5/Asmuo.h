#pragma once
#include <string>

using std::string;

/// Bazine klase Asmuo.
///
/// Talpina apsaugotus kintamuosius, saugiancius zmogaus varda ir pavarde.
/// Visi realizuoti metodai ir funkcijos yra virtualus, priejimo is isores prie ju nera.
class Asmuo
{
protected:
	string vardas, pavarde;
public:
	/// Konstruktorius.
	Asmuo(string var = "", string pav = "") : vardas{ var }, pavarde{ pav } {};

	/// Get metodas gauti zmogaus vardui.
	/// @returns Grazina zmogaus varda.
	virtual string Getvardas() const = 0;

	/// Get metodas gauti zmogaus pavardei.
	/// @returns Grazina zmogaus varda.
	virtual string Getpavarde() const = 0;

	/// Klases, kuriai priklauso objektas, indikatorine funkcija.
	virtual void kas_as() = 0;
};
