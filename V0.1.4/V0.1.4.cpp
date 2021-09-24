#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct studentas
{
    std::string vardas;
    std::string pavarde;
    vector <double> nd;
    int egz;
    double galutinis;
};

void input(vector <studentas>& stu, int& kiek);
void output(vector <studentas>& stu);
void balas(string tipas, vector <studentas>& stud);
void rikiavimas(vector <double>& mas);

int main()
{
    int st;
    std::cout << "Studentu skaicius : ";
    std::cin >> st;
    if (st <= 0) { throw std::invalid_argument("Programa neturi prasmes!"); }
    vector <studentas> grupe;
    grupe.reserve(st);
    input(grupe, st);
    output(grupe);
}

void input(vector <studentas>& stu, int& kiek)
{
    using namespace std;
    studentas laikinas;
    for (int j = 0; j < kiek; j++)
    {
        cout << "Studento vardas : "; cin >> laikinas.vardas;
        cout << "Studento pavarde : "; cin >> laikinas.pavarde;
        for (const char r : laikinas.vardas) { if (isdigit(r)) { throw std::invalid_argument("Varde negali buti skaiciaus! "); } }
        for (const char r : laikinas.pavarde) { if (isdigit(r)) { throw std::invalid_argument("Pavardeje negali buti skaiciaus!"); } }
        string darbas;
        cout << "Studento ivertinimai zinomi (spausti Z) ar generuoti juos atsitiktinai (spausti A)? "; cin >> darbas;
        if (darbas == "Z")
        {
            cout << "Namu darbu ivertinimai: " << endl;
            double tarp;
            while (cin >> tarp)
            {
                if (tarp > 10 || tarp < 0) { throw std::invalid_argument("Ivesta negalima reiksme!"); }
                laikinas.nd.push_back(tarp);
            }
            cin.clear();
            cin.ignore(10000, '\n');
            if (laikinas.nd.size() == 0) { throw "Privalo buti bent vienas pazymys!"; }
            cout << "Egzamino ivertinimas : "; cin >> laikinas.egz; cout << endl;
            if (laikinas.egz > 10 || laikinas.egz < 0) { throw std::invalid_argument("Ivesta negalima reiksme!"); }
            stu.push_back(laikinas);
            laikinas.nd.clear();
        }

        else if (darbas == "A")
        {
            int ndd;
            cout << "Namu darbu kiekis: "; cin >> ndd;
            if (ndd <= 0) { throw std::invalid_argument("Privalo buti bent vienas pazymys!"); }
            srand(time(0));
            for (int i = 0; i < ndd; i++)
            {
                int pazz = rand() % 10 + 1;
                cout << pazz << ' ';
                laikinas.nd.push_back(pazz);
            }
            cout << endl;
            cout << "Egzamino ivertinimas : ";
            srand(time(0));
            int egzz = rand() % 10 + 1;
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

    string noras;
    cout << "Noretumete gauti medianinius (spausti M) ar vidurkinius (spausti V) ivertinimus? "; cin >> noras;
    balas(noras, stu);
}

void output(vector <studentas>& stu)
{
    using namespace std;
    cout << setw(20) << left << "Pavarde" << "\t" << setw(10) << "Vardas" << "\t" << "Galutinis" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < stu.size(); i++)
    {
        cout << setw(20) << left << stu[i].pavarde << "\t" << setw(10) << stu[i].vardas << "\t" << fixed << setprecision(2) << stu[i].galutinis << endl;
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
            cout << endl;
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
                double keit = mas[i];
                mas[i] = mas[y];
                mas[y] = keit;
            }
        }
    }
}
