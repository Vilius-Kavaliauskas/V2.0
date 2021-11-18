#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <list>
#include <iterator>

#include "Studentas.h"
#include "Laikas.h"

void output_list(std::list <studentas>& stu, std::vector <studentas>& stuv, double &laikas_list, double &laikas_vec)
{
    using namespace std;
    ofstream GERI_VEC("Superiniai_vec_old.txt"), BLOGI_VEC("Nuviliantys_vec_old.txt");
    ofstream GERI_LIST("Superiniai_list_old.txt"), BLOGI_LIST("Nuviliantys_list_old.txt");
    GERI_VEC << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    BLOGI_VEC << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    GERI_VEC << "---------------------------------------------------------------------------" << endl;
    BLOGI_VEC << "---------------------------------------------------------------------------" << endl;
    GERI_LIST << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    BLOGI_LIST << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    GERI_LIST << "---------------------------------------------------------------------------" << endl;
    BLOGI_LIST << "---------------------------------------------------------------------------" << endl;

    laikas skirstom;
    for (auto vienas : stuv)
    {
        if (vienas.galutinis > 5) { GERI_VEC << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl; }
        else if (vienas.galutinis <= 5) { BLOGI_VEC << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl; }
    }
    laikas_vec += skirstom.elapsed();
    cout << "VECTOR: Studentai surusiuoti ir isspausdinti per: " << skirstom.elapsed() << "s." << endl;

    skirstom.reset();
    for (auto vienas : stu)
    {
        if (vienas.galutinis > 5) { GERI_LIST << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl; }
        else if (vienas.galutinis <= 5) { BLOGI_LIST << setw(20) << left << vienas.pavarde << setw(20) << left << vienas.vardas << fixed << setprecision(2) << vienas.galutinis << endl; }
    }

    laikas_list += skirstom.elapsed();
    cout << "LIST: Studentai surusiuoti ir isspausdinti per: " << skirstom.elapsed() << "s." << endl<< endl;
    ///cout << "VECTOR: Programa uztruko " << laikas_vec << " s." << endl;
    ///cout << "LIST: Programa uztruko " << laikas_list << " s." << endl;
    GERI_VEC.close();
    BLOGI_LIST.close();
    GERI_LIST.close();
    BLOGI_VEC.close();
}