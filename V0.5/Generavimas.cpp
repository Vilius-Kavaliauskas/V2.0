#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

void generuok(int kiek_paz, int stud_kiek)
{
	using namespace std;

	ofstream OUT("kursiokai_laikinas_test.txt");
	random_device rd;
	mt19937_64 mt(rd());
	uniform_int_distribution<int> dist(0, 10);

	double studentu_kiekis = pow(10, stud_kiek);

	OUT << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
	for (int j = 1; j <= kiek_paz; j++) { OUT << "ND" + to_string(j) << ' '; }
	OUT << "Egz." << endl;

	for (int i = 1; i <= studentu_kiekis; i++)
	{
		string kelintas = to_string(i);

		OUT << setw(20) << left << "Vardas" + kelintas << setw(20) << left << "Pavarde" + kelintas;
		for (int j = 0; j < kiek_paz; j++) { OUT << setw(3) << dist(mt) << ' '; }
		OUT << dist(mt) << endl;
	}
	OUT.close();
}