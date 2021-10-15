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


using std::vector;
using std::string;
using std::endl;

void input(std::vector <studentas>& stu, std::string ras)
{
    using std::cout;
    using std::cin;
    if (ras == "R")
    {
        studentas laikinas;
        std::cout << "Studentu skaicius : ";
        int st;
        std::cin >> st;

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

        balas(noras, stu);
    }
}