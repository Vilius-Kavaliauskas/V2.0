#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Studentas_class.h"
#include "Laikas.h"

using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::endl;

/// Studentu rušiavimo i geruosius ir bloguosius funkcija.
///
/// Pirmiausiai studentai isrusiuojami pagal 'Studentas' klaseje nurodyta palyginimo metoda.
/// Randami studentai, kuriu galutinis pazymys yra 5.
/// Studentai perskiriami ties riba, kur galutinis balas mazesnis nei 5.
/// Rezultatai isspausdinami i du atskirus failus.
void trink_class(std::vector <Studentas>& stuv)
{
	laikas trinam;
	
	std::sort(stuv.begin(), stuv.end(), compare);
	auto lievi_it = std::find_if(stuv.begin(), stuv.end(), [](Studentas v) {return v.Getbalas() == 5;});
	std::vector <Studentas> lievi(lievi_it, stuv.end());
	stuv.resize(stuv.size() - lievi.size());

	std::ofstream KIETI("Superiniai_class.txt"), LIEVI("Nuviliantys_class.txt");
	for (auto vienas : stuv)
	{
		KIETI << setw(20) << left << vienas.Getpavarde() << setw(20) << left << vienas.Getvardas() << fixed << setprecision(2) << vienas.Getbalas() << endl;
	}

	for (auto vienas : lievi)
	{
		LIEVI << setw(20) << left << vienas.Getpavarde() << setw(20) << left << vienas.Getvardas() << fixed << setprecision(2) << vienas.Getbalas() << endl;
	}
	lievi.clear();
	KIETI.close();
	LIEVI.close();
	std::cout << fixed << setprecision(3) << "CLASS : Trinant studentai surusiuoti per " << trinam.elapsed() << " s." << endl;
}
