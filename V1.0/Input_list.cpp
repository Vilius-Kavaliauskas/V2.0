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

void input_list(std::list <studentas>& stu, std::vector <studentas>& stuv, double &laikas_list, double &laikas_vec)
{
    using std::cout;
    using std::cin;
    int kiek_stud, kiek_nd;
    cout << "Kokio didumo imties norite? Galimi variantai: " << endl;
    cout << "1000 (spauti 3), 10000 (spausti 4), 100000 (spausti 5), 1000000 (spausti 6), 10000000 (spausti 7) "; cin >> kiek_stud;
    cout << "Kiek namu darbu buvo uzduota? "; cin >> kiek_nd;

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

    stuv.reserve(pow(10, kiek_stud));

    laikas skaito_vec;
    string failas = "kursiokai_laikinas_" + std::to_string(kiek_stud) + ".txt";
    std::ifstream IN(failas);
    string pirm;
    getline(IN, pirm);
    int kiek = 0;

    for(int i = 0; i < pow(10, kiek_stud); i++)
    {
        studentas laik;
        IN >> laik.vardas >> laik.pavarde;
        double sk;
        laik.nd.reserve(kiek_nd);
        for (int j = 0; j < kiek_nd; j++)
        {
            IN >> sk;
            laik.nd.push_back(sk);
        }

        IN >> laik.egz;
        stuv.push_back(laik);
        laik.nd.clear();
    }
 
    IN.close();
    
    laikas_vec = skaito_vec.elapsed();
    cout << endl << "VECTOR: Failas nuskaitytas per " << laikas_vec << " s." << endl;


    laikas skaito_list;
    std::ifstream INN(failas);
    getline(INN, pirm);

    for(int i =0; i< pow(10, kiek_stud); i++)
    {
        studentas laikinas;
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

    laikas_list = skaito_list.elapsed();
    cout << "LIST: Failas nuskaitytas per " << laikas_list << " s." << endl << endl;

    balas_list(noras, stu);
    balas(noras, stuv);
}