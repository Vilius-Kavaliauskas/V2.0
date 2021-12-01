#include "Studentas_struct.h"
#include "Laikas.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>


void input_struct(std::vector <Studentas_struct>& stu, int kiek_stud)
{
    laikas skaito_vec;
    std::string failas = "kursiokai_laikinas_" + std::to_string(kiek_stud) + ".txt";
    stu.reserve(pow(10, kiek_stud));
    std::ifstream IN(failas);
    std::string pirm;
    getline(IN, pirm);
    int kiek = 0;
    for (int i = 0; i < pow(10, kiek_stud); i++)
    {
        Studentas_struct laikinas;
        IN >> laikinas.vardas >> laikinas.pavarde;
        laikinas.nd.reserve(8);
        for (int i = 0; i < 8; i++)
        {
            double sk;
            IN >> sk;
            laikinas.nd.push_back(sk);
        }
        IN >> laikinas.egz;
        laikinas.balas();
        stu.push_back(laikinas);
    }
    IN.close();
    std::cout << std::endl << "STRUCT : Failas nuskaitytas per " << skaito_vec.elapsed() << " s." << std::endl;
}