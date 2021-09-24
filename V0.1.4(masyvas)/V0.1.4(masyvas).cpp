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
    double* nd;
    double nd_suma;
    int egz;
    double galutinis;
};

void input(studentas stu[], int& kiek);
void output(studentas stu[]);
void balas(string tipas, studentas stud[]);
void rikiavimas(double mas[]);

int main()
{
    int st;
    std::cout << "Studentu skaicius : ";
    std::cin >> st;
    studentas* grupe = new (std::nothrow) studentas[10];
    input(grupe, st);
    output(grupe);
}

void input(studentas stu[], int& kiek)
{
    using namespace std;
    studentas laikinas;
    for (int j = 0; j < kiek; j++)
    {
        cout << "Studento vardas : "; cin >> laikinas.vardas;
        cout << "Studento pavarde : "; cin >> laikinas.pavarde;
        laikinas.nd_suma = 0;
        string darbas;
        cout << "Studento ivertinimai zinomi (spausti Z) ar generuoti juos atsitiktinai (spausti A)? "; cin >> darbas;
        if (darbas == "Z")
        {
            cout << "Namu darbu ivertinimai: " << endl;
            laikinas.nd = new (std::nothrow) double[100];
            double tarp;
            int i = 0;
            while (cin >> tarp)
            {
                laikinas.nd[i] = tarp;
                laikinas.nd_suma += tarp;
                i++;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Egzamino ivertinimas : "; cin >> laikinas.egz; cout << endl;
            stu[j] = laikinas;
        }

        else if (darbas == "A")
        {
            int ndd;
            cout << "Namu darbu kiekis: "; cin >> ndd;
            laikinas.nd = new double[ndd];
            srand(time(0));
            for (int i = 0; i < ndd; i++)
            {
                int pazz = rand() % 10 + 1;
                cout << pazz << ' ';
                laikinas.nd[i] = pazz;
            }
            cout << endl;
            cout << "Egzamino ivertinimas : ";
            srand(time(0));
            int egzz = rand() % 10 + 1;
            cout << egzz << endl << endl;
            laikinas.egz = egzz;
            stu[j] = laikinas;
        }

    }

    string noras;
    cout << "Noretumete gauti medianinius (spausti M) ar vidurkinius (spausti V) ivertinimus? "; cin >> noras;
    balas(noras, stu);
}

void output(studentas stu[])
{
    using namespace std;
    cout << setw(20) << left << "Pavarde" << "\t" << setw(10) << "Vardas" << "\t" << "Galutinis" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < sizeof(stu); i++)
    {
        cout << setw(20) << left << stu[i].pavarde << "\t" << setw(10) << stu[i].vardas << "\t" << fixed << setprecision(2) << stu[i].galutinis << endl;
    }
}

void balas(std::string tipas, studentas stud[])
{
    int kiek = sizeof(stud);
    for (int i = 0; i < kiek; i++)
    {
        studentas laikinas = stud[i];
        if (tipas == "V")
        {
            laikinas.galutinis = 0.4 * (laikinas.nd_suma / sizeof(laikinas.nd)) + 0.6 * laikinas.egz;
        }
        else if (tipas == "M")
        {
            rikiavimas(laikinas.nd);
            cout << endl;
            int vid = sizeof(laikinas.nd);
            if (vid % 2 != 0) { laikinas.galutinis = laikinas.nd[vid / 2] * 0.4 + laikinas.egz * 0.6; }
            else { laikinas.galutinis = (laikinas.nd[vid / 2] + laikinas.nd[vid / 2 - 1]) / 2 * 0.4 + 0.6 * laikinas.egz; }
        }
        stud[i] = laikinas;
    }

}

void rikiavimas(double mas[])
{
    int kiek = sizeof(mas);
    for (int i = 0; i < kiek - 1; i++)
    {
        for (int y = i + 1; y < kiek; y++)
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