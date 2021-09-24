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

void input(vector <studentas> &stu, int& kiek);
void output(vector <studentas> &stu);
void balas(string tipas, vector <studentas> &stud);
void rikiavimas(vector <double> &mas);

int main()
{
    int st;
    std::cout << "Studentu skaicius : ";
    std::cin >> st;
    vector <studentas> grupe;
    grupe.reserve(st);
    input(grupe, st);
    output(grupe);
}

void input(vector <studentas> &stu, int& kiek)
{
    using namespace std;
    studentas laikinas;
    for (int j = 0; j < kiek; j++)
    {
        cout << "Studento vardas : "; cin >> laikinas.vardas;
        cout << "Studento pavarde : "; cin >> laikinas.pavarde;
        cout << "Namu darbu ivertinimai: " << endl;
        double tarp;
        while (cin >> tarp)
        {
            laikinas.nd.push_back(tarp);
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << laikinas.nd.size() << endl;
        cout << "Egzamino ivertinimas : "; cin >> laikinas.egz; cout << endl;
        stu.push_back(laikinas);
        laikinas.nd.clear();
    }

    string noras;
    cout << "Noretumete gauti medianinius (spausti M) ar vidurkinius (spausti V) ivertinimus? "; cin >> noras;
    balas(noras, stu);
}

void output(vector <studentas> &stu)
{
    using namespace std;
    cout << setw(20) << left << "Pavarde" << "\t" << setw(10) << "Vardas" << "\t" << "Galutinis" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i=0; i< stu.size(); i++)
    {
        cout << setw(20) << left << stu[i].pavarde << "\t" << setw(10) << stu[i].vardas << "\t" << fixed << setprecision(2) << stu[i].galutinis << endl;
    }
}

void balas(std::string tipas, vector <studentas> &stud)
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
        stud[i] = laikinas;
    }
    
}

void rikiavimas(vector <double> &mas)
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