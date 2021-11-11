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

#include "Balas.h"
#include "Generavimas.h"
#include "Laikas.h"
#include "Balas_list.h"

using std::string;
using std::endl;

void input_list(std::list <studentas>& stu, std::vector <studentas>& stuv)
{
    using std::cout;
    using std::cin;
    int kiek_stud, kiek_nd;
    studentas laikinas;
    cout << "Kokio didumo imties norite? Galimi variantai: " << endl;
    cout << "1000 (spauti 3), 10000 (spausti 4), 100000 (spausti 5), 1000000 (spausti 6), 10000000 (spausti 7) "; cin >> kiek_stud;
    cout << endl << "Kiek namu darbu buvo uzduota? "; cin >> kiek_nd;

    string noras;
    cout << "Noretumete gauti medianinius (spausti M) ar vidurkinius (spausti V) ivertinimus? ";
    try {
        cin >> noras;
        if (noras != "M" && noras != "V")
        {
            throw (noras);
        }
    }
    catch (string noras)
    {
        cout << "Nurodymas nesuprastas" << endl;
    }


    stuv.reserve(kiek_stud);
    generuok(kiek_nd, kiek_stud);
    laikas kuriam;
    std::ifstream IN("kursiokai_laikinas_test.txt");
    string pirm;
    getline(IN, pirm);
    
    for (int i = pow(10, kiek_stud); i > 0; i--)
    {
        IN >> laikinas.vardas >> laikinas.pavarde;
        double sk;
        laikinas.nd.reserve(kiek_nd);
        for (int j = 0; j < kiek_nd; j++)
        {
            IN >> sk;
            laikinas.nd.push_back(sk);
        }

        IN >> laikinas.egz;
        stuv.push_back(laikinas);
        laikinas.nd.clear();
    }
    IN.close();
    cout << endl << "VECTOR: Failas naudojant nuskaitytas per " << kuriam.elapsed() << " s." << endl << endl;


    kuriam.elapsed();
    std::ifstream INN("kursiokai_laikinas_test.txt");
    getline(INN, pirm);

    for (int i = pow(10, kiek_stud); i > 0; i--)
    {
        INN >> laikinas.vardas >> laikinas.pavarde;
        double sk;
        laikinas.nd.reserve(kiek_nd);
        for (int j = 0; j < kiek_nd; j++)
        {
            INN >> sk;
            laikinas.nd.push_back(sk);
        }

        INN >> laikinas.egz;
        stu.push_back(laikinas);
        laikinas.nd.clear();
    }
    INN.close();

    cout << endl << "LIST: Failas nuskaitytas per " << kuriam.elapsed() << " s." << endl << endl;

    balas_list(noras, stu);
    balas(noras, stuv);
}