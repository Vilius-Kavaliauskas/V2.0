#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#include "Studentas.h"
#include "Studentas_list.h"
#include "Input.h"
#include "Output.h"
#include "Generavimas.h"
#include "Laikas.h"
#include "Balas_list.h"
#include "Input_list.h"
#include "Output_list.h"

using namespace std;

int main()
{
    string rasymas;

    cout << "Duomenys faile (spausti F) ar rasysite juos pats (spausti R)? "; cin >> rasymas;
    cout << endl;

    vector <studentas> grupe;
    list <studentas_list> grupe_list;

    //----------------VEKTORIUS-----------------
    /*
    input(grupe, rasymas);
    output(grupe);
    grupe.clear();
    */

    //---------------LISTAS---------------------

    input_list(grupe_list, rasymas);
    output_list(grupe_list);
    grupe_list.clear();

}
