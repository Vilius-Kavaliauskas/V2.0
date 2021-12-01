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
#include "Trynimas_struct.h"
#include "Studentas_class.h"
#include "Studentas_struct.h"
#include "Input_struct.h"
#include "Input_class.h"

using namespace std;

int main()
{
    int kiekis = 6;
    cout << pow(10, kiekis) << endl;
    vector <Studentas> stu;
    stu.reserve(pow(10, kiekis));
    input_class(stu, kiekis);
    trink_class(stu);
    stu.clear();

    vector <Studentas_struct> stus;
    stus.reserve(pow(10, kiekis));
    input_struct(stus, kiekis);
    trink_struct(stus);
    stus.clear();
}
