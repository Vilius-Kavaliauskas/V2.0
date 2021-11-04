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

#include "Studentas_list.h"
#include "Balas.h"
#include "Generavimas.h"
#include "Laikas.h"
#include "Balas_list.h"

using std::string;
using std::endl;

void input_list(std::list <studentas_list>& stu, std::string ras)
{
    using std::cout;
    using std::cin;
    if (ras == "R")
    {
        studentas_list laikinas;
        std::cout << "Studentu skaicius : ";
        int st;
        std::cin >> st;

        //stu.reserve(st);
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
        cout << "Failas turimas (spausti T) ar generuoti atsitiktinai (spausti G) ? "; cin >> failas;

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

            studentas_list laikinas;
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
            //stu.reserve(kiek_eil);
            getline(INN, pirm);
            double sk;
            for (int i = 1;i <= kiek_eil; i++)
            {
                INN >> laikinas.vardas >> laikinas.pavarde;
                //laikinas.nd.reserve(kiek_);
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
            int kiek_stud, kiek_nd;
            studentas_list laikinas;
            cout << endl << "Kokio didumo imties norite? Galimi variantai: " << endl;
            cout << "1000 (spauti 3), 10000 (spausti 4), 100000 (spausti 5), 1000000 (spausti 6), 10000000 (spausti 7) "; cin >> kiek_stud;
            cout << endl << "Kiek namu darbu buvo uzduota? "; cin >> kiek_nd;
            //stu.reserve(kiek_stud);
            laikas kuriam;
            generuok(kiek_nd, kiek_stud);
            //cout << endl << pow(10, kiek_stud) << " studentu turintis failas sukurtas per " << kuriam.elapsed() << " s." << endl;

            kuriam.reset();
            std::ifstream IN("kursiokai_laikinas.txt");

            string pirm;
            getline(IN, pirm);


            for (int i = pow(10, kiek_stud); i > 0; i--)
            {
                IN >> laikinas.vardas >> laikinas.pavarde;
                double sk;
                //laikinas.nd.reserve(kiek_nd);
                for (int j = 0; j < kiek_nd; j++)
                {
                    IN >> sk;
                    laikinas.nd.push_back(sk);
                }

                IN >> laikinas.egz;
                stu.push_back(laikinas);
                laikinas.nd.clear();
            }
            IN.close();
            cout << endl << "Failas nuskaitytas per " << kuriam.elapsed() << " s." << endl << endl;
        }

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

        laikas skaiciuojam;
        balas_list(noras, stu);
        //cout << endl << "Galutiniai balai suskaiciuoti per " << skaiciuojam.elapsed() << " s." << endl;
    }
}