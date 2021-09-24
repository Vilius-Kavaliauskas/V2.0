#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

struct studentas
{
    std::string vardas;
    std::string pavarde;
    vector <double> nd;
    int egz;
    double galutinis;
};

void input(vector <studentas>& stu, string &ras);
void output(vector <studentas>& stu);
void balas(string tipas, vector <studentas>& stud);
void rikiavimas(vector <double>& mas);
void rikiavimas_str(vector <studentas>& gru);

int main()
{
    int st;
    string rasymas;
    cout << "Duomenys faile (spausti F) ar rasysite juos pats (spausti R)? "; cin >> rasymas;
    vector <studentas> grupe;
    input(grupe, rasymas);
    output(grupe);
}

void input(vector <studentas>& stu, string &ras)
{
    using std::cout;
    using std::cin;
    if (ras == "R")
    {
        studentas laikinas;
        std::cout << "Studentu skaicius : ";
        int st;
        std::cin >> st;
        if (cin.fail()) { throw std::invalid_argument("Programa neturi prasmes!"); }
        stu.reserve(st);
        for (int j = 0; j < st; j++)
        {
            cout << "Studento vardas : "; cin >> laikinas.vardas;
            cout << "Studento pavarde : "; cin >> laikinas.pavarde;
            for (const char r : laikinas.vardas) { if (cin.fail()) { throw std::invalid_argument("Varde negali buti skaiciaus! "); } }
            for (const char r : laikinas.pavarde) { if (cin.fail()) { throw std::invalid_argument("Pavardeje negali buti skaiciaus!"); } }
            string darbas;
            cout << "Studento ivertinimai zinomi (spausti Z) ar generuoti juos atsitiktinai (spausti A)? "; cin >> darbas;
            if (darbas == "Z")
            {
                cout << "Namu darbu ivertinimai: " << endl;
                double tarp;
                while (cin >> tarp)
                {
                    if (cin.fail()) { throw std::invalid_argument("Ivesta negalima reiksme!"); }
                    laikinas.nd.push_back(tarp);
                }
                cin.clear();
                cin.ignore(10000, '\n');
                if (cin.fail()) { throw "Privalo buti bent vienas pazymys!"; }
                cout << "Egzamino ivertinimas : "; cin >> laikinas.egz; cout << endl;
                if (cin.fail()) { throw std::invalid_argument("Ivesta negalima reiksme!"); }
                stu.push_back(laikinas);
                laikinas.nd.clear();
            }

            else if (darbas == "A")
            {
                random_device rd;
                mt19937_64 mt(rd());
                uniform_int_distribution<int> dist(0, 10);
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

    else if(ras == "F")
    {
        ifstream IN, INN;
        IN.open("kursiokai.txt", ios::in);
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

        INN.open("kursiokai.txt", ios::in);
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

    string noras;
    cout << "Noretumete gauti medianinius (spausti M) ar vidurkinius (spausti V) ivertinimus? "; cin >> noras;
    balas(noras, stu);
}

void output(vector <studentas>& stu)
{
    using namespace std;
    rikiavimas_str(stu);
    cout <<setw(20) << left << "Pavarde" <<setw(20) << left << "Vardas" << "Galutinis" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < stu.size(); i++)
    {
        cout <<setw(20) << left << stu[i].pavarde << setw(20) << left<< stu[i].vardas << fixed << setprecision(2) << stu[i].galutinis << endl;
    }
}

void balas(std::string tipas, vector <studentas>& stud)
{
    int kiek = stud.size();
    for (int i = 0; i < kiek; i++)
    {
        studentas laikinas = stud[i];
        if (tipas == "V")
        {
            laikinas.galutinis = 0.4 * (std::accumulate(laikinas.nd.begin(), laikinas.nd.end(), 0.0) / laikinas.nd.size()) + 0.6 * laikinas.egz;
        }
        else if (tipas == "M")
        {
            rikiavimas(laikinas.nd);
            int vid = laikinas.nd.size();
            if (vid % 2 != 0) { laikinas.galutinis = laikinas.nd[vid / 2] * 0.4 + laikinas.egz * 0.6; }
            else { laikinas.galutinis = (laikinas.nd[vid / 2] + laikinas.nd[vid / 2 - 1]) / 2 * 0.4 + 0.6 * laikinas.egz; }
        }
        else
        {
            throw std::invalid_argument("Nepasirinktas joks ivertinimo skaiciavimo variantas!");
        }
        stud[i] = laikinas;
    }

}

void rikiavimas(vector <double>& mas)
{
    for (int i = 0; i < mas.size() - 1; i++)
    {
        for (int y = i + 1; y < mas.size(); y++)
        {
            if (mas[i] > mas[y])
            {
                swap(mas[i], mas[y]);
            }
        }
    }
}

void rikiavimas_str(vector <studentas>& gru)
{
    for (int i = 0; i < gru.size()-1; i++)
    {
        for (int j = i + 1; j < gru.size(); j++)
        {
            if (gru[i].pavarde.compare(gru[j].pavarde)==1)
            {
                swap(gru[i], gru[j]);
            }
        }
    }
}