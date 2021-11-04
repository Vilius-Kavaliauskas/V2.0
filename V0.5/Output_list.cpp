#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <list>
#include <iterator>

#include "Studentas_list.h"
#include "Laikas.h"

void output_list(std::list <studentas_list> stu)
{
    using namespace std;
    ofstream GERI("Superiniai.txt"), BLOGI("Nuviliantys.txt");
    GERI << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    BLOGI << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    GERI << "---------------------------------------------------------------------------" << endl;
    BLOGI << "---------------------------------------------------------------------------" << endl;

    laikas skirstom;
    for (auto vienas : stu)
    {
        if (vienas.galutinis > 5) { GERI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl; }
        else if (vienas.galutinis <= 5) { BLOGI << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl; }
    }
    cout << endl << "Studentai surusiuoti ir isspausdinti per: " << skirstom.elapsed() << "s." << endl;
    GERI.close();
    BLOGI.close();
}