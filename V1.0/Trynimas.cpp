#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::endl;

#include "Studentas.h"
#include "Laikas.h"

void trink(std::list <studentas>& stu, std::vector <studentas>& stuv)
{
	///===========================VECTOR===================================
	laikas trinam;
	std::vector <studentas> kieti;
	kieti.reserve(stuv.size());
	std::remove_copy_if(stuv.begin(), stuv.end(), back_inserter(kieti), [](studentas v) {return v.galutinis < 5;});
	//stuv.resize(stuv.size() - kieti.size());
	std::remove_if(stuv.begin(), stuv.end(), [](studentas v) {return v.galutinis >= 5;});
	stuv.resize(stuv.size() - kieti.size());

	std::ofstream KIETI("Superiniai_vec_remove.txt"), LIEVI("Nuviliantys_vec_remove.txt");
	for (auto vienas : stuv)
	{
		LIEVI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}

	for (auto vienas : kieti)
	{
		KIETI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}
	kieti.clear();
	KIETI.close();
	LIEVI.close();
	std::cout << endl << "VECTOR: Trinant studentai surusiuoti per " << trinam.elapsed() << " s." << endl;



	///=================================LIST========================================
	trinam.reset();
	std::list <studentas> kie;
	std::remove_copy_if(stu.begin(), stu.end(), back_inserter(kie), [](studentas v) {return v.galutinis < 5;});
	std::remove_if(stu.begin(), stu.end(), [](studentas v) {return v.galutinis >= 5;});
	stu.resize(stu.size() - kie.size());

	std::ofstream KIE("Superiniai_list_remove.txt"), LIE("Nuviliantys_list_remove.txt");
	for (auto vienas : stu)
	{
		LIE << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}

	for (auto vienas : kie)
	{
		KIE << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl;
	}
	kie.clear();
	KIE.close();
	LIE.close();

	std::cout << "LIST: Trinant studentai surusiuoti per " << trinam.elapsed() << " s." << endl;

}