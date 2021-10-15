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
#include "Balas.h"
#include "Output.h"

using namespace std;

int main()
{
    string rasymas;

    try
    {
    cout << "Duomenys faile (spausti F) ar rasysite juos pats (spausti R)? "; cin >> rasymas;
        if (rasymas != "F" && rasymas != "R")
        {
            throw (rasymas);
        }
    }catch (string rasymas)
    {
        cout << "Nesuprastas nurodymas" << endl;
    }
    
    vector <studentas> grupe;
    input(grupe, rasymas);
    output(grupe);
}