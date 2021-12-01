#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Studentas_struct.h"
#include "Laikas.h"

using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::endl;

void trink_struct(std::vector <Studentas_struct>& stuv)
{
	laikas trinam;

	std::sort(stuv.begin(), stuv.end());
	auto lievi_it = std::find_if(stuv.begin(), stuv.end(), [](Studentas_struct v) {return v.galutinis == 5;});
	std::vector <Studentas_struct> lievi(lievi_it, stuv.end());
	stuv.resize(stuv.size() - lievi.size());

	std::ofstream KIETI("Superiniai_struct.txt"), LIEVI("Nuviliantys_struct.txt");
	for (auto vienas : stuv)
	{
		KIETI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}

	for (auto vienas : lievi)
	{
		LIEVI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}
	lievi.clear();
	KIETI.close();
	LIEVI.close();
	std::cout << "STRUCT : Trinant studentai surusiuoti per " << trinam.elapsed() << " s." << endl;
}