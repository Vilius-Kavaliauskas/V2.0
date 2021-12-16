#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <gtest/gtest.h>

#include "Laikas.h"
#include "Studentas_class.h"

using std::string;
using std::endl;
using std::cout;

void input_class(vector <Studentas>& stu, int kiek_stud)
{
    laikas skaito_vec;
    stu.reserve(pow(10, kiek_stud));
    string failas = "kursiokai_laikinas_" + std::to_string(kiek_stud) + ".txt";
    std::ifstream IN(failas);
    string pirm;
    getline(IN, pirm);
    for(int i = 0; i < pow(10, kiek_stud); i++)
    {
        Studentas laikinas;
        laikinas.readStudent(IN);
        stu.push_back(laikinas);
        laikinas.~Studentas();
    }
    IN.close();
    cout << "CLASS : Failas nuskaitytas per " << skaito_vec.elapsed() << " s." << endl;
}