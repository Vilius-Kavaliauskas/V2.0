#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>

using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::endl;

#include "Studentas.h"
#include "Laikas.h"

void kopijuok(std::list <studentas>& stu, std::vector <studentas>& stuv)
{
	///==========================VECTOR=====================================
	laikas kopijuojam;
	std::vector <studentas> kieti, prasti;
	kieti.reserve(stuv.size());
	prasti.reserve(stuv.size());

	std::copy_if(stuv.begin(), stuv.end(), back_inserter(prasti), [](studentas v) {return v.galutinis < 5;});
	std::copy_if(stuv.begin(), stuv.end(), back_inserter(kieti), [](studentas v) {return v.galutinis >= 5;});

	std::ofstream KIETI("Superiniai_vec_copy.txt"), LIEVI("Nuviliantys_vec_copy.txt");
	for (auto vienas : kieti)
	{
		KIETI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}

	for (auto vienas : prasti)
	{
		LIEVI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}
	prasti.clear();
	kieti.clear();
	KIETI.close();
	LIEVI.close();
	std::cout << "VECTOR: Kopijuojant studentai surusiuoti per " << kopijuojam.elapsed() << " s." << endl;

	
	///=======================LIST==========================================
	kopijuojam.reset();
	std::list <studentas> kiet, prast;
	std::copy_if( stu.begin(), stu.end(), back_inserter(prast), [](studentas s) {return s.galutinis < 5;} );
	std::copy_if( stu.begin(), stu.end(), back_inserter(kiet), [](studentas s) {return s.galutinis >= 5;} );
	std::ofstream KIET("Superiniai_list_copy.txt"), LIE("Nuviliantys_list_copy.txt");
	for (auto vienas : kiet)
	{
		KIET << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}

	for (auto vienas : prast)
	{
		LIE << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}
	prast.clear();
	kiet.clear();
	KIET.close();
	LIE.close();
	std::cout << "LIST: Kopijuojant studentai surusiuoti per " << kopijuojam.elapsed() << " s." << endl;
}