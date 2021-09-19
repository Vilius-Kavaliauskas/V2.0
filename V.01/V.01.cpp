#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct studentas
{
    std::string vardas;
    std::string pavarde;
    int n;
    int nd[100];
    int egz;
    double nd_suma;
    double galutinis;
};

void input(studentas stud[], int& kiek);
void output(studentas stud[], int& kiek);

int main()
{
    int st;
    std::cout << "Studentu skaicius : ";
    std::cin >> st;
    studentas stu[100];
    input(stu, st);
    output(stu, st);
}

void input(studentas stud[], int& kiek)
{
    using namespace std;
    for (int j = 0; j < kiek; j++)
    {
        double nd_egz[100];
        stud[j].nd_suma = 0;
        cout << "Studento vardas : "; cin >> stud[j].vardas;
        cout << "Studento pavarde : "; cin >> stud[j].pavarde;
        cout << "Namu darbu kiekis: "; cin >> stud[j].n;
        cout << "Namu darbu ivertinimai: " << endl;
        for (int i = 0; i < stud[j].n; i++)
        {
            int tarp;
            cin >> tarp;
            stud[j].nd[i] = tarp;
            stud[j].nd_suma += stud[j].nd[i];
        }
        cout << "Egzamino ivertinimas : "; cin >> stud[j].egz; cout << endl;
        stud[j].galutinis = 0.4 * (stud[j].nd_suma / stud[j].n) + 0.6 * stud[j].egz;
    }
}

void output(studentas stud[], int& kiek)
{
    using namespace std;
    cout << setw(20) << left << "Pavarde" << "\t" << setw(10) << "Vardas" << "\t" << "Galutinis" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < kiek; i++)
    {
        cout << setw(20) << left << stud[i].pavarde << "\t" << setw(10) << stud[i].vardas << "\t" << fixed << setprecision(2) << stud[i].galutinis << endl;
    }
}