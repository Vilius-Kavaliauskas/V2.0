#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

#include "Studentas.h"
#include "Laikas.h"

void output(std::vector <studentas> stu)
{
    using namespace std;
    ofstream GERI("Superiniai.txt"), BLOGI("Nuviliantys.txt");
    GERI << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    BLOGI << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    GERI << "---------------------------------------------------------------------------" << endl;
    BLOGI << "---------------------------------------------------------------------------" << endl;
    laikas skirstom;
    for (int i = 0; i < stu.size(); i++)
    {
        if (stu[i].galutinis > 5) { GERI << setw(20) << left << stu[i].pavarde << setw(20) << left << stu[i].vardas << fixed << setprecision(2) << stu[i].galutinis << endl; }
        else if (stu[i].galutinis <= 5) { BLOGI << setw(20) << left << stu[i].pavarde << setw(20) << left << stu[i].vardas << fixed << setprecision(2) << stu[i].galutinis << endl; }
    }
    cout << endl << "Studentai surusiuoti ir isspausdinti per: " << skirstom.elapsed() << "s." << endl;
    GERI.close();
    BLOGI.close();
}