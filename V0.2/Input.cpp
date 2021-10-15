#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>

#include "Studentas.h"
#include "Balas.h"
#include "C:\Users\kavav\Documents\OBJEKTINIS PROGRAMAVIMAS C++\v0.4\v0.4\Generavimas.h"
#include "C:\Users\kavav\Documents\OBJEKTINIS PROGRAMAVIMAS C++\v0.4\v0.4\Laikas.h"

using std::vector;
using std::string;
using std::endl;

void input(std::vector <studentas>& stu, std::string ras)
{
    using std::cout;
    using std::cin;
    laikas kuriam();

    if (ras == "R")
    {
        studentas laikinas;
        std::cout << "Studentu skaicius : ";
        int st;
        cin >> st;
            
        stu.reserve(st);
        for (int j = 0; j < st; j++)
        {
            cout << "Studento vardas : "; cin >> laikinas.vardas;
            cout << "Studento pavarde : "; cin >> laikinas.pavarde;

            string darbas;
            cout << "Studento ivertinimai zinomi (spausti Z) ar generuoti juos atsitiktinai (spausti A)? ";

            try {
                cin >> darbas;
                if (darbas != "Z" && darbas != "A")
                {
                    throw (darbas);
                }
            }
            catch (string darbas)
            {
                cout << "Nurodymas nesuprastas" << endl;
            }

            if (darbas == "Z")
            {
                cout << "Namu darbu ivertinimai: " << endl;
                double tarp;
                while (cin >> tarp)
                {
                    laikinas.nd.push_back(tarp);
                }

                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Egzamino ivertinimas : ";
                try {
                    cin >> laikinas.egz;
                    if (isalpha(laikinas.egz) || laikinas.egz > 10 || laikinas.egz < 0)
                    {
                        throw (laikinas.egz);
                    }
                }
                catch (int egz)
                {
                    cout << "Ivesta negalima reiksme" << endl;
                }
                cout << endl;

                stu.push_back(laikinas);
                laikinas.nd.clear();
            }

            else if (darbas == "A")
            {
                std::random_device rd;
                std::mt19937_64 mt(rd());
                std::uniform_int_distribution<int> dist(0, 10);
                int ndd;
                cout << "Namu darbu kiekis: "; cin >> ndd;
                if (cin.fail()) { throw std::invalid_argument("Privalo buti bent vienas pazymys!"); }
                for (int i = 0; i < ndd; i++)
                {
                    int pazz = dist(mt);
                    cout << pazz << ' ';
                    laikinas.nd.push_back(pazz);
                }
                cout << endl;
                cout << "Egzamino ivertinimas : ";
                int egzz = dist(mt);
                cout << egzz << endl << endl;
                laikinas.egz = egzz;
                stu.push_back(laikinas);
                laikinas.nd.clear();
            }
            else
            {
                throw std::invalid_argument("Nepasirinktas joks pazymiu generavimo budas!");
            }
        }
    }



    
    else if (ras == "F")
    {
        string failas;
        cout << "Ar failas turimas(spausti T), ar naudotis generuotais(spausti G)? ";
        try {
            cin >> failas;
            if (failas != "T" && failas != "G")
            {
                throw (failas);
            }
        }
        catch (string failas)
        {
            cout << "Negaliojantis pasirinkimas" << endl;
        }

        if (failas == "T")
        {
            std::ifstream IN, INN;

            try {
                IN.open("kursiokai.txt", std::ios::in);
                if (!IN)
                {
                    throw (ras);
                }
            }
            catch (string ras)
            {
                cout << "Failas nerastas arba neegzistuoja" << endl;
            }

            studentas laikinas;
            int kiek_eil = 0;
            string pirm, eil;
            getline(IN, pirm);
            int p = 0, kiek_ = 0;
            while (p < pirm.length())
            {
                if (pirm[p] == ' ' && pirm[p + 1] != ' ') { kiek_++; }
                p++;
            }
            kiek_ -= 2;
            while (getline(IN, eil)) { kiek_eil++; }
            IN.close();

            INN.open("kursiokai.txt", std::ios::in);
            stu.reserve(kiek_eil);
            getline(INN, pirm);
            double sk;
            for (int i = 1;i <= kiek_eil; i++)
            {
                INN >> laikinas.vardas >> laikinas.pavarde;
                laikinas.nd.reserve(kiek_);
                for (int j = 0; j < kiek_; j++)
                {
                    INN >> sk;
                    laikinas.nd.push_back(sk);
                }
                INN >> laikinas.egz;
                stu.push_back(laikinas);
                laikinas.nd.clear();
            }
            INN.close();
        }


        else if (failas == "G")
        {
            int nd_kiek, stud_kiek;
            cout << endl << "Kokio didumo imties norite? Galimi variantai: " << endl << "1000 (spausti 3), 10000 (spausti 4), 100000 (spausti 5), 1000000 (spausti 6), 10000000 (spausti 7)? ";
            cin >> stud_kiek;
            cout << endl <<"Kiek namu darbu buvo uzduota? ";
            cin >> nd_kiek;

            laikas kuriam;
            generuok(nd_kiek, stud_kiek);
            cout << endl << pow(10, stud_kiek) << " studentu turintis failas sugeneruotas per: " << kuriam.elapsed() << "s." << endl << endl;
            
            std::ifstream IN;
            IN.open("Kursiokai_laikinas.txt");
            studentas laikinas;
            string pirm;

            kuriam.reset();
            getline(IN, pirm);
            for (int i = 0; i < pow(10, stud_kiek); i++)
            {
                IN >> laikinas.vardas >> laikinas.pavarde;
                laikinas.nd.reserve(nd_kiek);
                int sk;
                for (int j = 0; j < nd_kiek; j++)
                {
                    IN >> sk;
                    laikinas.nd.push_back(sk);
                }
                IN >> laikinas.egz;
                stu.push_back(laikinas);
                laikinas.nd.clear();
            }
            IN.close();
            cout << "Failas nuskaitytas per: " << kuriam.elapsed() << "s." << endl << endl;
        }


        string noras;
        cout << endl << "Noretumete gauti medianinius (spausti M) ar vidurkinius (spausti V) ivertinimus? ";
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

        laikas skaiciuojam;
        balas(noras, stu);
        cout << endl << "Studentu galutiniai pazymiai apskaiciuoti per: " << skaiciuojam.elapsed() << "s." << endl << endl;
    }
}