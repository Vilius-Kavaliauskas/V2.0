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
#include "Generavimas.h"
#include "Laikas.h"
#include "Balas_list.h"
#include "Input_list.h"
#include "Output_list.h"

using namespace std;

int main()
{
    vector <studentas> grupe;
    list <studentas> grupe_list;

    input_list(grupe_list, grupe);
    output_list(grupe_list, grupe);
    grupe_list.clear();
    grupe.clear();
}
