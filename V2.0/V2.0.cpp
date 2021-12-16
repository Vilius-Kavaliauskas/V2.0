#include <string>
#include <iomanip>
#include <iostream>
#include <numeric>
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
#include <gtest/gtest.h>

#include "Laikas.h"
#include "Trynimas_class.h"
#include "Studentas_class.h"
#include "Asmuo.h"
#include "Input_class.h"

using namespace std;
using namespace testing;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    int kiekis = 5;
    cout << std::fixed << std::setprecision(0) << pow(10, kiekis) << endl;
    vector <Studentas> stu;
    stu.reserve(pow(10, kiekis));
    input_class(stu, kiekis);
    trink_class(stu);
    stu.clear();
}
/*
int test_main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
/*
TEST(StudentuProblemos, ArGerasBalas)
{
    string var = "Bet", pav = "Kas";
    Studentas laikinas(var, pav, { 8, 9, 6, 3, 8, 7, 9, 8, 7 }, 10);
    double suma = 0;
    for (int i = 0; i < laikinas.Getnd().size(); i++) {suma += laikinas.Getnd()[i];}
    double vid = (suma / laikinas.Getnd().size()) * 0.4 + laikinas.Getegz() * 0.6;
    EXPECT_EQ(vid, laikinas.Getbalas());
}
*/
