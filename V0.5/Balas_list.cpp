#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "Studentas_list.h"

void balas_list(std::string tipas, std::list <studentas_list>& stud)
{
    int kiek = stud.size();
    auto stud_front = stud.begin();

    for (int i = 0; i < kiek; i++)
    {
        studentas_list laikinas = *stud_front;

        if (tipas == "V")
        {
            laikinas.galutinis = 0.4 * (std::accumulate(laikinas.nd.begin(), laikinas.nd.end(), 0.0) / laikinas.nd.size()) + 0.6 * laikinas.egz;
        }

        else if (tipas == "M")
        {
            laikinas.nd.sort();

            auto nd_front = laikinas.nd.begin();
            int vid = laikinas.nd.size();

            if (vid % 2 != 0)
            {
                advance(nd_front, vid / 2);
                laikinas.galutinis = *nd_front * 0.4 + laikinas.egz * 0.6;
            }
            else
            {
                advance(nd_front, vid / 2 - 1);
                double mediana1 = *nd_front;
                advance(nd_front, 1);
                double mediana2 = *nd_front;
                laikinas.galutinis = (mediana2 + mediana1) / 2 * 0.4 + 0.6 * laikinas.egz;
            }
        }

        *stud_front = laikinas;
        advance(stud_front, 1);
    }

}