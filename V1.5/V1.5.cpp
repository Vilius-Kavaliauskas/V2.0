#include <string>
#include <iomanip>
#include <iostream>
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

#include "Laikas.h"
#include "Trynimas_class.h"
#include "Studentas_class.h"
#include "Asmuo.h"
#include "Input_class.h"

using namespace std;

int main()
{
    int kiekis = 5;
    cout << std::fixed << std::setprecision(0) << pow(10, kiekis) << endl;
    vector <Studentas> stu;
    stu.reserve(pow(10, kiekis));
    input_class(stu, kiekis);
    trink_class(stu);
    stu.clear();
}