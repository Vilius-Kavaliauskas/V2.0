#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

#include "Studentas.h"

void output(std::vector <studentas> stu)
{
    using namespace std;
    
    cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << "Galutinis" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < stu.size(); i++)
    {
        cout << setw(20) << left << stu[i].pavarde << setw(20) << left << stu[i].vardas << fixed << setprecision(2) << stu[i].galutinis << endl;
    }
}
