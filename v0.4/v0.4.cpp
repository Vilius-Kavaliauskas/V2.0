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
#include "Studentas.h"
#include "Input.h"
#include "Output.h"
#include "Generavimas.h"
#include "Laikas.h"

using namespace std;

int main()
{
    string rasymas;

    cout << "Duomenys faile (spausti F) ar rasysite juos pats (spausti R)? "; cin >> rasymas;
    cout << endl;

    vector <studentas> grupe;

    input(grupe, rasymas);
    output(grupe);
    grupe.clear();
}